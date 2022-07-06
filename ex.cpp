#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<queue>
#include<vector>
using namespace std;

char map[100][100];

int n, m;

int dx[] = { 0,0,1,-1 };
int dy[] = { -1,1,0,0 };
int result_time=0, result_time1=0;
int mx, my,sx,sy;
char fin;

int caltime(int start_x, int start_y) {
	char trace[100][100] = { 0, };
	int time = 1;
	queue<pair<int, int>> move;
	move.push(pair<int, int>(start_x, start_y));
	trace[start_x][ start_y] = 's';
	while (!move.empty()) {
		int len = move.size();
		for (int z = 0; z < len; z++) {
			int x = move.front().first;
			int y = move.front().second;
			move.pop();

			for (int i = 0; i < 4; i++) {
				mx = x + dx[i];
				my = y + dy[i];

				if (mx >= 0 && mx < n && my >= 0 && my < m && map[mx][my] != 'X' && trace[mx][my] == 0) {
					trace[mx][my] = time;
					if (map[mx][my] == 'A') {
						map[mx][my] = '.';
						fin='A';
						return time;
					}
					else if (map[mx][my] == 'B') {
						map[mx][my] = '.';
						fin = 'B';
						return time;
					}else if (map[mx][my] == 'C') {
						map[mx][my] = '.';
						fin = 'C';
						return time;
					}
					else {
						move.push(pair<int, int>(mx, my));
					}

				}
			}
		}
		time++;
	}
}

int caltimeA(int start_x, int start_y) {
	char trace[100][100] = { 0, };
	int time = 1;
	queue<pair<int, int>> move;
	move.push(pair<int, int>(start_x, start_y));
	trace[start_x][start_y] = 's';
	while (!move.empty()) {
		int len = move.size();
		for (int z = 0; z < len; z++) {
			int x = move.front().first;
			int y = move.front().second;
			move.pop();

			for (int i = 0; i < 4; i++) {
				mx = x + dx[i];
				my = y + dy[i];

				if (mx >= 0 && mx < n && my >= 0 && my < m && map[mx][my] != 'X' && trace[mx][my] == 0) {
					trace[mx][my] = 1;
					if (map[mx][my] == 'B') {
						map[mx][my] = '.';
						fin = 'B';
						return time;
					}
					else if (map[mx][my] == 'C') {
						map[mx][my] = '.';
						fin = 'C';
						return time;
					}
					else {
						move.push(pair<int, int>(mx, my));
					}

				}
			}
		}
		time++;
	}
}
int main() {

	freopen("input_ex.txt", "r", stdin);
		ios::sync_with_stdio(false);
		cin.tie(NULL);

	int t, tt=0, r,k;
	cin >> t;
	string a;
	while (tt < t) {
		int ax, ay, bx, by, cx, cy;
		cin >> n >> m >> r >> k;
		for (int i = 0; i < n; i++) {
			cin >> a;
			for (int j = 0; j < m; j++) {
				map[i][j]=a[j];
				if (a[j] == 'S') {
					sx = i;
					sy = j;
				}
				else if (a[j] == 'A') {
					ax = i;
					ay = j;
				}
				else if (a[j] == 'B') {
					bx = i;
					by = j;
				}

				else if (a[j] == 'C') {
					cx = i;
					cy = j;
				}
			}
		}
		mx = r - 1;
		my = k - 1;
		for(int i=0;i<3;i++){
			result_time += caltime(mx, my);
		}
		result_time += (abs(mx - sx) + abs(my - sy));


		for (int i = 0; i < 3; i++) {
			result_time1 += caltime(mx, my);
		}
		tt++;
		cout <<"#"<<tt <<" " << result_time<<"\n";
		result_time = 0;
	}
	return 0;
}