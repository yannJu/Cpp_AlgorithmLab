#include <iostream>
#include <vector>
#include <climits>
using namespace std;

void matrixChain(vector<int> &P);

int main(){
    int  t_case, matrixN, tmpR, tmpC;
    vector<int> P;

    cin >> t_case;
    while(t_case--){
        cin >> matrixN;
        for (int i = 0; i < matrixN; i++){
            cin >> tmpR >> tmpC;
            if (i == 0) P.push_back(tmpR);
            P.push_back(tmpC);
        }
        matrixChain(P);
    }
}

void matrixChain(vector<int> &P){
    int **result = new int*[P.size() - 1];
    int **s = new int*[P.size() - 1];
    int k, minCal = INT_MAX;
    for (int i = 0; i < P.size() - 1; i++) result[i] = new int[P.size() - 1];
    for (int i = 0; i < P.size() - 1; i++) s[i] = new int[P.size() - 1];

    for (int i = 0; i < P.size() - 1; i++) result[i][i] = 0;
    for (int i = 0; i < P.size() - 1; i++) result[i][i] = i + 1;
    for (int l = 2; l < P.size(); l++){
        for (int j  = 1; j < P.size() -l + 1; j++){
            k = j + l - 1;
            result[j - 1][k - 1] = INT_MAX;
            for (int m = j; m < k; m++) {
                minCal = result[j - 1][m - 1] + result[m][k - 1] + (P[j - 1] * P[m] * P[k]);
                if (minCal < result[j - 1][k - 1]) {
                    result[j - 1][k - 1] = minCal;
                    s[j - 1][k - 1] = m;
                }
            }
        }
    }
    for (int i= 0; i < P.size() - 1; i++){
        for (int j = 0;  j < P.size() - 1; j++) cout << s[i][j] << " ";
        cout << endl;
    }
}