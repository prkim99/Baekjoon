#include<iostream>
using namespace std;

int fact(int n) {
	if (n <= 1)return 1;
	return n * fact(n - 1);
}
int main() {
	int n, k;
	cin >> n >> k;
	cout << fact(n) /( fact(n - k)*fact(k));
	return 0;
}