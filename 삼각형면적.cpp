#include <iostream>
#include <cmath>
using namespace std;

int main(){
	int c_Num;
	int x1, x2, x3, y1, y2, y3;
	int signedArea, handle;
	cin >> c_Num;
	for (int i = 0; i < c_Num; i++){
		cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
		signedArea = ((x2 - x1) * (y3 - y1) - (x3 - x1) * (y2 - y1));
		if (signedArea < 0) handle = -1;
		else if (signedArea == 0) handle = 0;
		else handle = 1;
		cout << abs(signedArea) << " " << handle << endl;
	}
}
