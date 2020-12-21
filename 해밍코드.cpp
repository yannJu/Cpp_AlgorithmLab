#include <iostream>
#include <cmath>
using namespace std;


int main(){
	int c_Num, p_Num;
	int n, num;

	cin >> c_Num;
	while(c_Num--){
		int arr[32] ={0,};
		int cnt = 0;
		unsigned int answer = 0;
		int cK;

		cin >> n >> num;

		while (cnt < 32){
			if(n == 0 && (cnt == 0 || cnt == 1 || cnt == 3 || cnt == 7 || cnt == 15)) arr[cnt++] = 2;
			else {
				arr[cnt++] = num % 2; num /= 2;
			}
		} //2진수로 변환하여 배열에 담음(p = 2로)

		if (n == 1){ //패리티비트를 실제비트로 (오류수정)
			int ErrNum = 0; //에러난 P를 찾아서 더해줄 변수
			int cK_arr[5] = {0,}; //P가 에러난 경우 1로변경
			int result_arr[27] = {0,}, cnt = 0; //실제비트를 담기위한 배열
			for (int i = 0; i < 5; i++){ //1, 2, 4, 8, 16이므로
				cK = 0; //1을 ChecK하기 위한 변수
				p_Num = pow(2, i); //p의 위치
				for (int j = p_Num - 1; j < 32; j += 2*p_Num){
					for (int k = 0; k < p_Num; k++) cK += arr[j + k];
				}
				if (cK % 2 != 0) cK_arr[i] = 1; //1의 갯수가 홀수이면 에러나기때문에 1로 바꿔줌
			}
			for (int i = 0; i < 5; i++){
				if (cK_arr[i] == 1) ErrNum += pow(2, i);
			}
			if (ErrNum){
				if (arr[ErrNum - 1] == 0) arr[ErrNum - 1] = 1;
				else arr[ErrNum - 1] = 0;
			}
			for (int i = 0; i < 32; i++){
				if (!(i == 0 || i == 1 || i == 3 || i == 7 || i == 15)){
					result_arr[cnt++] = arr[i];
				}
			}
			for (int i = 0; i < 27; i++){
				if (result_arr[i] == 1) answer += pow(2, i);
			}
		}
		else if (n == 0){ //32비트의 패리티비트 계산
			for (int i = 0; i < 5; i++){ //1, 2, 4, 8, 16이므로
				cK = 0; //1을 ChecK하기 위한 변수
				p_Num = pow(2, i); //p의 위치
				for (int j = p_Num - 1; j < 32; j += 2*p_Num){
					for (int k = 0; k < p_Num; k++){
						if (arr[j + k] != 2) cK += arr[j + k];
					}
				}
				if (cK % 2 == 0) arr[p_Num - 1] = 0;
				else arr[p_Num - 1] = 1;
			}
			for (int i = 0; i < 32; i ++){
				if (arr[i] == 1) answer += pow(2, i);
			}
		}
		cout << answer << endl;
	}
}
