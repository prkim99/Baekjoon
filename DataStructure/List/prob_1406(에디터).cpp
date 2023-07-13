#include<iostream>
#include<list>
using namespace std;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	list<char> l;
	string str;
	cin >> str;
	int n;
	cin >> n;
	auto p = l.begin();
	for (int i = 0; i < str.length(); i++) {
		l.insert(p,str[i]);
	}
	for (int i = 0; i < n; i++) {
		char in;
		cin >> in;
		if ('L' == in) {
			if (p != l.begin()) {
				p--;
			}
		}
		else if ('D' == in) {
			if (p != l.end()) {
				p++;
			}
		}
		else if ('B' == in) {
			if (p != l.begin()) {
				p--;
				p = l.erase(p);
			}
		}
		else {
			cin >> in;
			l.insert(p, in);
		}
	}
	for (auto v : l) {
		cout << v;
	}

	return 0;
}
