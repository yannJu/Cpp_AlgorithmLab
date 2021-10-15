/*
Median 구하기
여러 개의 데이터가 주어졌을 때, 그 데이터들의 median(중앙값)을 구하는 프로그램을 작성하시오.
Median (중앙값)은 주어진 데이터를 오름차순으로 나열하였을 때, 가장 중앙에 위치하는 데이터이
다. 즉, 주어진 정수의 개수가 홀수일 경우에는 오름차순으로 나열하였을 떄 가장 중앙에 있는 정수
이며, 주어진 정수의 개수가 짝수일 경우에는 오름차순으로 나열하였을 떄 가장 중앙에 있는 두 개
의 정수의 평균값을 나타낸다.
예를 들어, 다음과 5 개의 정수가 주어졌을 때
4 7 10 9 8 -> 오름차순으로 나열 -> 4 7 8 9 10
median 은 8 이며, 다음과 같이 6 개의 정수가 주어졌을 떄
4 7 10 9 8 1 -> 오름차순으로 나열 -> 1 4 7 8 9 10
median 은 중앙에 위치한 두 개의 정수 7 와 8 의 평균값인 7.5 이다. (본 문제에서는 두 정수의 평
균값은 소수점이하를 버린 정수값으로 한다. 따라서, 7.5 의 경우에는 정수 7 을 평균값으로 한다.)
어떤 상황에서 데이터가 순차적으로 생성되는 경우에 새로운 데이터가 한 개씩 생성될 때마다 어떤
계산을 수행하는 것을 on-line 작업이라고 한다. On-line 작업 중에서 처음 생성된 정수부터 지금까
지 생성된 정수의 median 을 계산하는 프로그램을 작성하시오. (일반적으로는 on-line 작업에서는
데이터가 무한히 생성된다라고 가정하지만, 본 문제에서는 median 을 계산하기위해서는 생성되는
모든 정수를 기록하고 있어야 하므로, 생성되는 정수의 개수는 제한적이라고 가정한다.)
다음 그림은 정수가 새로 생성될 때마다 처음 생성된 정수부터 방금 생성된 정수까지의 median 을
구하는 예이다.
4 7 10 9 8 1 3 2 1 2 4 2 1 ┅
4
처음 생성된 정수부터 지금까지
생성된 정수들의 median
5 7 8 8 7 3
data stream
위 그림에서 계산되는 median 은 아래와 같다.
4 5 7 8 8 7 7 5 4 3 4 3 3
© Copyright 2021 by Joonsoo Choi. All Rights Reserved.
이 median 을 모두 더한 정수는 4+5+7+8+8+7+7+5+4+3+4+3+3 = 68 이며, 68 의 마지막 자
리수는 8 이다.
입력
입력은 표준입력(standard input)을 사용한다. 입력은 t 개의 테스트 케이스로 주어진다. 입력 파일
의 첫 번째 줄에 테스트 케이스의 개수를 나타내는 정수 t 가 주어진다. 두 번째 줄부터 t 개의 줄에
는 한 줄에 한 개의 테스트 케이스에 해당하는 정수들이 주어진다. 각 테스트 케이스에 해당되는 각
줄의 첫 번째 정수 n (1 ≤ n ≤ 100,000) 은 생성될 정수의 개수를 나타낸다. 그 다음에는 n 개의
생성된 정수가 주어지는데, 각 정수의 최소값은 1 이며 최대값은 230
-1 이다. 같은 줄에 나열되는 각
정수들 사이에는 한 개의 공백이 있으며, 잘못된 데이터가 입력되는 경우는 없다.
출력
출력은 표준출력(standard output)을 사용한다. 입력되는 테스트 케이스의 순서대로 다음 줄에 이어
서 각 테스트 케이스의 결과를 출력한다. 각 테스트 케이스에 해당하는 출력의 첫 줄에 입력되는 n
개의 정수가 처음 생성될 때부터 마지막 정수가 생성될 때까지 매번 새로운 자연수가 생성될 때마다,
처음 생성된 정수부터 지금 생성된 정수까지의 모든 정수들의 median 을 모두 더한 정수의 마지막
자리수를 출력한다.
입력과 출력의 예
입력 출력
4
6 4 7 10 9 8 1
13 4 7 10 9 8 1 3 2 1 2 4 2 1
10 1 2 3 4 5 6 7 8 9 10
10 10 9 8 7 6 5 4 3 2 1
9
8
0
5
*/

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main(){
    int t_case, len, tmp;
    long long answer;
    priority_queue<int, vector<int>, greater<int> > High;
    priority_queue<int> Low;

    cin >> t_case;
    while(t_case--){
        cin >> len;
        answer = 0;
        while(len--){
            cin >> tmp;
            if (Low.size() == 0 && High.size() == 0) Low.push(tmp);
            else {
                if (Low.top() < tmp) High.push(tmp);
                else Low.push(tmp);
            }
            if (Low.size() < High.size()) {
                Low.push(High.top());
                High.pop();
            }
            else if (Low.size() > High.size() + 1){
                High.push(Low.top());
                Low.pop();
            }
            if (Low.size() == High.size()) answer += ((Low.top() + High.top())/2);
            else answer += Low.top();
            //cout << "answer : " << answer << endl;
            //cout << "L : " << Low.size() << " H : " << High.size() << endl;
        }
        cout << answer % 10 << endl;
        while(Low.size() > 0) Low.pop();
        while(High.size() > 0) High.pop();
    }
}