#include <iostream>
using namespace std;

int main(){
	int c, num_f, num_e, sum;
	cin >> c;
	for (int i = 0; i < c; i++){
		sum = 0;
		cin >> num_f;
		cin >> num_e;
		while (num_f <= num_e){
			sum += num_f;
			num_f++;
		}
		cout << sum << endl;
	}
	return 0;
}
