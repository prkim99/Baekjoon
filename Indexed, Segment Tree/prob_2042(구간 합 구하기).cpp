#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
int e = 0,n;
long long int indexTree[1024 * 1024 * 2];
void swapp(int b,long long int c) {
	b += e-1;
	long long int gap = c - indexTree[b];
	for (int i = b; i >=1; i =i/2) {
		indexTree[i] +=gap;
	}
}
void sum(int b, int c) {
	b += e-1;
	c += e-1;
	long long int sum=0;
	while (b <= c) {
		if (b % 2 == 1)
			sum += indexTree[b];
		if (c % 2 == 0)
			sum += indexTree[c];
		b = (b + 1) / 2;
		c = (c - 1) / 2;
	}
	cout << sum<<endl;
}
int main() {
	int m,k;
	long long int a, b, c;
	scanf("%d %d %d", &n, &m, &k);
	int t = 0;

	while (t<n) {
		e++;
		t = 1<<e ;

	}
	e = 1 << e;
	for (int i = e; i < n+e; i++) {
		cin >> indexTree[i];
	}

	for (int i = e*2-1; i >1; i-=2) {
		indexTree[i / 2] = indexTree[i] + indexTree[i - 1];
	}
	for (int i = 0; i < m+k; i++) {
		cin >> a >> b >> c;
		if (a == 1) {
			swapp(b, c);
		}
		else if (a == 2) {
			sum(b, c);
		}
	}
	return 0;
}