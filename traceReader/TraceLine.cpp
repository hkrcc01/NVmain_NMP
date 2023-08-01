/*******************************************************************************
* Copyright (c) 2012-2014, The Microsystems Design Labratory (MDL)
* Department of Computer Science and Engineering, The Pennsylvania State University
* All rights reserved.
* 
* This source code is part of NVMain - A cycle accurate timing, bit accurate
* energy simulator for both volatile (e.g., DRAM) and non-volatile memory
* (e.g., PCRAM). The source code is free and you can redistribute and/or
* modify it by providing that the following conditions are met:
* 
*  1) Redistributions of source code must retain the above copyright notice,
*     this list of conditions and the following disclaimer.
* 
*  2) Redistributions in binary form must reproduce the above copyright notice,
*     this list of conditions and the following disclaimer in the documentation
*     and/or other materials provided with the distribution.
* 
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
* ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
* WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
* DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
* FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
* DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
* SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
* CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
* OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
* OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
* 
* Author list: 
*   Matt Poremba    ( Email: mrp5060 at psu dot edu 
*                     Website: http://www.cse.psu.edu/~poremba/ )
*******************************************************************************/

#include "traceReader/TraceLine.h"

using namespace NVM;

TraceLine::TraceLine( )
{
    /*
     *  Set the address to some default bad value so it is not read by
     *  the memory simulator before it is set by the trace reader.
     */
    address.SetPhysicalAddress( 0xDEADC0DE0BADC0DEULL );
    operation = NOP;
    cycle = 0; 
    vsize = 0;
    localityBit = false;
}

TraceLine::~TraceLine( )
{
    /* There is no heap memory to free. Do nothing. */
}

/* Set the values of the address and memory operation. */
void TraceLine::SetLine( NVMAddress& addr, OpCode op, ncycle_t cycle, uint64_t vsize, uint64_t pt )
{
    this->address = addr;
    this->operation = op;
    this->cycle = cycle;
    this->vsize = vsize;
    this->psumTag = pt;
}

/* Get the address of the memory operation. */
NVMAddress& TraceLine::GetAddress( )
{
    return address;
}

/* Get the memory command of the operation. */
OpCode TraceLine::GetOperation( )
{
    return operation;
}

ncycle_t TraceLine::GetCycle( ) 
{
    return cycle;
}

uint64_t TraceLine::GetVsize( )
{
    return vsize;
}

uint64_t TraceLine::GetPsumTag( )
{
    return psumTag;    
}

bool TraceLine::GetLocalityBit( )
{
    return localityBit;
}
