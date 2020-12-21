#include <iostream>
#include <string>
#include <cmath>
#include <sstream>
using namespace std;

void IP2B(string);
void B2IP(unsigned ui);

int main(){
	int c_Num;
	int num;
	unsigned int ui;
	string word;

	cin >> c_Num;
	while(c_Num--){
		cin >> num;
		if (num == 1){
			cin >> word;
			IP2B(word);
		}
		else if (num == 2){
			cin >> ui;
			B2IP(ui);
		}
	}
}

void IP2B(string w){
	string num = "";
	int arr[8] = {0,};
	int result[32] = {0,};
	int n, ar_cnt, re_cnt = 31;
	unsigned int answer = 0;

	
	for (int i = 0; i < w.length(); i++){
		if (w[i] == '.' || i == w.length() - 1) {
			if (i == w.length() - 1) num += w[i];
			n = 0;	ar_cnt = 0; //n값, ar count값 초기화
			for (int i = 0; i < num.length(); i++){ //string이었던 num을 변환하기 위해서
				n += (num[i]-'0') * pow(10, num.length() - i - 1);
			}
			while (n > 0){ //2진화 된 n을 arr에 채워주기
				arr[ar_cnt++] = n % 2;
				n /= 2;
			}
			for (int i = 7; i >= 0; i--){ //result에 n2진수 채워주기
				result[re_cnt--] = arr[i];
			}
			num = "";//num cnt초기화
			for (int i = 0; i < 8; i++) arr[i] = 0;
		}
		else num += w[i];
	}
	for (int i = 0; i < 32; i++){
		if (result[i] == 1) answer += pow(2, i);
	}
	cout << answer << endl;
}

void B2IP(unsigned int ui){
	int result[32] = {0,};
	int arr[8] = {0,};
	int re_cnt = 0, ar_cnt = 7, answer = 0;
	string s;
	stringstream ss;

	while(ui > 0){
		result[re_cnt++] = ui % 2;
		ui /= 2;
	}

	for (int i = 31; i >= 0; i--){
		arr[ar_cnt--] = result[i];
		if (ar_cnt == -1){
			for (int i = 0; i < 8; i++) answer += arr[i] * pow(2, i);
			ss << answer;
			ar_cnt = 7; answer = 0;
			for (int i = 0; i < 8; i++) arr[i] = 0;
		}
		if (i < 31 && i % 8 == 7) ss << ".";
		s = ss.str();
	}
	cout << s << endl;

	
}
