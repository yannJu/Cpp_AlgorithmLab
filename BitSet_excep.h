#include <iostream>
#include <exception>
#include "Bvector.h"
class IncompatibleException : public std::exception{
	public:
		int v1, v2;
		IncompatibleException(int v1, int v2) : v1(v1), v2(v2){}
};

class BitSet : public Bvector{
    public:
        BitSet(int sz = 32);
        void insert(int v);
        friend BitSet operator+(const BitSet& b1, const BitSet& b2);
        friend std::ostream& operator<<(std::ostream& os, const BitSet& b);
};
