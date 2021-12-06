/*
KMP 알고리즘 (DFA)
주어진 문자열에서 특정한 패턴 문자열을 검색하는 문자열 검색 알고리즘 중에서 DFA(Deterministic
Finite Automata)를 이용한 KMP(Knuth-Morris-Pratt) 알고리즘을 구현하시오.
이 알고리즘에서 핵심은 패턴 문자열에 해당하는 DFA를 만드는 것이다. 예를 들어 패턴 문자열
ABABACA에 해당하는 DFA 상태 전이도(state transition graph)는 다음과 같다. 단, 이 DFA에서 다
루는 문자열은 문자 A, B, C로만 만들어 진다고 가정한다.
위의 DFA 전이도에서는 state 0, 1, …, 7에서 state 0로 전이(transition)하는 에지는 그려져 있지 않
으며, state 0로 전이하지 않는 에지는 총 13개가 있다.
패턴 문자열의 DFA전이도가 만들어 졌으면, 검색범위가 되는 텍스트 문자열은 위 상태전이도의 초
기상태(initial state)에서 시작하여 텍스트 문자열의 각 문자열에 따라 상태를 전이하여 최종적으로
종료상태(accept state) 에 도달하면 텍스트 문자열에서 패턴 문자열이 검색되었을 나타낸다. 예를
들어 텍스트 문자열 ABCABAABABABACACA 에서는 전이되는 상태는 아래와 같다.
0(초기상태) -> 1 -> 2 -> 0 -> 1 -> 2 -> 3 -> 1 -> 2 -> 3 -> 4 -> 5 -> 4 -> 5 -> 6 -> 7(종
료상태)
검색하고자 하는 패턴 문자열과 검색범위를 나타내는 텍스트 문자열이 주어졌을 때, 패턴 문자열의
DFA 상태 전이도를 만들고, 텍스트 문자열에 패턴 문자열이 몇 번 나타나는지를 계산하는 프로그램
을 작성하시오.

입력
입력은 표준입력(standard input)을 사용한다. 입력은 t 개의 테스트 케이스로 주어진다. 입력 파일의
첫 번째 줄에 테스트 케이스의 개수를 나타내는 정수 t 가 주어진다. 두 번째 줄부터 한 줄에 한 개의
테스트 케이스가 입력된다. 각 테스트 케이스에 해당되는 각 줄에는 패턴 문자열과 텍스트 문자열이
0 1 2 3 4 5 6 7 A B A B A C A
A
A
A
A
B B
Start
state
Accept
state
© Copyright 2021 by Joonsoo Choi. All Rights Reserved.
주어진다. 두 문자열의 최소 길이는 1이며 최대 길이는 1000이다. 두 문자열은 모두 영문자 대문자 A,
B, C로만 만들어 진다고 가정한다. 두 스트링 사이에는 한 개의 공백이 있으며, 잘못된 데이터가 입력
되는 경우는 없다.
출력
출력은 표준출력(standard output)을 사용한다. 입력되는 테스트 케이스의 순서대로 다음 줄에 이어
서 각 테스트 케이스의 결과를 출력한다. 각 테스트 케이스에 해당하는 출력의 첫 줄에 입력되는 패턴
문자열에 해당하는 DFA 상태 전이도를 만들었을 때, 상태 0으로 전이하지 않는 에지의 개수를 출력
하고, 그 다음으로 텍스트 문자열에 패턴 문자열이 몇 번 나타나는지를 출력한다.
입력과 출력의 예
입력
3
ABABACA ABCABAABABABACACA
AAAAA AAAAAAAAAA
ABCABCABC CBACBACBACBACBA
출력
13 1
6 6
16 0
*/
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int patterns = 4;
void constructDFA(int **, vector<int> *);
void changeInt(vector<int> *, string);
void DFAmatiching(int **, int, vector<int> *);

int main() {
    int t_case, patternLen, textLen;
    int **DFA;
    string pattern, text;
    cin >> t_case;

    while(t_case--){
        vector<int> patternVec, textVec;
        cin >> pattern >> text;
        //Char로 확인하기 어려우므로 0, 1, 2, 3으로 변환
        changeInt(&patternVec, pattern); changeInt(&textVec, text);
        patternLen = pattern.size(); textLen = text.size();
        DFA = new int*[patterns];
        for (int i = 0; i < patterns; i++) DFA[i] = new int[patternLen + 1];
        //DFA[pattern[0]] 번째 배열들을 모두 초기화
        for (int j = 0; j < patterns; j++) DFA[j][0] = 0;
        //DFA 배열 생성
        constructDFA(DFA, &patternVec);
        //string match
        DFAmatiching(DFA, patternLen, &textVec);
    }
}

void changeInt(vector<int> *vec, string st){
    vector<int> tmp;
    for (int j = 0; j < st.size(); j++){
        switch (st[j]){
            case 'A':
                tmp.push_back(0);
                break;
            case 'B':
                tmp.push_back(1);
                break;
            case 'C':
                tmp.push_back(2);
                break;
            default:
                tmp.push_back(3);
                break;
        }
    }

    for (int i = 0; i < tmp.size(); i++) vec->push_back(tmp[i]);
}

void constructDFA(int **DFA, vector<int> *pattern){
    DFA[pattern->at(0)][0] = 1;
    for (int X = 0 , j = 1; j <= pattern->size(); j++){
        for (int c = 0; c < patterns; c++) DFA[c][j] = DFA[c][X];
        if (j == pattern->size()) break;
        DFA[pattern->at(j)][j] = j + 1;
        X = DFA[pattern->at(j)][X];
    }
    // print DFA
    // for (int i = 0; i < patterns; i++){
    //     for (int j = 0; j <= pattern->size(); j++) cout << DFA[i][j] << " " ;
    //     cout << endl;
    // }
}

void DFAmatiching(int **DFA, int patternLen, vector<int> *text){
    int edgeCnt = 0, matchingCnt = 0;
    int i, j, textLen = text->size();

    //edge의 수 cnt
    for (int e = 0; e < patterns; e++){
        for (int k = 0; k <= patternLen; k++){
            if (DFA[e][k] > 0) edgeCnt += 1;
        }
    }
    for (i = 0, j = 0; i < textLen; i++){
        j = DFA[text->at(i)][j];
        if (j == patternLen){
            matchingCnt += 1;
        }
    }    
    cout << edgeCnt << " " << matchingCnt << endl;
}