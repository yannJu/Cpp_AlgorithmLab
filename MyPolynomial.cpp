#include "MyPolynomial.h"
// constructor
myPolynomial::myPolynomial(int c, unsigned e){
   numTerms=0;
   term[numTerms].setCoeff(c);
   term[numTerms++].setExp(e);
   degree=e;
}
myPolynomial::myPolynomial(int nTerms, int mono[]){
   numTerms=nTerms;
   for(int i=numTerms-1,j=0; i>=0; i--,j+=2){
      term[i].setCoeff(mono[j]);
      term[i].setExp(mono[j+1]);
   }
   bubbleSort();
   degree=term[0].exp;
}
// copy constructor
myPolynomial::myPolynomial(const myPolynomial &poly):degree(poly.degree),numTerms(poly.numTerms){
   for(int i=0; i<poly.numTerms; i++)
      term[i]=poly.term[i];
}
// accessor functions
int myPolynomial::getDegree() const{
   return degree;
}
int myPolynomial::getNumTerms() const{
   return numTerms;
}
// mutator functions
void myPolynomial::setDegree(int d){
   degree=d;
}
void myPolynomial::setNumTerms(int n){
   numTerms=n;
}
// member functions
myPolynomial myPolynomial::ddx() const{
   myPolynomial poly(*this);
   for(int i=0; i<numTerms; i++)
      poly.term[i]=term[i].ddx();
   poly.deleteZeroTerm();
   return poly;
}
// overloaded operators
bool myPolynomial::operator ==(const myPolynomial &poly) const{
   if(degree!=poly.degree || numTerms!=poly.numTerms)
      return false;
   for(int i=0; i<numTerms; i++){
      if(term[i]!=poly.term[i])
         return false;
   }
   return true;
}
bool myPolynomial::operator !=(const myPolynomial &poly) const{
   return !operator==(poly);
}
myPolynomial& myPolynomial::operator =(const myPolynomial &poly){
   degree=poly.degree;
   numTerms=poly.numTerms;
   for(int i=0; i<numTerms; i++)
      term[i]=poly.term[i];
   return (*this);
}
myPolynomial myPolynomial::operator +=(const myPolynomial &poly){
   return (*this)+poly;
}
myPolynomial& myPolynomial::operator -=(const myPolynomial &poly){
   (*this)=myPolynomial((*this)-poly);
   return (*this);
}
myPolynomial& myPolynomial::operator *=(const myPolynomial &poly){
   (*this)=myPolynomial((*this)*poly);
   return (*this);
}
myPolynomial& myPolynomial::operator *=(int k){
   for(int i=0; i<numTerms; i++)
      term[i].setCoeff(term[i].getCoeff()*k);
   return (*this);
}
myPolynomial myPolynomial::operator -() const{ // unary Minus
   myPolynomial newTerms(*this);
   for(int i=0; i<newTerms.numTerms; i++)
      newTerms.term[i].setCoeff(-term[i].getCoeff());
   return newTerms;
}
myPolynomial myPolynomial::operator *(int k) const{
   myPolynomial newTerms(*this);
   for(int i=0; i<newTerms.numTerms; i++)
      newTerms.term[i].setCoeff(k*term[i].getCoeff());
   newTerms.deleteZeroTerm();
   return newTerms;
}
myPolynomial myPolynomial::operator +(const myTerm &t) const{
   for(int i=0; i<numTerms; i++){
      if(term[i].getExp()==t.getExp()){
         myPolynomial newTerms(*this);
         newTerms.term[i].setCoeff(term[i].getCoeff()+t.getCoeff());
         return newTerms;
      }
   }
   myPolynomial newTerms;
   if(numTerms==1 && term[0].coeff==0)
      newTerms.setNumTerms(1);
   else
      newTerms.setNumTerms(numTerms+1);
   for(int i=0,j=0; i<newTerms.numTerms; i++){
      if(term[j].getExp() > t.getExp())
         newTerms.term[i]=term[j++];
      else
         newTerms.term[i]=t;
   }
   return newTerms;
}
myPolynomial myPolynomial::operator +(const myPolynomial &poly) const{
   myPolynomial newTerms;
   newTerms.setNumTerms(numTerms+poly.numTerms);
   int i=0, j=0, k=0;
   while(i<numTerms && j<poly.numTerms){
      if(term[i].getExp() > poly.term[j].getExp())
         newTerms.term[k++]=term[i++];
      else if(term[i].getExp() < poly.term[j].getExp())
         newTerms.term[k++]=poly.term[j++];
      else{
         newTerms.term[k].setExp(term[i].getExp());
         newTerms.term[k++].setCoeff(term[i++].getCoeff()+poly.term[j++].getCoeff());
      }
   }
   while(i<numTerms)
      newTerms.term[k++]=term[i++];
   while(j<poly.numTerms)
      newTerms.term[k++]=poly.term[j++];
   newTerms.deleteZeroTerm();
   return newTerms;
}
myPolynomial myPolynomial::operator -(const myPolynomial &poly) const{
   myPolynomial newTerms;
   newTerms.setNumTerms(numTerms+poly.numTerms);
   int i=0, j=0, k=0;
   while(i<numTerms && j<poly.numTerms){
      if(term[i].getExp() > poly.term[j].getExp())
         newTerms.term[k++]=term[i++];
      else if(term[i].getExp() < poly.term[j].getExp())
         newTerms.term[k++]=-poly.term[j++];
      else{
         newTerms.term[k].setExp(term[i].getExp());
         newTerms.term[k++].setCoeff(term[i++].getCoeff()-poly.term[j++].getCoeff());
      }
   }
   while(i<numTerms)
      newTerms.term[k++]=term[i++];
   while(j<poly.numTerms)
      newTerms.term[k++]=-poly.term[j++];
   newTerms.deleteZeroTerm();
   return newTerms;
}
myPolynomial myPolynomial::operator *(const myPolynomial &poly) const{
   myPolynomial newTerms;
   for(int j=0; j<numTerms; j++){
      for(int k=0; k<poly.numTerms; k++)
         newTerms=newTerms+term[j]*poly.term[k];
   }
   newTerms.deleteZeroTerm();
   return newTerms;
}
myPolynomial operator *(int k, const myPolynomial &poly){
   myPolynomial newTerms(poly);
   for(int i=0; i<newTerms.numTerms; i++)
      newTerms.term[i].setCoeff(k*poly.term[i].getCoeff());
   newTerms.deleteZeroTerm();
   return newTerms;
}
// output operator
ostream& operator <<(ostream &outStream, const myPolynomial& poly){
   bool checkZero=true;
   if (poly == myPolynomial::ZERO)
      return outStream << 0;
   for(int i=0; i<poly.numTerms; i++){
      outStream<<poly.term[i];
      if(i+1!=poly.numTerms && poly.term[i+1].getCoeff()>0)
            outStream<<'+';
      if(poly.term[i].getCoeff()!=0)
         checkZero=false;
   }
   if(checkZero)
      return outStream<<0;
   return outStream;
}
long myPolynomial::operator ()(int x) const{
   int result=0, temp;
   for(int i=0; i<numTerms; i++){
      temp=1;
      for(int j=0; j<term[i].exp; j++)
         temp*=x;
      result+=term[i].coeff*temp;
   }
   return result;
}
void myPolynomial::swap(myTerm &t1, myTerm &t2){
   myTerm temp=t1;
   t1=t2;
   t2=temp;
}
void myPolynomial::bubbleSort(){
   for(int i=0; i<numTerms-1; i++){
      for(int j=numTerms-1; j>i; j--){
         if(term[j-1]<term[j])
            swap(term[j-1],term[j]);
      }
   }
}
void myPolynomial::deleteZeroTerm(){
   int temp=numTerms;
   bubbleSort();
   for(int i=numTerms-1; i>0; i--){
      if(term[i].getCoeff()==0)
         temp--;
      else
         break;
   }
   numTerms=temp;
}
const myPolynomial myPolynomial::ZERO(0); // the zero polynomial P(x) = 0
const myPolynomial myPolynomial::ONE(1, (unsigned)0); // the monomial P(x) = 1
const myPolynomial myPolynomial::X(1, 1); // the monomial P(x) = x
