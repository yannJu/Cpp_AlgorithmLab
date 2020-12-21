#include <iostream>
using namespace std;

int main(){
	int c_num, t_num, a_num, result;
	cin >> c_num;
	for(int i = 0; i < c_num; i++){
		cin >> t_num;
		for(int j = 1; j <= t_num; j++){
			cout << j;
			a_num = t_num - 1;
			result = j + a_num;
			for(int n = 1; n < j; n++){
				cout << " " << result;
				a_num -= 1;
				result += a_num;
			}
			cout << endl;
		}
	}
	return 0;
}
