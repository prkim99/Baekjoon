#include <iostream>
#include <algorithm>
using namespace std;
int dp[101][100001];

int main() {


	int N, K, i = 1;
	cin >> N >> K;
	int* W = new int[K + 1];
	int* V = new int[N + 1];

	while (i < N + 1) {
		cin >> W[i] >> V[i];
		i++;
	}
	for (int i = 0; i <= N; i++) {
		dp[i][0] = 0;
	}
	for (int j = 0; j <= K; j++) {
		dp[0][j] = 0;
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= K; j++) {
			if (j >= W[i]) {
				dp[i][j] = max(dp[i - 1][j], V[i] + dp[i - 1][j - W[i]]);
			}
			else {
				dp[i][j] = dp[i - 1][j];
			}
		}
	}
	cout << dp[N][K] << endl;

	return 0;
}