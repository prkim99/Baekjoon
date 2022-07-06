//#include<iostream>
//using namespace std;
//
//int main() {
//	long long int n;
//	cin >> n;
//	long long int i = 1;
//	long long int before = 0, result = 1, temp = 0;
//	while (i < n) {
//		temp = result % 1000000;
//		result += before;
//		before = temp;
//		i++;
//	}
//	cout << result % 1000000;
//	return 0;
//}