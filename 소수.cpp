#include <iostream>
#include <cmath>
using namespace std;

int main(){
	int c_Num;
	int checkNum, sq_Num;
	int answer;
	cin >> c_Num;
	for (int i = 0; i < c_Num; i++){
		answer = 1;
		cin >> checkNum;
		sq_Num = sqrt(checkNum);
		while (sq_Num > 1){
			if (checkNum % sq_Num-- == 0) {
				answer = 0;
				break;
			}
		}
		cout << answer << endl;
	}
}
