#include<iostream>
using namespace std;

double fact(int n,int k) {
	double total = 1;
	if (k == 1) {
		return n;
	}
	for(int i=0;i<k;i++){
		total *= (n - i);
	}
	return total;
}
//int doll[51][51];
int doll[50];
int main() {
	int m, k;
	cin >> m;
	int total = 0;
	for (int i = 0; i < m; i++) {
		cin >> doll[i];
		total += doll[i];
	}
	cin >> k;
	double all = fact(total,k)/fact(k,k);
	double cs = 0;
	for (int i = 0; i < m; i++) {
		cs += fact(doll[i],k) /fact(k,k);
	}
	double result = cs/all;
	printf("%.15lf", cs/all);
	return 0;
}