#include<iostream>
#include <queue>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, i=0;
	cin >> N;
	int num;
	priority_queue<int> left;
	priority_queue<int,vector<int>,greater<int>> right;
	while (i<N)
	{
		cin >> num;
		if(left.size() <= right.size()) {
			left.push(num);
		}
		else {
			right.push(num);
		}
		if (!left.empty() && !right.empty()) {
			if (left.top() > right.top()) {
				int temp = right.top();
				int temp2 = left.top();
				left.pop();
				right.pop();
				left.push(temp2);
				right.push(temp);
			}
		}
		cout << left.top() << '\n';
		i++;
	}
	return 0;
}