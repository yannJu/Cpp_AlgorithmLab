#ifndef _MYTERM_H_
#define _MYTERM_H_
#include <iostream>
using namespace std;
class myTerm{
private:
   int coeff; // integer coefficient
   unsigned exp; // exponent (non-negative integer)
public:
   // constructor
   myTerm(int c = 0, unsigned e = 0);
   // copy constructor
   myTerm(const myTerm &term);
   // accessor functions
   int getCoeff() const{
      return coeff;
   }
   unsigned getExp() const{
      return exp;
   }
   // mutator functions
   void setCoeff(int c){
      coeff = c;
   }
   void setExp(unsigned e){
      exp = e;
   }
   // overloaded operators
   bool operator =(const myTerm& term);
   bool operator ==(const myTerm& term) const;
   bool operator !=(const myTerm& term) const;
   bool operator <(const myTerm& term) const;
   myTerm operator *(const myTerm& term) const;
   myTerm operator -() const;
   // member functions
   myTerm ddx() const; // derivative of a term
   // friend functions and classes
   friend ostream& operator <<(ostream &outStream, const myTerm& term);
   friend class myPolynomial;
};
#endif
