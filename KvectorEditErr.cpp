#include <iostream>
using namespace std;

class Kvector{
	int *m;
	int len, val;
	static int total_len;
	public:
		Kvector(int sz, int value);
		Kvector(const Kvector& v);
		~Kvector(){
			cout << this << " : ~Kvector() \n";
			delete[] m;
			total_len -= len;
		}
		void print() const{
			for (int i = 0; i < len; i++) cout << m[i] << " ";
			cout << endl;
		}
		void clear() const{
			delete[] m;
			//m = NULL;
			//len = 0;
		}
		int size() const {return len;}
		static int getTotal() {return total_len;}
};
int Kvector::total_len = 0;


Kvector::Kvector(int sz = 0, int value = 0) : len(sz), val(value) {
	cout << this << " : Kvector(int, int) \n";
	if (len > 0) {
		m = new int[len];
		total_len += len;
		for (int i = 0; i < len; i++) m[i] = val;
	}
	else m = NULL;
	
}

Kvector::Kvector(const Kvector& v){
	cout << this << " : Kvector(Kvector&) \n";
	len = v.len;
	m = new int[len];
	total_len += len;
	for (int i = 0; i < len; i++) m[i] = v.val;
}

int main(){
	Kvector v1(3); v1.print();
	const Kvector v2(2, 9); v2.print();
	Kvector v3(v2); v3.print();
	cout << "total length : " <<  Kvector::getTotal() << endl;
	
	v2.print();
	v3.print();
	cout << "total length : " <<  Kvector::getTotal() << endl;
	return 0;
}
