#include <iostream>
using namespace std;


int prefix[200001];

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n,m,k,j,val;
	cin >> n>>m;
	for (int i =  1; i <= n; i++) {
		cin >> val;
		prefix[i] = prefix[i-1] + val;
	}

	for (int i = 0; i < m; i++) {
		cin >> k >> j;
		cout<<prefix[j] - prefix[k-1]<<"\n";
	}
	return 0;
}
