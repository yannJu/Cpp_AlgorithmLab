#include <iostream>
#include <cmath>
using namespace std;

int CheckTriangle(int a, int b, int c);

int main(){
	int c_Num;
	int x1, x2, x3, y1, y2, y3;
	int a, b, c, max;
	
	cin >> c_Num;
	for(int i = 0; i < c_Num; i++){
		cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
		a = pow(x2 - x1, 2) + pow(y2 - y1, 2);
		b = pow(x3 - x2, 2) + pow(y3 - y2, 2);
		c = pow(x3 - x1, 2) + pow(y3 - y1, 2);
		/*
		a = (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);
		b = (x3 - x2) * (x3 - x2) + (y3 - y2) * (y3 - y2);
		c = (x3 - x1) * (x3 - x1) + (y3 - y1) * (y3 - y1);
		*/
		max = c;
		if (a > c) {max = a; a = c; c = max;}
		if (b > c) {max = b; b = c; c = max;}
		cout << CheckTriangle(a, b, c) << endl;
	}
}

int CheckTriangle(int a, int b, int c){
	if (sqrt(a)+ sqrt(b) <= sqrt(c)) return 0;
	else if (a + b == c) return 1;
	else if (a + b < c) return 2;
	else return 3;
}
