#include <iostream>
using namespace std;

int tri[130000];
int sum[130000];
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n,r,c,left, right;
	cin >> n;
	for (int i = 1; i <=n ; i++) {
		for (int j = 1; j <=i ; j++) {
			cin >> tri[(i)*(i-1)/2 + j];
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			if (j == 0) {
				sum[(i) * (i - 1) / 2 + j] = tri[(i) * (i - 1) / 2 + j] + sum[(i) * (i - 1) / 2 + j-i+1];
			}
			else if (j == i) {
				sum[(i) * (i - 1) / 2 + j] = tri[(i) * (i - 1) / 2 + j] + sum[(i) * (i - 1) / 2 + j - i];
			}
			else {
				left=sum[(i) * (i - 1) / 2 + j - i];
				right=sum[(i) * (i - 1) / 2 + j - i + 1];
				if (left > right) {
					right = left;
				}
				sum[(i) * (i - 1) / 2 + j] = tri[(i) * (i - 1) / 2 + j] +right;
			}
		}
	}
	int max = 0;
	for (int i = 1; i <= n; i++) {
		int val = sum[n * (n - 1) / 2 + i];
		if (val > max) {
			max = val;
		}
	}
	cout << max;
	return 0;
}
