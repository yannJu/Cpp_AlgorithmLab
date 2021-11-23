//시작, 출발 노드번호가 주어졌을때 최소 weight를 가지는 path를 구함
#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

void FloydWarshall(int ***, int, int ***, int ***);
void printPath(int, int, int***);

int main(){
    //입력은전체 노드수와 연결되는 노드pair, 연결되는 i, j와 weight로 이루어진다.
    int n, t_case, **W, **D, **PI;
    int tmpi, tmpj;

    //Initialize Weight Matrix
    cin >> n >> t_case;
    W = new int*[n];
    for (int i = 0; i < n; i++){
        int *tmp = new int[n];
        for (int j = 0; j < n; j++) tmp[j] = 100;
        tmp[i] = 0;
        W[i] = tmp;
    }

    while(t_case--){
        int i, j, weight;
        cin >> i >> j >> weight;
        W[i - 1][j - 1] = weight;
    }

    FloydWarshall(&W, n, &D, &PI);

    cout << "input Path : " << endl;
    cin >> tmpi >> tmpj;
    printPath(tmpi - 1, tmpj - 1, &PI);
    cout << endl;
}

void FloydWarshall(int ***W, int rows, int ***resultD, int ***resultPI){
    int n = rows;
    int **w = *W, **D = new int*[n], **d = new int*[n], **pi = new int*[n];

    //D(0) = W, Initialize Pi Matrix
    for (int i = 0; i < n; i++){
        int *tmp = new int[n];
        int *pTmp = new int[n];
        int *dTmp = new int[n];
        for (int j = 0; j < n; j++) {
            tmp[j] = w[i][j];
            dTmp[j] = w[i][j];
            if (w[i][j] < 100) pTmp[j] = i + 1;
            else pTmp[j] = 0;
        }
        pTmp[i] = 0;
        D[i] = tmp;
        pi[i] = pTmp;
        d[i] = dTmp;
    }

    for (int k = 0; k < n; k++){
        //copy(&D[0][0], &D[0][0] + (n * n), &d[0][0]);
        //D = k - 1번째 배열, d = 현재 배열
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                d[i][j] = min(D[i][j], D[i][k] + D[k][j]);
                if (D[i][j] > D[i][k] + D[k][j]) pi[i][j] = pi[k][j];
            }
        }
        for (int l = 0; l < n; l++){
            for (int m = 0; m < n; m++) D[l][m] = d[l][m];
        }
    }
    /*print ASP Matrix
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++) cout << D[i][j] << " ";
        cout << endl;
    }
    */
    /*print pi Matrix
   for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++) cout << pi[i][j] << " ";
        cout << endl;
    }
    */
   *resultD = D;
   *resultPI = pi;
}

void printPath(int I, int J, int***PI){
    int **pi = *PI;

    if (pi[I][J] == 0) {
        cout << J + 1 << " ";
        return;
    }
    printPath(I, pi[I][J] - 1, PI);
    cout << J + 1 << " ";
}