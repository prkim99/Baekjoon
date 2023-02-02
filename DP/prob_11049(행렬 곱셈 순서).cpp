#include <iostream>
#include <climits>
using namespace std;

int mat[501];
int com[501][501];
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n,r,c;
	int i = 0;
	cin >> n;
	for (; i < n; i++) {
		cin >> r>>c;
		mat[i]=r;
	}
	mat[i] = c;
	int comp;
	for (int j = 1; j < n; j++) {
		for (int i = 1; j+i <= n; i++) {
			int comp,min=INT_MAX;
			int kk=j;
			for (int k = i; k < i + j;k++) {
				comp= com[i][k] + com[k + 1][i + j] + mat[i - 1] * mat[k] * mat[i + j];
				if (min > comp) {
					min = comp;
					kk = k;
				}
			}
			com[i][i + j] = min;
		}
	}
	cout << com[1][n];


	return 0;
}
