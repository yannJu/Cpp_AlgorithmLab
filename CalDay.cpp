#include <iostream>
using namespace std;

int main(){
	int c, y;
	int cent, N, T, I, J, K, L, P, Q, month, day;
	cin >> c;
	for (int i = 0; i < c; i++){
		cin >> y;
		cent = y / 100;
		N = y - y / 19 * 19;
		T = (cent - 17) / 25;
		I = (cent - ((cent / 4) + ((cent - T) / 3))) + (N * 19 + 15);
		J = I - I / 30 * 30;
		K = J - ((J / 28) * (1 - J / 28) * (29 / (J + 1)) * ((21 - N) / 11));
		L = ((y + (y / 4)) + J + 2) - cent + (cent / 4);
		P = L - (L / 7 * 7);
		Q = K - P;
		month = (Q + 40) / 44 + 3;
		day = (Q + 28) - (month / 4 * 31);
		/*cout << "y = " << y << " cent = " << cent << " N = " << N ;
		cout << " T = " << T << " I = " << I << " J = " << J;
		cout << " K = " << K << " L = " << L << " P = " << P;
		cout << " Q = " << Q << endl;
		*/
		cout << month << " " << day << endl;
	}
	return 0;
}

