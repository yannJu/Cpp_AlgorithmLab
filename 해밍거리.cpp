#include<iostream>
using namespace std;

class HammingBin{
	int arr[32];
	int oneCk, cnt;
	int num;
	public:
		HammingBin(int n = 0) {num = n; oneCk = 0; cnt = 0;}
		void DtoB();
		int getOne() {return oneCk;}
		int& operator[] (int);
		friend bool operator!= (const HammingBin& a, const HammingBin& b) {return (a!=b);}
};

void HammingBin::DtoB(){
	while(cnt < 32){
		if (num % 2 == 1) oneCk += 1;
		arr[cnt++] = num%2;
		num /= 2;
	}
}

int& HammingBin::operator[] (int k){
	return arr[k];
}
int main(){
	int c_Num;
	int m, n;
	int hd;
	cin >> c_Num;
	while(c_Num--){
		cin >> m >> n;
		hd = 0;
		HammingBin h1(m); HammingBin h2(n);
		h1.DtoB(); h2.DtoB();
		cout << h1.getOne() << " " << h2.getOne() << " ";
		for (int i = 0; i < 32; i++){
			if (h1[i] != h2[i]) hd += 1;
		}
		cout << hd << endl;
	}
}
