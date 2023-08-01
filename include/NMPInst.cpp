

#include <include/NMPInst.h>

using namespace NVM;

NMPInst::NMPInst( )
{
    OpCode operation = NOP;
    ncycle_t cycle = 0;
    uint64_t vsize = 0;
    bool localityBit = false;
}

NMPInst::~NMPInst( )
{
}

void NMPInst::setNMPInst( NVMAddress& addr, OpCode op, ncycle_t cycle, uint64_t vsize, uint64_t pt)
{
    this->address = addr;
    this->operation = op;
    this->cycle = cycle;
    this->vsize = vsize;
    this->psumTag = pt;
}