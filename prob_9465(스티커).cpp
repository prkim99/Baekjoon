#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
int dpt[2][100000];

int dp(vector<int> v1, vector<int> v2) {
	memset(dpt, 0, sizeof(dpt));
	dpt[0][0] = v1[0];
	dpt[1][0] = v2[0];
	if (v1.size() > 1) {
		dpt[0][1] = v1[1]+dpt[1][0];
		dpt[1][1] = v2[1]+dpt[0][0];
		for (int i = 2; i < v1.size(); i++) {
			dpt[0][i] = v1[i] + max(dpt[1][i - 1], dpt[1][i - 2]);
			dpt[1][i] = v2[i] + max(dpt[0][i - 1] , dpt[0][i - 2]);
		}
	}
	int n = v1.size();
	int maxVal = max(dpt[0][n - 2], dpt[0][n - 1]);
	maxVal = max(maxVal, dpt[1][n - 2]);
	maxVal = max(maxVal, dpt[1][n - 1]);
	return maxVal;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t;
	int tt = 0;
	cin >> t;
	while (t > tt) {
		int n;
		cin >> n;
		vector<int> v1;
		vector<int>v2;
		int val;
		for (int i = 0; i < n; i++) {
			cin >> val;
			v1.push_back(val);
		}
		for (int i = 0; i < n; i++) {
			cin >> val;
			v2.push_back(val);
		}
		cout << dp(v1, v2) << "\n";
		tt++;
	}

	return 0;
}
