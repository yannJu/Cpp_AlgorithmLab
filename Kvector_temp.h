#include <iostream>
#ifndef __KVECTOR__
#define __KVECTOR__

template <class T>
class Kvector{
	protected:
		T *m;
		int len;
		T val;
	public:
		Kvector(int sz = 0, T value = NULL);
		Kvector(const Kvector& v);
		virtual ~Kvector();
		virtual void print() const {std::cout << "Kvector : "; for (int i =0; i < len; i++) std::cout << m[i] << " "; std::cout << std::endl;}
		void clear() {
			delete[] m;
			m = NULL;
			len = 0;
		}
		int size() const {return len;}
		T& operator[] (int);//([])operator overloading, member function
		const T& operator[] (int idx) const {return m[idx];}
		Kvector<T>& operator= (const Kvector<T>& v); //(=)operator overloading, member function
		T sum() const {
			T s;
			for (int i = 0; i < len; i++) s+=m[i];
			return s;
		}
		bool operator== (const Kvector<T>& a); //(==)operator overloading, non-member function
		bool operator!= (const Kvector<T>& a); //(==)operator overloading, non-member function
		T operator+= (const T& a){
			this += a;
			return *this;
		}
		friend std::ostream& operator<< (std::ostream& os, const Kvector<T>& a){
			for (int i = 0; i < a.len; i++) os << a.m[i] << " ";
			return os;
		}
};

#endif // !__KVECTOR__
