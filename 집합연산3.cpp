#include <iostream>
#include <fstream>
using namespace std;

int main(){
	ifstream in("input.txt");
	int c_Num, sz, n;
	int Ack, Ock, Nck; //교집합, 합집합, 차집합의 1의 개수 check
	int resultA[132], resultO[132], resultN[132]; //결과를 담을 배

	in >> c_Num;
	while(c_Num--){
	unsigned int a[132] = {0,}, b[132] = {0,};
	unsigned int A[132] = {0,}, O[132] = {0,}, N[132] = {0,};
	Ack = 0; Ock = 0; Nck = 0; //초기화
		in >> sz;
		while(sz--){
			in >> n;	
			a[n] = 1;
		}
		in >> sz;
		while(sz--){
			in >> n;
			b[n] = 1;
		} // a, b집합 배열로 생성
		
		for (int i = 0; i < 132; i++){
			if (a[i] == 1 && b[i] == 1) {
				A[i] = 1; resultA[Ack++] = i; //교집합이 1이면 체크 +1 배열에 그 인덱스 담음
			}
		}
		for (int i = 0; i < 132; i++){
			if (a[i] == 1 || b[i] == 1) {
				O[i] = 1; resultO[Ock++] = i; //합집합이 1이면 체크 +1 배열에 그 인덱스 담음
			}
		}
		for (int i = 0; i < 132; i++){
			if (a[i] == 1 && not(b[i] == 1)) {
				N[i] = 1; resultN[Nck++] = i; //차집합이 1이면 체크 +1 배열에 그 인덱스 담음
			}
		}
		
		cout << Ack << " ";
		for (int i = 0; i < Ack; i++){
			cout << resultA[i] << " ";
		}
		cout << endl << Ock << " ";
		for (int i = 0; i < Ock; i++){
			cout << resultO[i] << " ";
		}
		cout << endl << Nck << " ";
		for (int i = 0; i < Nck; i++){
			cout << resultN[i] << " ";
		}
		cout << endl;
	}
}
