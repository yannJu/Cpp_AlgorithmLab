#include <iostream>
#include <fstream>
#include <algorithm>
#include <climits>
using namespace std;

unsigned int arr[1350] = {0,};

int main(){
	ifstream in("input.txt");
	int c_Num, k;
	unsigned int num = 1, cnt = 0;
	in >> c_Num;
	while(c_Num--){
		in >> k;
		while (cnt <= k){
			for (int i = 1;; i <<= 1){
				for (int j = i;; j *= 3){
					for (int k = j;; k *= 5){
						arr[cnt++] = k;
						if (k > UINT_MAX / 5) break;
					}
					if (j > UINT_MAX / 3) break;
				}
				if (i > UINT_MAX >> 1) break;
			}
			sort(arr, arr + cnt);
		}
		cout << arr[k - 1] << endl;
	}
}
