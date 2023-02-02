#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;
int a[4001];
int b[4001];
int c[4001];
int d[4001];
vector <int> ab;
vector <int> cd;

int main() {

	int n;
	cin >> n;
	//scanf("%d",&n);
	for (int j = 0; j < n; j++) {
		//scanf("%d %d %d %d", &a[j], &b[j], &c[j], &d[j]);
		cin >> a[j] >> b[j] >> c[j] >> d[j];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			ab.push_back(a[i] + b[j]);
			cd.push_back(c[i] + d[j]);
		}
	}
	sort(ab.begin(), ab.end());
	sort(cd.begin(), cd.end());
	long long int result = 0;
	long long int p1 = 0, p2 = n * n - 1, sum,i,j;
	while (p1 < n * n && p2 >= 0) {
		sum = ab[p1] + cd[p2];
		if (sum == 0) {
			//result++;
			i =j=1;
			while (p1+i<n*n&&ab[p1]==ab[p1+i]) {
				i++;
			}
			while (p2-j>=0&&cd[p2] == cd[p2 - j]) {
				j++;
			}
			result += i*j;
			p2-=j;
			p1+=i;

		}
		else if (sum > 0) {
			p2--;
		}
		else {
			p1++;
		}

	}
	cout << result;
	return 0;
}
