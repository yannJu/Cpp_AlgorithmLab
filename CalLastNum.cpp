#include <iostream>
#include <stdlib.h>
using namespace std;

int main(){
	int c_num, h_num, num;
	int result;
	cin >> c_num;
	for (int i = 0; i < c_num; i++){
		cin >> h_num;
		result = 1;
		for (int j = 0; j < h_num; j++){
			cin >> num;			
			result *= num % 10;
			result %= 10;
		}
		cout << result << endl;
	}
	return 0;
}
