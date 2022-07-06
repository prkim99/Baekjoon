#include<iostream>
#include <vector>
#include<stack>
#include<cmath>
using namespace std;

int main() {
	int n, t = 0;
	long long int val;
	string input,in;
	while (true) {
		vector<string> inst;
		vector<long long int> num;
		vector<long long int> inp;
		input = " ";
		while (input != "END") {
			cin >> input;
			inst.push_back(input);
				if (input == "QUIT") {
					return 0;
				}
			if (input == "NUM") {
				cin >> val;
				num.push_back(val);
			}
		}
		t = 0;
		cin >> n;
		while (t < n) {
			cin >> val;
			inp.push_back(val);
			t++;
		}
		int k = 0, l = 0;
		long long int val2 = 0;
		bool flag=false;
		while (k < n) {
			t = 0;
			l = 0;
			stack<long long int> s;
			s.push(inp[k]);
			while (t < inst.size()) {
				if (inst[t] == "NUM") {
					s.push(num[l]);
					l++;
					if (abs(s.top()) > 1000000000) {
						flag = true;
						break;
					}
				}

				else if (inst[t] == "POP") {
					if (s.empty()) {
						flag = true;
						break;
					}
					s.pop();
				}
				else if (inst[t] == "INV") {
					if (s.empty()) {
						flag = true;
						break;
					}
					val = -(s.top());
					s.pop();
					s.push(val);
					if (abs(s.top()) > 1000000000) {
						flag = true;
						break;
					}
				}
				else if (inst[t] == "DUP") {
					if (s.empty()) {
						flag = true;
						break;
					}
					s.push(s.top());

				}
				else if (inst[t] == "SWP") {
					if (s.size() < 2) {
						flag = true;
						break;
					}
					val = s.top();
					s.pop();
					val2 = s.top();
					s.pop();
					s.push(val);
					s.push(val2);
					if (abs(s.top()) > 1000000000) {
						flag = true;
						break;
					}
				}
				else if (inst[t] == "ADD") {
					if (s.size() < 2) {
						flag = true;
						break;
					}
					val = s.top();
					s.pop();
					val2 = s.top();
					s.pop();
					s.push(val + val2);
					if (abs(s.top()) > 1000000000) {
						flag = true;
						break;
					}
				}
				else if (inst[t] == "SUB") {
					if (s.size() < 2) {
						flag = true;
						break;
					}
					val = s.top();
					s.pop();
					val2 = s.top();
					s.pop();
					s.push(val2 - val);
					if (abs(s.top()) > 1000000000) {
						flag = true;
						break;
					}
				}
				else if (inst[t] == "MUL") {
					if (s.size() < 2) {
						flag = true;
						break;
					}
					val = s.top();
					s.pop();
					val2 = s.top();
					s.pop();
					s.push(val * val2);
					if (abs(s.top()) > 1000000000) {
						flag = true;
						break;
					}
				}
				else if (inst[t] == "DIV") {
					if (s.size() < 2) {
						flag = true;
						break;
					}
					val = s.top();
					s.pop();
					val2 = s.top();
					s.pop();
					if (val == 0) {
						flag = true;
						break;
					}
					s.push(val2 / val);
					if (abs(s.top()) > 1000000000) {
						flag = true;
						break;
					}

				}
				else if (inst[t] == "MOD") {
					if (s.size() < 2) {
						flag = true;
						break;
					}
					val = s.top();
					s.pop();
					val2 = s.top();
					s.pop();
					if (val == 0) {
						flag = true;
						break;
					}
					s.push(val2 % val);
					if (abs(s.top()) > 1000000000) {
						flag = true;
						break;
					}
				}

				t++;
			}

			if (s.size() != 1 || flag) {
				cout << "ERROR"<<endl;
				flag = false;
			}
			else {
			
					cout << s.top() << endl;
			
			}

			k++;
		}
		cout << endl;
	}

	return 0;
}