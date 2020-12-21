#include <iostream>
#include "Kvector.h"

class Bvector : public Kvector{
    protected:
        unsigned int *u_m;
        const int NBITS;
    public:
        Bvector(int nbits = 32);
        Bvector(const Bvector& e);
        bool bit(int pos) const; //pos번째 bit의 값을 0(false) or 1(true)로 반환
        void set(int pos); //pos번째 bit의 값을 1로 씀(다른 bit는 변화 x)
        void reset(int pos); //pos번째 bit의 값을 0으로 씀(다른 bit는 변화 x)
        int size() const {return NBITS;} //len이 아니라 NBITS를 반환
        void clear() {for (int i = 0; i < len; i++) m[i] = 0;} //all bits are false
        void print() const;
        bool operator[](int idx) const {return bit(idx);} //not reference 객체 반환
        Bvector& operator=(const Bvector& v); 
        friend std::ostream& operator<<(std::ostream& os, const Bvector& v);
};