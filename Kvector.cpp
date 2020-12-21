#include <iostream>
#include "Kvector.h"
using namespace std;

Kvector::Kvector(int sz, int value) : len(sz), val(value) { //default 
	cout << this << " : Kvector(" << sz << "," << value << ")\n";
	if (len > 0) {
		m = new int[len];
		for (int i = 0; i < len; i++) m[i] = val;
	}
	else m = NULL;
}

Kvector::Kvector(const Kvector& v){ //copy
	cout << this << " : Kvector(* " << &v << ")\n";
	len = v.len;
	val = v.val;
	if (!len) {m = NULL; return;}
	m = new int[len];
	for (int i = 0; i < len; i++) m[i] = val;
}

Kvector::~Kvector(){
	cout << this << " : ~Kvector() \n";
	delete[] m;
}int& Kvector::operator[] (int key){ //([])operator
	return m[key];
}

Kvector& Kvector::operator= (const Kvector& a){ //(=) operator
	cout << "Kvector::operator= " << &a << endl;
	delete[] m;
	len = a.size(); val = a.val;	
	if (len) {
		m = new int[len];
		for (int i = 0; i < len; i++){
			m[i] = val;	
		}
	}
	return *this;
}

ostream& operator<< (ostream& os, const Kvector& a){ //cout
	for (int i = 0; i < a.len; i++) os << a.m[i] << " ";
	return os;
}

bool operator== (const Kvector& a, const Kvector& b){ //(==)
	if (a.len != b.len) return false;
	for (int i = 0; i < a.len; i++){
		if (a.m[i] != b.m[i]) return false;
	}
	return true;
}

bool operator!= (const Kvector& a, const Kvector& b){ //(!=)
	return !(a==b);
}
