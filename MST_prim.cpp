/*
Minimum Spanning Tree (Prim’s Algorithm)
Connected, Weighted, Undirected 그래프 G가 주어졌을 때, 이 그래프의 minimum spanning
tree(MST)를 구하는 Prim의 알고리즘을 구현하시오.
예를 들어, 10개의 노드와 가중치를 가지는 19개의 에지로 구성된 아래 그래프 G의 MST T는 다음과
같다.
위의 그래프에서 9개의 에지로 구성된 MST T의 에지의 가중치의 총합은 37이다.


입력
입력은 표준입력(standard input)을 사용한다. 입력은 t 개의 테스트 케이스로 주어진다. 입력 파일의
첫 번째 줄에 테스트 케이스의 개수를 나타내는 정수 t 가 주어진다. 두 번째 줄부터 테스트 케이스가
입력된다. 각 테스트 케이스에 해당되는 각 줄에는 그래프의 노드의 개수를 나타내는 정수 𝑛𝑛 (3 ≤
𝑛𝑛 ≤ 1000) 이 주어진다. 그 다음 n 개의 줄에는 한 줄에 하나의 노드 𝑘𝑘 (1 ≤ 𝑘𝑘 ≤ 𝑛𝑛) 에 인접한 노드와
번호와 그 노드에 연결된 에지의 가중치가 주어진다. 각 줄에는 먼저 노드 번호 𝑘𝑘 (1 ≤ 𝑘𝑘 ≤ 𝑛𝑛) 가 주어
지고, 그 다음에는 노드 k에 인접한 노드들의 개수 𝑚𝑚 (1 ≤ 𝑚𝑚 ≤ 𝑛𝑛 − 1) 이 주어진다. 그 다음에는 2m
개의 정수 𝑣𝑣1 𝑤𝑤1 𝑣𝑣2 𝑤𝑤2 ⋯ 𝑣𝑣𝑚𝑚 𝑤𝑤𝑚𝑚 가 주어지는데, 𝑣𝑣1, 𝑣𝑣2 , ⋯ , 𝑣𝑣𝑚𝑚 은 노드 k에 인접한 노드들의 번호이고
𝑤𝑤1, 𝑤𝑤2 , ⋯ , 𝑤𝑤𝑚𝑚 은 해당 노드와 연결된 에지의 가중치를 나타낸다. 가중치의 최대는 100이며 최소는 1
이다. 각 정수들 사이에는 한 개의 공백이 있으며, 잘못된 데이터가 입력되는 경우는 없다.
© Copyright 2021 by Joonsoo Choi. All Rights Reserved.
출력
출력은 표준출력(standard output)을 사용한다. 입력되는 테스트 케이스의 순서대로 다음 줄에 이어
서 각 테스트 케이스의 결과를 출력한다. 각 테스트 케이스에 해당하는 출력의 첫 줄에 입력되는 그래
프의 MST의 에지의 총합을 나타내는 정수를 출력한다.
입력과 출력의 예
입력
3
10
1 3 2 9 3 8 4 5
2 3 1 9 5 7 6 9
3 5 1 8 4 3 5 2 7 3 8 5
4 3 1 5 3 3 8 7
5 4 2 7 3 2 6 5 7 4
6 5 2 9 5 5 7 6 9 9 10 8
7 5 3 3 5 4 6 6 8 4 9 7
8 4 3 5 4 7 7 4 9 4
9 4 6 9 7 7 8 4 10 3
10 2 6 8 9 3
5
1 3 2 1 4 8 5 5
2 2 1 1 3 6
3 1 2 6
4 1 1 8
5 1 1 5
5
1 4 2 20 3 12 4 12 5 8
2 3 1 20 3 17 4 5
3 3 1 12 2 17 5 6
4 3 1 12 2 5 5 5
5 3 1 8 3 6 4 5
출력
36
20
24
*/

#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;


vector<int> keys;
void Prim(vector<vector<int> > *, vector<int> *, int);

int isFind(vector<pair<int, int> > v, int idx) {
    for (int i = 0; i < v.size(); i++) {
        if (v[i].first == idx) return i;
    }
    return -1;
}
bool compare(pair<int, int> a, pair<int, int> b)  {return a.second < b.second;}

int main(){
    int t_case, nodeCase;

    cin >> t_case; //TestCase 수 (ex : 3)
    while(t_case--){
        vector<vector<int> > G;
    
        cin >> nodeCase; //Node 수 (ex : 10)
        keys.assign(nodeCase, INT_MAX);
        //-------------------------------Create Graph
        for (int i = 0; i < nodeCase; i++){
            vector<int> v;
            int n, tmp;
            cin >> n >> tmp; //Node, 와 인접한 Node 수 (ex : 1, 3)
            v.assign(nodeCase, -1); //인접하지 않으면 -1로 표기되도록 초기화
            v[i] = 0; //자기자신은 0
            while(tmp--) {
                int ajN, weight;
                cin >> ajN >> weight;
                v[ajN - 1] = weight;
            }
            G.push_back(v);
        }
        //----------------------------------------------
        Prim(&G, &keys, 0);
    }
}

void Prim(vector<vector<int> > * g, vector<int> *k, int r){
    vector<int> keys = *k; //ck벡터와 key값을 가지고 있는 벡터
    vector<vector<int> > G = *g; //그래프 벡터(인접벡터)
    vector<pair<int, int> > ckV;
    int sum = 0, cnt = 0;

    keys[r] = 0; //r 제외 INT_MAX
    for (int i = 0; i < keys.size(); i++) ckV.push_back(make_pair(i, keys[i]));

    while(!ckV.empty()){
        sort(ckV.begin(), ckV.end(), compare);
        pair<int, int> u = ckV[0]; //Extract_min
        ckV.erase(ckV.begin());
        vector<int> tmp = G[u.first];
        for (int i = 0; i < tmp.size(); i++){
            //자기 자신이 아니며 & w(u, v) (= tmp[i]) < v.key (= keys[i]) & Q에 속해있는 경우
            if ((tmp[i] > 0) and (tmp[i] < keys[i]))  {
                int idx = isFind(ckV, i);
                if (idx >= 0) {
                    keys[i] = tmp[i]; //key값을 변경
                    ckV[idx] = make_pair(ckV[idx].first, tmp[i]);
                }
            }
        }
    }
    for (int k = 0; k < keys.size(); k++) sum += keys[k]; 
    cout << sum << endl;
    keys.clear();
}