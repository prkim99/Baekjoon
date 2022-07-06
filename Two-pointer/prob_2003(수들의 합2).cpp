#include<iostream>
using namespace std;

int a[10000];

int main() {
	int n, m;
	cin >> n>>m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int result = 0;
	for (int i = 0; i < n; i++) {
		int sum = 0;
		for (int j = i; j < n; j++) {
			sum += a[j];
			if (sum == m) {
				result++;
				break;
			}
		}
	}

	cout << result;
	return 0;
}