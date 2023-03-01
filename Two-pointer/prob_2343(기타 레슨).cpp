#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
int n, m;
int arr[100001];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int s, e = 0;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		e += arr[i];
	}
	s = *max_element(arr, arr + n);

	while (s < e) {
		int mid = (s + e) / 2;

		int sum = 0, cnt = 0;
		for (int i = 0; i < n; i++) {
			if (sum + arr[i] > mid) {
				sum = 0;
				cnt++;
			}
			sum += arr[i];
		}
		if (sum != 0) cnt++;

		if (cnt > m) {
			s = mid + 1;
		}
		else {
			e = mid;
		}
	}

	cout << s;
	return 0;
}
