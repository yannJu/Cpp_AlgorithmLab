#include <iostream>
#include "Kvector_temp.h"
using namespace std;

template <class T>
Kvector<T>::Kvector(int sz, T value) : len(sz), val(value) { //default 
	cout << this << " : Kvector(" << sz << "," << value << ")\n";
	if (len > 0) {
		m = new T[len];
		for (int i = 0; i < len; i++) m[i] = val;
	}
	else m = NULL;
}

template <class T>
Kvector<T>::Kvector(const Kvector<T>& v){ //copy
	cout << this << " : Kvector(* " << &v << ")\n";
	len = v.len;
	if (!len) {m = NULL; return;}
	m = new T[len];
	for (int i = 0; i < len; i++) m[i] = v.m[i];
}

template <class T>
Kvector<T>::~Kvector(){
	cout << this << " : ~Kvector() \n";
	delete[] m;
}

template <class T>
T& Kvector<T>::operator[] (int key){//([])operator overloading, member function
	return m[key];
}

template <class T>
Kvector<T>& Kvector<T>::operator= (const Kvector<T>& a){ //(=) operator
	cout << "Kvector::operator= " << &a << endl;
	delete[] m;
	len = a.size(); val = a.val;	
	if (len) {
		m = new T[len];
		for (int i = 0; i < len; i++){
			m[i] = val;	
		}
	}
	return *this;
}

template <class T>
bool Kvector<T>::operator== (const Kvector<T>& a){ //(==)
	if (len != a.len) return false;
	for (int i = 0; i < a.len; i++){
		if (m[i] != a.m[i]) return false;
	}
	return true;
}

template <class T>
bool Kvector<T>::operator!= (const Kvector<T>& a){ //(!=)
	return !(*(this)==a);
}

