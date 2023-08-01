
#ifndef __NMPInst_H__
#define __NMPInst_H__

#include <src/Params.h>
#include "include/NVMAddress.h"

namespace NVM
{

enum OpCode 
{
    NOP = 0,
    SUM = 1,
};

class NMPInst
{
    public:
    NVMAddress address;
    OpCode operation;
    ncycle_t cycle;
    uint64_t vsize;
    uint64_t psumTag;
    bool localityBit;

    NMPInst( );
    ~NMPInst( );

    void setNMPInst( NVMAddress& addr, OpCode op, ncycle_t cycle, 
                    uint64_t vsize, uint64_t pt );
};

}; // namespace NVM

#endif