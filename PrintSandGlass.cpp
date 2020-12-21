#include <iostream>
using namespace std;

int main(){
	int c_N, n;
	cin >> c_N;
	for (int i = 0; i < c_N; i++){
		cin >> n;
		for (int j = 0; j < n; j++){
			if (j <= n / 2){
				for (int l = 0; l < j; l++){ 
				cout << "-";
				}
				for (int k = 0; k < n - j * 2; k++){
					if (k % 2 == 0) cout << "*";
					else cout << "+";
				}
				for (int l = 0; l < j; l++){ 
				cout << "-";
				}
				cout << endl;
			}
			else{
				for (int l = 0; l < n - j - 1; l++){ 
				cout << "-";
				}
				for (int k = 0; k < 2 * j - n + 2; k++){
					if (k % 2 == 0) cout << "*";
					else cout << "+";
				}
				for (int l = 0; l < n - j - 1; l++){ 
				cout << "-";
				}
				cout << endl;
			}
		}
	}
}
