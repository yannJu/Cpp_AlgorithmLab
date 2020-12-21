#include <iostream>
#include "BitSet_excep.h"
using namespace std;

int main(int argc, char *argv[]){
	try{
		BitSet b1(132), b2(131);
		b1.insert(3); b1.insert(5); b1.insert(8);
		b2.insert(4); b2.insert(5); b2.insert(8); b2.insert(130);
		b1.print(); b2.print();
		cout << "b1 = " << b1 << endl;
		cout << "b2 = " << b2 << endl;
		cout << "b1 + b2 = ";
		cout << (b1+b2) << endl;
	}
	catch(IncompatibleException& e){
        cout << "In + operation, the operands are not compatible.\n";
        cout << "The size of the first BitSet is " << e.v1 << endl;
        cout << "The size of the second BitSet is " << e.v2 << endl;
	}
}

BitSet::BitSet(int sz) : Bvector(sz){}
void BitSet::insert(int v){
    set(v);
}
BitSet operator+(const BitSet& b1, const BitSet& b2){
    try{
        if (b1.NBITS != b2.NBITS) throw IncompatibleException(b1.NBITS, b2.NBITS);
        else{
            BitSet tmp(b1.NBITS);
            for (int i = 0; i < b1.NBITS; i++){
                if (b1.bit(i) || b2.bit(i)) tmp.set(i); 
            }
            return tmp;
        }
    }
    catch (IncompatibleException& e){
		throw;
    }
}
ostream& operator<<(ostream& os, const BitSet& b){
   os << "{ ";
   for (int i = 0; i < b.NBITS; i++) {
        if (b.bit(i)) os << i << " ";
    }
    os << "}" << endl;
    return os;
}
