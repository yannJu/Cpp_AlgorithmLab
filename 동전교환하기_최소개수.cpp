/*
동전 교환하기 (최소개수) (2)
거스름 돈을 동전으로 교환할 때, 동전의 개수가 가장 적게 교환하는 방법을 찾는 프로그램을 작성하
시오. 단, 동전은 무한히 많다고 가정한다.
예를 들어, 동전에는 1 원, 5 원, 10 원, 25 원, 50 원, 100 원 짜리 동전 등의 총 6 종류가 있고, 287
원을 교환할 때 100 원 동전 2 개, 50 원 동전 1 개, 25 원 동전 1 개, 10 원 동전 1 개, 1 원 동전 2 개
등 총 7 개의 동전으로 교환할 수 있다. 7 개는 287 원을 동전으로 교환할 때 필요한 동전의 최소 개
수이다.

입력
입력은 표준입력(standard input)을 사용한다. 입력은 t 개의 테스트 케이스로 주어진다. 입력 파일
의 첫 번째 줄에 테스트 케이스의 개수를 나타내는 정수 t 가 주어진다. 두 번째 줄부터 두 줄에 한 개
의 테스트 케이스에 해당하는 데이터들이 주어진다. 각 테스트 케이스에 해당되는 첫 줄에는 거스름
돈의 금액을 나타내는 정수 n (1 ≤ n ≤ 1,000) 이 주어진다. 두 번째 줄의 첫 번째 정수는 동전의
종류의 개수를 나타내는 정수 m (1 ≤ m ≤ 10) 이 나타나고, 그 다음으로는 m 개의 정수가 나타나
는데 각 정수는 동전의 금액을 나타내는 정수이다. 이 m 개의 정수는 작은 정수부터 큰 정수 순서로
나타내며, 가장 적은 정수는 항상 1 이다. 또한 이 m 개의 정수는 각각 다르다. 잘못된 데이터가 입력
되는 경우는 없다.
출력
출력은 표준출력(standard output)을 사용한다. 입력되는 테스트 케이스의 순서대로 다음 줄에 이어
서 각 테스트 케이스의 결과를 출력한다. 각 테스트 케이스에 해당하는 출력의 첫 줄에 주어진 거스
름 돈을 동전으로 교환할 때 필요한 동전의 최소 개수를 나타내는 정수를 출력한다.
© Copyright 2021 by Joonsoo Choi. All Rights Reserved.
입력과 출력의 예
입력
3
287
6 1 5 10 25 50 100
63
6 1 5 10 21 25 50
16
10 1 2 3 4 5 6 7 8 9 10

출력
7
3
2
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int t_case, coin_case;
    int cost, tmp, coinTmp, result;
    vector<int> coins, dp;

    cin >> t_case;
    while(t_case--){
        result = 0;
        cin >> cost;
        cin >> coin_case;
        
        for (int i = 1 ; i <= cost; i++) dp.push_back(i);
        for (int i = 0; i < coin_case; i++) {
            cin >> tmp;
            dp[tmp - 1] = 1;
            coins.push_back(tmp);
        }
        for (int j = 1; j <= cost; j++){
            for (int k = 1; k < j; k++) dp[j - 1] = min(dp[j - 1], dp[j - k - 1] + dp[k - 1]);
        }
        //for (int j = 0; j < cost; j ++) cout << "J  : " <<  j + 1 << " cost : " << dp[j] << endl;
        cout << dp[cost - 1] << endl;
        coins.clear();
        dp.clear();
    }
}

/* --------외부코드 ------------------------------
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int t_case, coin_case;
    int cost, tmp,*dp;
    vector<int> coins;

    cin >> t_case;
    while(t_case--){
        cin >> cost;
        cin >> coin_case;
        
        dp = new int[cost + 1];
        dp[0] = 0;
        for (int h = 1; h <= cost; h++) dp[h] = cost + 1;
        for (int i = 0; i < coin_case; i++) {
            cin >> tmp;
            coins.push_back(tmp);
        }
        for (int j = 0; j < coin_case; j++){
            for (int k = coins[j]; k <= cost; k++) dp[k] = min(dp[k], dp[k - coins[j]] + 1);
        }
        //for (int j = 0; j <= cost; j ++) cout << "J  : " <<  j << " cost : " << dp[j] << endl;
        cout << dp[cost] << endl;
        coins.clear();
    }
}
*/