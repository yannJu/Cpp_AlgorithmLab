#include <iostream>
#include "Kvector_temp.h"
#include "Kvector_temp.cpp"
using namespace std;

class Team{
	public:
		string name;
		int victory;
		Team(const string& n = "X", int v = 0) : name(n), victory(v) {}
		Team& operator += (const Team& rhs) {
			victory += rhs.victory;
			return *this;
		}
	friend Team operator+ (Team a, const Team& b){
		a += b;
		return a;
	}
	friend bool operator== (const Team& a, const Team& b){
		return (a.name == b.name);
	}
	friend bool operator!= (const Team& a, const Team& b){
		return !(a == b);
	}
	friend ostream& operator<< (ostream& os, const Team& n){
		os << n.name << "(" << n.victory << ")";
		return os;
	}
};

int main(){
	Kvector<int> v1(3, 0); v1.print();
	cout << "v1 : " << v1 << endl;
	cout << "v1.sum() = " << v1.sum() << endl;
	
	Kvector<int *> v4(5, NULL); v4.print();
	int arr[5] = {0, 1, 2, 3, 4};
	for (int i = 0; i < 5; i++) v4[i]  = &arr[4 - i];
	cout << "v4 : " << v4 << endl;
	for (int i = 0; i < 5; i++) cout << *(v4[i]) << " ";
	cout << endl << endl;

	Kvector<Team> league1(2, Team()), league2(2, Team());
	league1.print();
	league2.print();
	league1[0] = Team("Twins", 10); league1[1] = Team("Bears", 5);
	league2[0] = Team("Twins", 80); league2[1] = Team("Bears", 81);
	cout << "league1 : " << league1 << endl;
	cout << "league2 : " << league2 << endl;
	cout << "league1 == league2 : " << (league1 == league2) << endl;
	league2[0] = Team("Bulls", 80);
	league2[1] = Team("Warriors", 81);
	cout << "league1 : " << league1 << endl;
	cout << "league2 : " << league2 << endl;
	cout << "league1 != league2 : " << (league1 != league2) << endl;
	Kvector<Team> league3 = league2;
	league3[0].victory = 20;
	league3[1].name = "Spurs";
	cout << "league3 : " << league3 << endl;
	cout << "league1.sum() = " << league1.sum() << endl;
	cout << "league2.sum() = " << league2.sum() << endl;
	cout << "league3.sum() = " << league3.sum() << endl;
}
