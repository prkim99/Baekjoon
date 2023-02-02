#include <iostream>
using namespace std;


int mat[1025][1025];

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n,m,val;
	cin >> n>>m;
	for (int i =  1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> val;
			mat[i][j]=mat[i][j-1]+val;
}
	}
	int x1, y1, x2, y2;
	int t=0;
	while (t<m) {
		cin >> x1 >> y1 >> x2 >> y2;
		int total = 0;
		for (int i = x1; i <=x2 ; i++) {
			total += mat[i][y2] - mat[i][y1 - 1];
		}
		cout << total << "\n";
		t++;
	}
	return 0;
}
