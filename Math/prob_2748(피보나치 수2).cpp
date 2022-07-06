#include<iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	int i = 1;
	long long int before = 0, result = 1, temp = 0;
	while (i < n) {
		temp = result;
		result += before;
		before = temp;
		i++;
	}
	cout << result;
	return 0;
}