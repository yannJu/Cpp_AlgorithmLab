#include <iostream>
#include <fstream>
using namespace std;

int main(){
	int arrSize;
	int c_Num, row, col, i, j;
	int n;
	ifstream in("input.txt");
	in >> c_Num;
	while(c_Num--){
		in >> row >> col;
		int a[row][col], b[row][col], c[row][col];
		for (i = 0; i < row; i++){
			for (j = 0; j < col; j++){
				in >> n;
				a[i][j] = n;
			}
		}
		for (i = 0; i < row; i++){
			for (j = 0; j < col; j++){
				in >> n;
				b[i][j] = n;
			}
		}
		for (i = 0; i < row; i++){
			for (j = 0; j < col; j++){
				c[i][j] = a[i][j] + b[i][j];
				cout << c[i][j] << " ";
			}
			cout << endl;
		}
	}	
}
