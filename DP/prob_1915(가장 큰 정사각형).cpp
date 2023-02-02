#include <iostream>
#include <algorithm>
using namespace std;


int stair[1001][1001];
int dp[1001][1001];

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, m, val1, val2;
	string row;
	cin >> n>>m;
	for (int i =  1; i <= n; i++) {
		cin >> row;
		for (int j = 1; j <= m; j++) {
			stair[i][j] = row[j - 1] - '0';
		}
	}
	int maxVal = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			val1 = min(dp[i - 1][j], dp[i][j - 1]);
			val2 = min(dp[i - 1][j - 1],val1);
			if (stair[i][j] == 0) {
				dp[i][j] = 0;
			}
			else {
				dp[i][j] = val2 + 1;
			}
			if (maxVal < dp[i][j]) {
				maxVal = dp[i][j];
			}
		}
	}
	cout << maxVal*maxVal;
	return 0;
}
