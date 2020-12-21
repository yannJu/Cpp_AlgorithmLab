#include <iostream>
#include "BitSet.h"
using namespace std;

int main(int argc, char *argv[]){
    BitSet b1(131), b2(131);
    b1.insert(3); b1.insert(5); b1.insert(8);
    b2.insert(4); b2.insert(5); b2.insert(8); b2.insert(130);
    b1.print(); b2.print();
    cout << "b1 = " << b1 << endl;
    cout << "b2 = " << b2 << endl;
    cout << "b1 + b2 = " << b1+b2 << endl;
}

BitSet::BitSet(int sz) : Bvector(sz){}
void BitSet::insert(int v){
    set(v);
}
BitSet operator+(const BitSet& b1, const BitSet& b2){
    BitSet tmp(b1.NBITS);
    for (int i = 0; i < b1.NBITS; i++){
        if (b1.bit(i) || b2.bit(i)) tmp.set(i); 
    }
    return tmp;
}
ostream& operator<<(ostream& os, const BitSet& b){
   os << "{ ";
   for (int i = 0; i < b.NBITS; i++) {
        if (b.bit(i)) os << i << " ";
    }
    os << "}" << endl;
    return os;
}