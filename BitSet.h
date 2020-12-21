#include <iostream>
#include "Bvector.h"

class BitSet : public Bvector{
    public:
        BitSet(int sz = 32);
        void insert(int v);
        friend BitSet operator+(const BitSet& b1, const BitSet& b2);
        friend std::ostream& operator<<(std::ostream& os, const BitSet& b);
};