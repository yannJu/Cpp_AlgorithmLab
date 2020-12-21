#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
using namespace std;

int row, col;
char map[100][100];
int tf[100][100];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

int dfs(int x, int y, int cnt) {

	tf[x][y] = 1;

	for (int k = 1; k <= 4; k++) {
		int nx, ny;
		nx = x + dx[k-1];
		ny = y + dy[k-1];
		if (nx >= 0 && nx < row && ny >= 0 && ny < col) {
			if (map[nx][ny] == '.' && tf[nx][ny] == 0) {
				cnt = dfs(nx, ny, cnt + 1);
			}
		}
	}
	return cnt;
}

int main() {
	char p[100];
	int c_Num;
	
	cin >> c_Num;
	while(c_Num--){
		//n*n 지도 입력
		cin >> col >> row;
		for (int i = 0; i < row; i++) {
			cin >> p;
			for (int j = 0; j < col; j++) {
				map[i][j] = p[j];
			}
		}

		vector<int> ans;
		//모든 요소를 돌며 1인 곳에서부터 DFS 시작
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				if (map[i][j] == '.' && tf[i][j] == 0) {
					ans.push_back(dfs(i, j, 1));
				}
			}
		}

		//ans 오름차순 정리
		sort(ans.begin(), ans.end());

		cout << ans.size() << "\n";
		for (int i = ans.size() - 1; i >= 0; i--){
			cout << ans[i] << " ";
		}
		cout << endl;
		for (int i = 0; i < row; i++){
			for (int j = 0; j < col; j++){
				map[i][j] =0; tf[i][j] = 0;
			}
		}
	}
	return 0;
}
