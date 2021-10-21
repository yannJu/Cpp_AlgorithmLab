#include <iostream>
#include <vector>
using namespace std;

int **A, **B, **C;
void matrixMultiple_bruteForce(int**, int**, int, int, int);
int** matrixMultiple_divideConquer(int**, int**, int);

int main(){
    int Ar, Ac, Br, Bc, tmp;

    cin >> Ar >> Ac >> Br >> Bc;
    if (Ac != Br) {
        cout << "Error!" << endl;
        return 0;
    }
    A = new int*[Ar]; B = new int*[Br];
    for (int j = 0; j < Ar; j++) A[j] = new int[Ac];
    for (int j = 0; j < Br; j++) B[j] = new int[Bc];
    for (int k = 0; k < Ar; k++){
        for (int l = 0; l < Ac; l++){
            cin >>  tmp;
            A[k][l] = tmp;
        }
    }
    for (int k = 0; k < Br; k++){
        for (int l = 0; l < Bc; l++){
            cin >>  tmp;
            B[k][l] = tmp;
        }
    }
    matrixMultiple_bruteForce(A, B, Ar, Ac, Bc);
    C = matrixMultiple_divideConquer(A, B, Ar);
    cout << "divideConquer-------------------------" << endl;
    for (int i = 0; i < Ar; i++){
        for (int j = 0; j < Ar; j++) cout << C[i][j] << " " ;
        cout << endl;
    }
    cout << "--------------------------------------" << endl;
}

void matrixMultiple_bruteForce(int** a, int**b, int r, int ar, int c){
    int **C = new int*[r];
    int sum;

    for (int i = 0; i < r; i++) C[i] = new int[c];
    for (int j = 0; j < r; j++){
        for (int k = 0; k < c; k++){
            sum = 0;
            for (int l = 0; l < ar; l++){
                sum += A[j][l] * B[l][k];
            }
            C[j][k] = sum;
        }
    }
    cout << "BruteForce-------------------------" << endl;
    for (int i = 0; i < r; i++){
        for (int j = 0; j < c; j++) cout << C[i][j] << " " ;
        cout << endl;
    }
    cout << "--------------------------------------" << endl;
}

int** matrixMultiple_divideConquer(int**a, int**b, int ar){
    int n = ar;
    int **C = new int*[ar];
    int **Atmp_f = new int*[ar/2],  **Atmp_s = new int*[ar/2], **Btmp_f = new int*[ar/2], **Btmp_s = new int*[ar/2];
    for (int i = 0; i < ar; i++) C[i] = new int[ar];
    if (n == 1) C[0][0] = a[0][0] * b[0][0];
    else {
        //C11
        for (int i = 0; i < n / 2; i++){
            Atmp_f[i] = new int[ar / 2];
            Btmp_f[i] = new int[ar / 2];
            Atmp_s[i] = new int[ar / 2];
            Btmp_s[i] = new int[ar / 2];
            for (int j = 0; j < n / 2; j++) { 
                Atmp_f[i][j] = a[i][j];
                Btmp_f[i][j] = b[i][j];
                Atmp_s[i][j] = a[i][j + n / 2];
                Btmp_s[i][j] = b[i + n / 2][j];
            }
        }
        for (int i = 0; i < n / 2; i++){
            for (int j = 0; j < n / 2; j++ ) C[i][j] = matrixMultiple_divideConquer(Atmp_f, Btmp_f, ar / 2)[i][j] + matrixMultiple_divideConquer(Atmp_s, Btmp_s, ar / 2)[i][j];
        }
        //C12
        for (int i = 0; i < n / 2; i++){
            Atmp_f[i] = new int[ar / 2];
            Btmp_f[i] = new int[ar / 2];
            Atmp_s[i] = new int[ar / 2];
            Btmp_s[i] = new int[ar / 2];
            for (int j = 0; j < n / 2; j++) { 
                Atmp_f[i][j] = a[i][j];
                Btmp_f[i][j] = b[i][j + n / 2];
                Atmp_s[i][j] = a[i][j + n / 2];
                Btmp_s[i][j] = b[i+ n / 2][j + n / 2];
            }
        }
        for (int i = 0; i < n / 2; i++){
            for (int j = 0; j < n / 2; j++ ) {
                C[i][j + n / 2] = matrixMultiple_divideConquer(Atmp_f, Btmp_f, ar / 2)[i][j] + matrixMultiple_divideConquer(Atmp_s, Btmp_s, ar / 2)[i][j];
            }
        }
        //C21
        for (int i = 0; i < n / 2; i++){
            Atmp_f[i] = new int[ar / 2];
            Btmp_f[i] = new int[ar / 2];
            Atmp_s[i] = new int[ar / 2];
            Btmp_s[i] = new int[ar / 2];
            for (int j = 0; j < n / 2; j++) { 
                Atmp_f[i][j] = a[i + n / 2][j];
                Btmp_f[i][j] = b[i][j];
                Atmp_s[i][j] = a[i + n / 2][j + n / 2];
                Btmp_s[i][j] = b[i + n / 2][j];
            }
        }
        for (int i = 0; i < n / 2; i++){
            for (int j = 0; j < n / 2; j++ ) {
                C[i + n / 2][j] = matrixMultiple_divideConquer(Atmp_f, Btmp_f, ar / 2)[i][j] + matrixMultiple_divideConquer(Atmp_s, Btmp_s, ar / 2)[i][j];
            }
        }
        //C22
        for (int i = 0; i < n / 2; i++){
            Atmp_f[i] = new int[ar / 2];
            Btmp_f[i] = new int[ar / 2];
            Atmp_s[i] = new int[ar / 2];
            Btmp_s[i] = new int[ar / 2];
            for (int j = 0; j < n / 2; j++) { 
                Atmp_f[i][j] = a[i + n / 2][j];
                Btmp_f[i][j] = b[i][j + n / 2];
                Atmp_s[i][j] = a[i + n / 2][j + n / 2];
                Btmp_s[i][j] = b[i+ n / 2][j + n / 2];
            }
        }
        for (int i = 0; i < n / 2; i++){
            for (int j = 0; j < n / 2; j++ ) {
                C[i + n / 2][j + n / 2] = matrixMultiple_divideConquer(Atmp_f, Btmp_f, ar / 2)[i][j] + matrixMultiple_divideConquer(Atmp_s, Btmp_s, ar / 2)[i][j];
            }
        }
    }
    return C;
}