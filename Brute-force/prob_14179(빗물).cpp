#include<iostream>
#include<map>
#include<cstring>
#include<cmath>
#include <vector>
#include <queue>
#include<algorithm>
#include <stack>

using namespace std;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int h, w;
	cin >> h >> w;
	int block[501];

	for (int i = 0; i < w; i++) {
		cin >> block[i];
	}
	
	int s = 0;
	int sh = block[0];
	int blockL[501];
	blockL[0] = 0;
	for (int i = 1; i < w; i++) {
		blockL[i] = sh;
		if (block[i] > sh) {
			sh = block[i];
		}
	}
	
	int th = block[w - 1];
	int total = 0;
	for (int i = w - 2; i >= 0; i--) {
		int low = min(blockL[i], th);
		if (low - block[i] > 0) {
			total += low - block[i];
		}

		if (th < block[i]) {
			th = block[i];
		}
	}
	cout << total;
	return 0;
}
