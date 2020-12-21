#include "MyTerm.h"
// constructor
myTerm::myTerm(int c, unsigned e):coeff(c),exp(e){}
// copy constructor
myTerm::myTerm(const myTerm &term):coeff(term.coeff),exp(term.exp){}
// overloaded operators
bool myTerm::operator =(const myTerm& term){
   setCoeff(term.getCoeff());
   setExp(term.getExp());
}
bool myTerm::operator ==(const myTerm& term) const{
   if(coeff==term.coeff && exp==term.exp)
      return true;
   else
      return false;
}
bool myTerm::operator !=(const myTerm& term) const{
   return !operator==(term);
}
bool myTerm::operator <(const myTerm& term) const{
   return exp < term.exp;
}
myTerm myTerm::operator -() const{
   return myTerm(-coeff,exp);
}
myTerm myTerm::operator *(const myTerm& term) const{
   return myTerm(getCoeff()*term.getCoeff(),getExp()+term.getExp());
}
// derivative of a term
myTerm myTerm::ddx() const{
   if(exp==0)
      return myTerm(0,0);
   return myTerm(exp*coeff,exp-1);
}
// output operator
ostream& operator <<(ostream &outStream, const myTerm& term){   
   if(term.coeff==0)
      return outStream;
   else if(term.exp==0)
      return outStream<<term.coeff;

   if(term.coeff==1)
      outStream<<"x";
   else if(term.coeff==-1)
      outStream<<"-x";
   else
      outStream<<term.coeff<<"x";

   if(term.exp==1)
      return outStream;
   else
      return outStream<<"^"<<term.exp;
}
