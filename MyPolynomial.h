#ifndef _MYPOLYNOMIAL_H_
#define _MYPOLYNOMIAL_H_
#define MAX_SIZE 50
#include "MyTerm.h"
class myPolynomial{
private:
   int degree; // maximum expnent
   int numTerms;
   myTerm term[MAX_SIZE];
public:
   // constructor
   myPolynomial(int c=0, unsigned e=0);
   myPolynomial(int nTerms, int mono[]);
   // copy constructor
   myPolynomial(const myPolynomial &poly);
   // accessor functions
   int getDegree() const; // get a degree of the polynomial
   int getNumTerms() const; // number of terms in the polynomial
   // mutator functions
   void setDegree(int d);
   void setNumTerms(int n);
   // member functions
   void swap(myTerm &t1, myTerm &t2);
   void bubbleSort();
   void deleteZeroTerm();
   myPolynomial ddx() const; // derivative of a polynomial
   // overloaded operators
   bool operator ==(const myPolynomial &poly) const;
   bool operator !=(const myPolynomial &poly) const;
   myPolynomial& operator =(const myPolynomial &poly);
   myPolynomial operator +=(const myPolynomial &poly);
   myPolynomial& operator -=(const myPolynomial &poly);
   myPolynomial& operator *=(const myPolynomial &poly);
   myPolynomial& operator *=(int k);
   myPolynomial operator -() const; // unary Minus
   myPolynomial operator *(int k) const;
   myPolynomial operator +(const myTerm &t) const;
   myPolynomial operator +(const myPolynomial &poly) const;
   myPolynomial operator -(const myPolynomial &poly) const;
   myPolynomial operator *(const myPolynomial &poly) const;
   long operator ()(int x) const; // evaluate the polynomial
   // friend operators and functions
   friend myPolynomial operator *(int k, const myPolynomial &poly);
   friend ostream& operator <<(ostream &outStream, const myPolynomial &poly);
   static const myPolynomial ZERO; // P(x) = 0
   static const myPolynomial ONE; // P(x) = 1
   static const myPolynomial X; // P(x) = x
};
#endif
