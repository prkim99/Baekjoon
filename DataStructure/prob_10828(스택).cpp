#include<iostream>
#include<stack>
using namespace std;

stack<int> s;
int main() {
	int n,val;
	cin >> n;
	string input;
	for (int i = 0; i < n; i++) {
		cin >> input;
		if (input == "push") {
			cin >> val;
			s.push(val);
		}
		else if (input == "pop") {
			if (s.empty()) {
				cout << -1 << endl;
			}
			else {
				cout << s.top()<<endl;
				s.pop();
			}
		}
		else if (input == "size") {
			cout << s.size() << endl;
		}
		else if (input == "empty") {
			if (s.empty()) {
				cout << 1 << endl;
			}
			else {
				cout << 0 << endl;
			}
		}
		else if (input == "top") {
			if (s.empty()) {
				cout << -1 << endl;
			}
			else {
				cout << s.top() << endl;
			}
		}
	}
	return 0;
}