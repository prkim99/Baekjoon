#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

vector<int> prime;
void setPrime() {
	prime.push_back(2);
	prime.push_back(3);
	int j;
	for (int i = 5; i <= 1000000; i+=2) {
		j = 1;
		int m = sqrt(i);
		while(prime[j]<=m) {
			if (i % prime[j] == 0) {
				break;
			}
			j++;
		}
		if (prime[j] > m) {
			prime.push_back(i);
		}
		
	}
}
bool isPrime(int num) {
	int s = 0;
	int e = prime.size()-1;
	int m = (s + e) / 2;

	while (s<=e) {
		if (prime[m] > num) {
			e = m - 1;
		}
		else if (prime[m] < num) {
			s = m + 1;
		}
		else {
			return true;
		}
		m= (s + e) / 2;
	}
	return false;
}
int main() {
	setPrime();
	int n,a,b,gap;
	scanf("%d",&n);
	while (n != 0) {
		int i;
		for (i = 0; i < prime.size(); i++) {
			gap = n - prime[i];
			if (isPrime(gap)) {
				break;
			}
		}
		a = prime[i];
		b = gap;
		printf("%d = %d + %d\n", n, a, b);
		scanf("%d", &n);
	}

	return 0;
}