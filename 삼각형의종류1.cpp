#include <iostream>
using namespace std;

int CheckTriangle(int a, int b, int c);

int main(){
	int c_Num;
	int a, b, c;
	cin >> c_Num;
	for (int i = 0; i < c_Num; i++){
		cin >> a >> b >> c;
		cout << CheckTriangle(a, b, c) << endl;
	}
}

int CheckTriangle(int a, int b, int c){
	if (a + b <= c) return 0;
	else {
		if (a == b && b == c && c == a) return 1;
		else if (a == b || b == c || c == a) return 3;
		else if (a * a + b * b == c * c) return 2;
		else return 4;
	}
}
