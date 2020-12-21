#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

int main(){
	int c_Num;
	int num;
	ifstream in("input.txt");
	in >> c_Num;
	for (int i = 0; i < c_Num; i++){
		int arr[32] = {0,};
		int cnt = 0, oneCk = 0;
		unsigned int answer = 0;
		in >> num;
		while (cnt < 32){
			if (num % 2 == 1) oneCk += 1;
			arr[cnt++] = num % 2;
			num /= 2;
		}
		if (oneCk % 2 == 1 || num == 1) arr[31] = 1;
		for (int i = 31; i >= 0; i--){
			if (arr[i] == 1) answer += pow(2, i);
		}
		cout << answer << endl;
	}
}
