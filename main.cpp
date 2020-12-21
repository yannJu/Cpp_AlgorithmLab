#include <iostream>
#include "Avector.h"
#include "Bvector.h"
using namespace std;

int main(int rgc, char *argv[]){
    Avector a1(7, 4, "stu"); //m -> 4444444 table-> stu
    Avector a2(a1);

    cout << "a1 == a2 : " << (a1==a2) << endl;

    a1[0] = 0; //m->0444444
    a2[1] = 5; //m->4544444
    a2.setTable("ijk"); //table-> ijk
    a1.print();
    a2.print();

    cout << "a1.size() : " << a1.size() << endl;
    cout << "a2.size() : " << a2.size() << endl;
    cout << "a1 : " << a1 << endl;
    cout << "a2 : " << a2 << endl;

    a1.clear();
    a1.print();

    cout << "a1.size() : " << a1.size() << endl;
    cout << "a1 : " << a1 << endl;

    a1 = a2; //m->4544444 table->ijk
    a1.print(); 
    
    cout << "a1.size()" << a1.size() << endl;
    cout << "a1 : " << a1 << endl;

	Bvector b1(61), b2(131);
	b1.set(3); b1.set(5); b1.set(8);
	b2.set(4); b2.set(5); b2.set(8); b2.set(130);
	b1.print(); b2.print();
	cout << "b1.size() : " << b1.size() << endl;
	cout << "b2.size() : " << b2.size() << endl;
	cout << "b1 : " << b1 << endl;
	cout << "b2 : " << b2 << endl;
	b1.clear();
	b1.print();
	cout << "b1.size() : " << b1.size() << endl;
	cout << "b1 : " << b1 << endl;
	cout << "b2[5] " << b2[5] << endl;
	b1 = b2;
	b1.print();
	cout << "b1.size() : " << b1.size() << endl;
	cout << "b1 : " << b1 << endl;

	Avector *ap = new Avector(5, 2, "xyz");
	Bvector *bp = new Bvector(50);
	Kvector *karray[2] = {ap, bp};

	ap->print(); //포인터 자체가 Avector의 포인트고 재정의 해서 virtual이 소용이 없음
	cout << *ap << endl;
	cout << "ap->size() : " << ap->size() << endl;
	bp->print();
	cout << *bp << endl;
	cout << "bp->size() : " << bp->size() << endl;

	for (int i = 0; i < 2; i++){
		cout << i << endl;
		karray[i]->print(); //virtual
		cout << *(karray[i]) << endl;
		cout << "size() : " << karray[i]->size() << endl;
	}
}
