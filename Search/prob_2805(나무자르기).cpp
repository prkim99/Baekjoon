#include<iostream>
using namespace std;
long long int tree[1000000];
int main() {
	int n;
	long long int m, max = 0;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> tree[i];
		if (max < tree[i]) {
			max = tree[i];
		}
	}

	long long int start = 0, end = max;
	long long int mid = start + (end - start) / 2;
	long long int i,cut;
	while (start<=end) {
		i = mid;
		long long int sum = 0;
		for (int j = 0; j < n; j++) {
			if (i >= tree[j])
				continue;
			sum += tree[j] - i;
		}
		if (sum == m) {
			cut = i;
			break;
		}
		else if (sum > m) {
			start = mid + 1;
			cut = i;
			}
		else {
			end = mid - 1;

		}
		mid = start + (end - start) / 2;
	}

	cout << cut;
	return 0;
}