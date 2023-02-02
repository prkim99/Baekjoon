#include<iostream>
#include<queue>
using namespace std;

int board[51][51];
bool visit[51][51];
int range[51][51];
int ud[] = { 1,-1,0,0 };
int lr[] = { 0,0,1,-1 };
int n, m;

int dfs(int i,int j) {
	int result = 0;
	int now = board[i][j];
	visit[i][j] = true;
	for (int k = 0; k < 4; k++) {
		int ii = i + now * ud[k];
		int jj = j + now * lr[k];
		if (n > ii && ii >= 0 && m > jj && jj >= 0&&board[ii][jj] != 'H' - '0') {
			if (visit[ii][jj] == false) {
				int a;
				if (range[ii][jj] != 0) {
					a= range[ii][jj];
				}
				else {
					a = dfs(ii, jj);
				}
				if (a == -1) {
					return -1;
				}
				if (result < a) {
					result = a;
				}
			}
			else {
				return -1;
			}
		}
	}
	range[i][j] = result+1;
	visit[i][j] = false;
	return result+1;
}

int main() {
	cin >> n >> m;
	string row;
	for (int i = 0; i < n; i++) {
		cin >> row;
		for (int j = 0; j < m; j++) {
			board[i][j] = row[j] - '0';
		}
	}
	cout<<dfs(0,0);
	

	return 0;
}