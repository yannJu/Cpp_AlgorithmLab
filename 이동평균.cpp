#include <iostream>
#include <fstream>
using namespace std;

void cal(int sz, int k, int arr[]);

int main(){
	int c_Num;
	int sz, n;
	int k, i;
	ifstream in("input.txt");

	in >> c_Num;
	while(c_Num--){
		in >> sz; int arr[sz];
		for(i = 0; i < sz; i++){
			in >> arr[i];
		}
		in >> k;
		cal(sz, k, arr);
	}
}

void cal(int sz, int k, int arr[]){
	int p = 0, answer;
	int c = sz - k + 1;
	cout << c << " ";
	while(c--){
		answer = 0;
		for (int i = p; i < k + p; i++){
			answer += arr[i];
		} 
		cout << answer / k << " ";
		p += 1;
	}
	cout << endl;
}
