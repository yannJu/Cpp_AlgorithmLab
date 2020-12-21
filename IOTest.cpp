#include<iostream>
using namespace std;

int main(){
	int icnt;
	int t;
	int numbers;

	cin >> icnt;
	for (int i = 0; i < icnt; i++){
		cin >> t;
		int sum = 0;
		for (int j = 0; j < t; j++){
			cin >> numbers;
			sum += numbers;
		}
		cout << sum << endl;
	}
	return 0;
}
