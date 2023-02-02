#include <iostream>
#include<vector>
using namespace std;

int num[1000];
vector<int> prime;
int main() {
	int n, k;
	cin >> n >> k;
	int kk = 0,j=0,i;
	prime.push_back(2);
	for (i = 2; i <= n; i++) {
		if (num[i] == -1) {
			continue;
		}
		for (j = 1; j*i<=n; j++) {
			if (num[i*j] == 0) {
				kk++;
				num[i * j] = -1;
			}
			if (kk == k) {
				cout << i * j;
				return 0;
			}
		}
	}
}