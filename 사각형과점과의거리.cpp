#include <iostream>
#include <cmath>
using namespace std;

int CheckEculidean(int min_x, int px, int min_y, int py);
int CheckRectilinear(int min_x, int px, int min_y, int py);

int main(){
	int c_Num;
	int x1, x2, y1, y2;
	int px, py;
	int min_x, min_y;

	cin >> c_Num;
	for(int i = 0; i < c_Num; i++){
		cin >> x1 >> y1 >> x2 >> y2;
		cin >> px >> py;
		if ((x1 <= px && px <= x2) && (y1 <= py && py <= y2)) cout << 0 << " " << 0 << endl;
		else {
			if (px > x2) min_x = x2;
			else if (px < x1) min_x = x1;
			else min_x = px;
			if (py > y2) min_y = y2;
			else if (py < y1) min_y = y1;
			else min_y = py;
			cout << CheckEculidean(min_x, px, min_y, py) << " " << CheckRectilinear(min_x, px, min_y, py) << endl;
		}
	}
}

int CheckEculidean(int min_x, int px, int min_y, int py) {
	int result = pow((min_x - px), 2) + pow((min_y - py), 2);
	return result;
	}
int CheckRectilinear(int min_x, int px, int min_y, int py) {
	int result = abs(min_x - px) + abs(min_y - py);
	return result;
	}
