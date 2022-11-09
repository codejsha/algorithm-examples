#ifndef CPP_ALGORITHM_COMPUTING_PARITY_OF_WORD_H
#define CPP_ALGORITHM_COMPUTING_PARITY_OF_WORD_H

#include <array>

namespace ComputingParity
{
    short CountBits(unsigned int x);
    short Parity(unsigned long long x);
    short ParityDropLowestBits(unsigned long long x);
    short ParityMask(unsigned long long x);
    short ParityXor(unsigned long long x);
}

#endif
