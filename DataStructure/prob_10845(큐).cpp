#include<iostream>
#include<queue>
using namespace std;

queue <int> q;
int main() {
	int n, val;
	cin >> n;
	string input;
	for (int i = 0; i < n; i++) {
		cin >> input;
		if (input == "push") {
			cin >> val;
			q.push(val);
		}
		else if (input == "pop") {
			if (q.empty()) {
				cout << -1 << endl;
			}
			else {
				cout << q.front() << endl;
				q.pop();
			}
		}
		else if (input == "size"){
			cout<<q.size()<<endl;
		}
		else if (input == "empty") {
			if (q.empty()) {
				cout << 1 << endl;
			}
			else {
				cout << 0 << endl;
			}
		}
		else if (input == "front") {
			if (q.empty()) {
				cout << -1 << endl;
			}
			else {
				cout << q.front() << endl;
			}
		}
		else if (input == "back") {
			if (q.empty()) {
				cout << -1 << endl;
			}
			else {
				cout << q.back() << endl;
			}
		}
	}
	return 0;
}