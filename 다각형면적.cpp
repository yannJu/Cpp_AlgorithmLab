#include <iostream>
#include <cmath>
using namespace std;

struct Temp{
	int x;
	int y;
};
Temp t[100];

int SignedArea(Temp t[], int sc_Num);

int main(){
	int c_Num;
	int sc_Num, x1, y1;
	int cnt;
	int answer;
	cin >> c_Num;
	for (int i = 0; i < c_Num; i++){
		cin >> sc_Num;
		cnt = 0;
		answer = 1;
		for (int j = 0; j < sc_Num; j++){
			cin >> x1 >> y1;
			t[cnt].x = x1; t[cnt++].y = y1;
		}
		int s = SignedArea(t, sc_Num);
		if (s < 0) answer = -1;
		cout << abs(s) << " " << answer << endl; 
	}
}

int SignedArea(Temp t[], int sc_Num){
	int signedarea = 0;
	for (int i = 0; i < sc_Num; i++){
		signedarea += (t[i].x + t[(i+1)%sc_Num].x) * (t[(i+1)%sc_Num].y - t[i].y);
	}
	return signedarea;
}
