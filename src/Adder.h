#ifndef __ADDER_H__
#define __ADDER_H__

#include "src/NVMObject.h"
#include "src/Config.h"

namespace NVM 
{

class Config;

enum AdderState 
{
    ADDER_UNKNOW,
    ADDER_IDLE,
    ADDER_BUSY
};

class Adder : public NVMObject
{
    public:
        Adder( );
        ~Adder( );

        void SetConfig( Config *c, bool createChildren = true );

        bool IsIssuable( NVMainRequest *req, FailReason *reason = NULL );
        bool IssueCommand( NVMainRequest *req );
        //bool RequestComplete( NVMainRequest *req );
        //ncycle_t NextIssuable( NVMainRequest *request );

        void RegisterStats( );
        void CalculateStats( );

        void Cycle( ncycle_t );
        bool IsCalculate( );

    private:
        Config *conf;

        AdderState state;

        ncycle_t lastCalculate;
        ncycle_t nextCalculate;

        ncycle_t calculateWaits;
        ncycle_t calculateWaitsTotal;

        double adderEnergy;

};

}; // namespace NVM

#endif