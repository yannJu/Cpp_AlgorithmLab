#include <iostream>
#include <cmath>
using namespace std;

int main(){
	int c_Num;
	int x1, x2, y1, y2;
	int px1, py1, px2, py2;
	
	cin >> c_Num;
	for (int i = 0; i < c_Num; i++){
		cin >> x1 >> y1 >> x2 >> y2;
		cin >> px1 >> py1 >> px2 >> py2;
		
		//첫번째 선분이 세로일때
		if (x1 == x2 && py1 == py2){
			if (((y1 <= py1 && py1 <= y2) || (y2 <= py1 && py1 <= y1))){
				if (py1 == y1 || py1 == y2 || px1 == x1 || px2 == x1) cout << 2 << endl;
				else if (min(px1, px2) <= x1 && x1 <= max(px1, px2)) cout << 2 << endl;
				else if (x1 > max(px1, px2) || x1 < min(px1, px2)) cout << 0 << endl;
				else cout << 1 << endl;
			}
			else cout << 0 << endl;
		}
		//첫번째 선분이 가로일때
		if (y1 == y2 && px1 == px2){
			if ((x1 <= px1 && px1 <= x2) || (x2 <= px1 && px1 <= x1)){
				if (py1 == y1 || py2 == y1 || px1 == x1 || px1 == x2) cout << 2 << endl;
				else if (min(py1, py2) <= y1 && y1 <= max(py1, py2)) cout << 2 << endl;
				else if (y1 > max(py1, py2) || y1 < min(py1, py2)) cout << 0 << endl;
				else cout << 1 << endl;
			}
			else cout << 0 << endl;
		}
	}
}
