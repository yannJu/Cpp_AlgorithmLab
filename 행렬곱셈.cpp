#include <iostream>
using namespace std;

int** makeArray(int* sz);

int main(){
	int c_Num;
	int r, s, t;
	int num;
	int **arr1 = NULL, **arr2 = NULL, **answer = NULL; 
	int *sz1 = NULL, *sz2 = NULL, *answersz =NULL;
	int result;

	cin >> c_Num;
	while(c_Num--){
		cin >> r >> s >> t;
		sz1 = new int[2];
		sz1[0] = r; sz1[1] = s;
		arr1 = makeArray(sz1);
		for (int i0 = 0; i0 < r; i0++){
			for (int i1 = 0; i1 < s; i1++){
				cin >> num;
				arr1[i0][i1] = num;
			}
		}//arr1 배열생성

		sz2 = new int[2];
		sz2[0] = s; sz2[1] = t;
		arr2 = makeArray(sz2);
		for (int i0 = 0; i0 < s; i0++){
			for (int i1 = 0; i1 < t; i1++){
				cin >> num;
				arr2[i0][i1] = num;
			}
		} //arr2 배열생성

		answersz = new int[2];
		answersz[0] = r; answersz[1] = t;
		answer = makeArray(answersz);
		for (int i0 = 0; i0 < r; i0++){
			for (int i1 = 0; i1 < t; i1++){
				result = 0;
				for (int j = 0; j < s; j++){
					result += arr1[i0][j] * arr2[j][i1];
				}
				answer[i0][i1] = result;
			}
		} //answer배열 생성(행렬곱셈)

		for (int i = 0; i < r; i++){
			for (int j = 0; j < t; j++){
				cout << answer[i][j] << " ";
			}
			cout << endl;
		}
	}	
}

int** makeArray(int* sz){
	int n1 = sz[0], n2 = sz[1];
	int **arr = new int *[n1];
	for (int i = 0; i < n1; i++){
		arr[i] = new int [n2];
	}
	return arr;
}
