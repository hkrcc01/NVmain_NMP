
#include "src/Adder.h"
#include "src/Bank.h"
#include "src/Params.h"
#include "src/MemoryController.h"
#include "src/EventQueue.h"

using namespace NVM;

Adder::Adder(/* args */)
{
    conf = NULL;

    state = ADDER_IDLE;

    lastCalculate = 0;
    nextCalculate = 0;

    adderEnergy = 0.0f;
}

Adder::~Adder()
{
}

void Adder::SetConfig( Config *c, bool createChildren )
{
    conf = c;

    if ( !createChildren ) return;

    Params *params = new Params( );
    params->SetParams( c );
    SetParams( params );

}

bool Adder::IssueCommand( NVMainRequest *request )
{
    if (state == ADDER_BUSY) {
        std::cerr << "NVMain Error: try calculate on a adder that is not idle!"
            << std::endl;
        return false;
    }

    nextCalculate = MAX( nextCalculate, 
                        GetEventQueue()->GetCurrentCycle() 
                            + MAX( p->tBURST, p->tCCD ) * request->burstCount + p->tADDER );

    //跟新一些功耗和周期的参数
    adderEnergy += p->Eadder;

    return true;
}

bool Adder::IsIssuable( NVMainRequest *req, FailReason *reason )
{
    bool rv = true;
    if (req->type != SUM) return false;



    if ( nextCalculate > GetEventQueue()->GetCurrentCycle() )
    {
        rv = false;
        calculateWaitsTotal++;
        reason->reason = ADDER_TIMING;
        calculateWaits += nextCalculate - GetEventQueue()->GetCurrentCycle();
    }
    return rv;
}

void Adder::RegisterStats( )
{

}

void Adder::CalculateStats( )
{

}

void Adder::Cycle( ncycle_t )
{
}

bool Adder::IsCalculate( )
{
    if (state == ADDER_BUSY) return true;
    else return false;  
}