#include <iostream>
#include <string>
using namespace std;

int checkISBN(string word);
int checkSum(string word);

int main(){
	int c_Num;
	string word;

	cin >> c_Num;
	while(c_Num--){
		cin >> word;
		cout << checkISBN(word) << endl;
	}
}

int checkISBN(string word){
	int result = 1;
	int cnt = 0, bar = 0;
	int wordLength = word.length();
	if (wordLength != 13) return 0;
	for (int i = 0; i < wordLength; i++){
		//cout << "r : " << word[i] << endl;
		if (word[i] == '-'){
			//cout << "bar : " << bar << ", cnt : " << cnt << endl;
			if (i == 0) return 0; //맨앞에 들어온 수가 없는 경우
			if (bar == 0 && (cnt > 5 || cnt == 0)) return 0; 
			if (bar == 1 && (cnt > 7 || cnt == 0)) return 0; 
			if (bar == 2){
				if (cnt > 6 || cnt == 0) return 0;
				result = checkSum(word);
			} 
			if (bar >= 3) return 0;
			bar += 1; cnt = 0;
		}
		else if (word[i] != 'X' && isdigit(word[i]) == 0) return 0; //이상한 문자가 들어온경우
		else if (word[i] == 'X' && i < wordLength - 1) return 0; 
		else cnt += 1;
	}
	if (cnt != 1) return 0;
	return result;
}

int checkSum(string word){
	int arr[10] = {0,};
	int result = 0;
	int n = 0;
	int ar_cnt = 0;
	char c;
	
	for (int i = 0; i < word.length(); i++){
		if(word[i] == 'X') c = word[i];
		if (word[i] != '-') arr[ar_cnt++] = word[i]-'0';
	}
	//cout << endl;
	for (int i = 10; i > 1; i--){
		result += (i * arr[10 - i]);
	}
	if (result % 11 == 0) n = result / 11;
	else n = (result / 11) + 1;
	//cout << "1." << n*11 << ", 2,." << arr[9] << ", 3. " << result << endl;
	if (n * 11 - result == arr[9]) return 1;
	else if (n * 11 - result == 10 && c == 'X') return 1;
	
	return 0;
}
