 #include <iostream>
using namespace std;

int main(){
	int c_N, n;
	cin >> c_N;

	for (int i = 0; i < c_N; i++){
		cin >> n;
		for (int j = 0; j < n; j++){
			for (int k = 0; k < n; k++){
				if (j == n / 2){
					if (k == n / 2) cout << "O";
					else cout << "+";
				}
				else{
					if (k == n / 2) cout << "I";
					else if (k == n - j - 1) cout << "*";
					else cout << ".";
				}
			}
			cout << endl;
		}
	}
}
