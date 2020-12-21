#include <iostream>
using namespace std;
#define N 3

class Kvector{
	protected:
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

class Avector : public Kvector{
	char table[N];
	public:
		Avector (int sz = 0, int v = 0, const char *t = "abc");
		void setTable(const char *t);
	friend ostream& operator<<(ostream& os, const Avector& v);
};

ostream& operator<<(ostream& os, const Avector& v){
	for (int i = 0; i < v.len; i++){
		os << v.table[i] << " ";
	}
	return os;
}

Avector::Avector(int sz, int v, const char *t) : Kvector(sz, v){
	int idx;

	cout << this << " : Avector(" << sz << "," << v << "," << t << ")\n";
	for (int i = 0; i < N; i++){
		idx = m[i];
		table[i] = t[idx];
	}
}

void Avector::setTable(const char *t) {
	int idx;
	for (int i = 0; i < N; i++){
		idx = m[i] % N;
		table[i] = t[idx];
	}
}
int main(int argc, char *argv[]){ //MAIN
	if (argc != 2){
		cout << "usage : ./avector pqr\n";
		return 1;
	}
	Avector v1(3); v1.print();
	Avector v2(2, 1, "xyz"); v2.print();
	Avector v3(v2); v3.print();
	cout << "v1 == v2 " << (v1 == v2) << endl;
	cout << "v3 == v2 " << (v3 == v2) << endl;
	v3 = v2 = v1;
	cout << "v1 : " << v1 << endl; v1.print();
	cout << "v2 : " << v2 << endl; v2.print();
	cout << "v3 : " << v3 << endl; v3.print();
	cout << "v3 != v2" << (v3 != v2) << endl;
	v1[2] = 2;
	v2[0] = v1[2];
	v1.setTable(argv[1]);
	cout << "v1 : " << v1 << "v2 : " << v2 << "v3 : " << v3 << endl;
	v1.print();
	v2.print();
	v3.print();
}

//********* class KVector func***********
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
	m = new int[len];
	for (int i = 0; i < len; i++) m[i] = val;
}
