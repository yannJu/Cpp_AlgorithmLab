#include <iostream>
#ifndef __KVECTOR__
#define __KVECTOR__

class Kvector{
	protected:
		int *m;
		int len, val;
	public:
		Kvector(int sz = 0, int value = 0);
		Kvector(const Kvector& v);
		virtual ~Kvector();
		virtual void print() const {std::cout << "Kvector\n";}
		void clear() {
			delete[] m;
			m = NULL;
			len = 0;
		}
		int size() const {return len;}
		Kvector& operator= (const Kvector& v); //(=)operator overloading, member function
		int& operator[] (int);//([])operator overloading, member function
		const int& operator[] (int idx) const {return m[idx];}
		friend std::ostream& operator<< (std::ostream& os, const Kvector& a); //cout operator overloading, non-member function
		friend bool operator== (const Kvector& a, const Kvector& b); //(==)operator overloading, non-member function
		friend bool operator!= (const Kvector& a, const Kvector& b); //(==)operator overloading, non-member function
};

#endif // !__KVECTOR__