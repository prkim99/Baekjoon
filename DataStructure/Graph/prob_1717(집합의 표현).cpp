#include<iostream>
#include <vector>
using namespace std;
int parent[1000001];

int find(int a) {
	if (parent[a] == a)
		return a;
	else {
		parent[a] = find(parent[a]);
	}
	return parent[a];
}
void uni(int a, int b) {
	int pa = find(a);
	int pb = find(b);
	parent[pa] = pb;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, m, op, val1, val2;
	cin >> n >>  m;
	for (int i = 0; i <= n; i++) {
		parent[i] = i;
	}
	for (int i = 0; i < m; i++) {
		cin >> op>>val1>>val2;
		if (op == 1) {
			if (find(val1)==find(val2)) {
				cout << "YES\n";
			}
			else {
				cout << "NO\n";
			}
		}
		else {
			uni(val1, val2);
		}
	}
	return 0;
}