#include <iostream>
using namespace std;

int main(){
	int c, n, numbers;
	int min, max;

	cin >> c;
	for (int i = 0; i < c; i++){
		cin >> n;
		cin >> numbers;
		min = max = numbers;
		for (int j = 1; j < n; j++){
			cin >> numbers;
			if (min > numbers){
				min = numbers;
			}
			if (max < numbers){
				max = numbers;
			}
		}
		cout << max << " " << min << endl;	
	}
	return 0;
}
