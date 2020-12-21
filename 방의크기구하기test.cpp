#include <iostream>
#include <algorithm>
using namespace std;

int **map = NULL, **tf = NULL, *room = NULL;
int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
int cnt, row, col;

int** makeArray(int* sz);
void Solution(int row, int col);
void dfs(int row, int col);

int main(){
	int c_Num;
	int *sz;
	char p[100];

	cin >> c_Num;
	while(c_Num--){
		sz = new int[2];
		cnt = 0;
		int temp = 0;

		cin >> col >> row;
		int roomsz = col * row;
		room = new int [roomsz];
		sz[0] = row; sz[1] = col;
		map = makeArray(sz); //맵 생성
		tf = makeArray(sz); //tf맵 생성

		for (int i0 = 0; i0 < row; i0++){
			cin >> p;
			for (int i1 = 0; i1 < col; i1++){
				if (p[i1] == '+') {
					map[i0][i1] = 1;
				}
				else if (p[i1] == '.') {
					map[i0][i1] = 0;
				}
			}
		} //맵초기화 & tf맵 초기화
		for (int i = 0; i < row; i++){
				for (int j = 0; j < col; j++){
					if (map[i][j] == 0) {
						dfs(i, j), cnt++;
					}
				}
		}
		sort(room, room + cnt);

		for (int i = 1; i <= cnt; i++){
			if (room[i] >= 1) temp += 1;
		}
		cout << temp << endl;
		for (int i = cnt; i > 0; i--){
			if (room[i] >= 1) cout << room[i] << " ";
		}
		cout << endl; //출력
	}
	
}
int** makeArray(int* sz){
	int n1 = sz[0], n2 = sz[1];
	int **arr = new int *[n1];
	for (int i = 0; i < n1; i++){
		arr[i] = new int [n2];
	}
	return arr;
}//배열생성

/*
void Solution(int r, int c){
	for (int i = 0; i < r; i++){
		for (int j = 0; j < c; j++){
			if (map[i][j] == 0) {
				dfs(i, j), cnt++;
			}
		}
	}
} //map이 '.' 인 경우에만 dfs실행
*/
void dfs(int r, int c){
	if(!tf[r][c]) room[cnt]++;
	tf[r][c] = 1;

	int dx, dy;

	for (int i = 0; i < 4; i++){
		dx = c + dir[i][0];
		dy = r + dir[i][1];
		if (0 <= dx && dx < col && 0 <= dy && dy < row) {
			if(tf[dy][dx] == 0 & map[dy][dx] == 0) dfs(dy, dx);
		}
	}
}
