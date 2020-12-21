#include <iostream>
using namespace std;

class Kvector{
	int *m;
	int len, val;
	public:
		Kvector(int sz, int value);
		Kvector(const Kvector& v);
		~Kvector(){
			cout << this << " : ~Kvector() \n";
			delete[] m;
		}
		void print() const{
			for (int i = 0; i < len; i++) cout << m[i] << " ";
			cout << endl;
		}
		void clear() {
			delete[] m;
			m = NULL;
			len = 0;
		}
		int size() const {return len;}

		Kvector& operator= (const Kvector& a); //(=)operator overloading, member function
		int& operator[] (int);//([])operator overloading, member function
		const int& operator[] (int idx) const {return m[idx];}
		friend ostream& operator<< (ostream& os, const Kvector& a); //cout operator overloading, non-member function
		friend bool operator== (const Kvector& a, const Kvector& b); //(==)operator overloading, non-member function
		friend bool operator!= (const Kvector& a, const Kvector& b); //(==)operator overloading, non-member function
};

int& Kvector::operator[] (int key){ //([])operator
	return m[key];
}

Kvector& Kvector::operator= (const Kvector&  a){ //(=) operator
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

Kvector::Kvector(int sz = 0, int value = 0) : len(sz), val(value) { //default 
	cout << this << " : Kvector(int, int) \n";
	if (len > 0) {
		m = new int[len];
		for (int i = 0; i < len; i++) m[i] = val;
	}
	else m = NULL;
}

Kvector::Kvector(const Kvector& v){ //copy
	cout << this << " : Kvector(Kvector&) \n";
	len = v.len;
	val = v.val;
	m = new int[len];
	for (int i = 0; i < len; i++) m[i] = val;
}

int main(){ //MAIN
	Kvector v1(3); v1.print();
	Kvector v2(2, 9); v2.print();
	Kvector v3(v2); v3.print();
	cout << (v1==v2) << endl;
	cout << (v3==v2) << endl;
	v3 = v2 = v1;
	cout << v1 << endl;
	cout << v2 << endl;
	cout << v3 << endl;
	cout << (v3 != v2) << endl;
	v1[2] = 2;
	v2[0] = v1[2];
	cout << "v1 : " << v1 << "v2 : " << v2 << "v3 : " << v3 << endl;
}
