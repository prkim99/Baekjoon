#include <iostream>
#include <vector>
using namespace std;
int d_info[15];
int m_info[15];
int dp[15];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int n, t, p;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> d_info[i] >> m_info[i];
	}


	dp[d_info[0] - 1] = m_info[0];
	for (int i = 1; i < n; i++)
	{
		dp[i + d_info[i] - 1] = max(dp[i + d_info[i] - 1], dp[i-1] + m_info[i]);
		dp[i] = max(dp[i], dp[i - 1]);
	}

	int profit = 0;
	for (int i = 0; i < n; i++)
	{
		if (dp[i] > profit) {
			profit = dp[i];
		}
	}
	cout << profit;
	return 0;
}