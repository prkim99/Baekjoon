#include<iostream>
#include<vector>
#include <cstring>
#include<queue>
#include<stack>
#include <algorithm>
using namespace std;
int nn;
int dp[501][501] = { 0, };
int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };
vector<vector<int>> v;
int maxV = 0;
bool isPos(int i, int j) {
	if (i < 0 || j < 0 || i >= nn || j >= nn) {
		return false;
	}
	return true;
}
int dfs(int i, int j) {
	if (dp[i][j] > 0) {
		return dp[i][j];
	}
	dp[i][j] = 1;
	for (int l = 0; l < 4; l++) {
		int di = i + dx[l];
		int dj = j + dy[l];
		if (isPos(di, dj)) {
			if (v[i][j] < v[di][dj] ) {
				dp[i][j] = max(dfs(di,dj)+1, dp[i][j]);
				if (maxV < dp[i][j]) {
					maxV = dp[i][j];
				}
			}
		}
	}
	return dp[i][j];
}
int solve() {
	int result;

	nn = v.size();
	for (int i = 0; i < nn; i++) {
		for (int j = 0; j < nn; j++) {
			maxV = max(dfs(i, j), maxV);
		}
	}

	result = maxV;
	return result;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n;
	cin >> n;

	int val;
	for (int i = 0; i < n; i++) {
		vector<int> vv;
		for (int j = 0; j < n; j++) {
			cin >> val;
			vv.push_back(val);
		}
		v.push_back(vv);
		vv.clear();
	}

	cout << solve();


	return 0;
}
