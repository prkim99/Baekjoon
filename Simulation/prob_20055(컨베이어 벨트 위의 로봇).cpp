#include<iostream>
#include<map>
#include<cstring>
#include<cmath>
#include <vector>
#include <queue>
#include<algorithm>
#include <stack>]
#include <deque>
using namespace std;


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, k;
	cin >> n >> k;
	int belt[201]={0,};
	int cnt = 0;
	for (int i = 0; i < 2 * n; i++) {
		cin >> belt[i];
		if (belt[i] == 0) {
			cnt++;
		}
	}

	int s = 0;
	int e = n-1;
	deque<int>robot;
	int stage = 0;
	while (cnt < k) {
		s--;
		if (s == -1) s = 2 * n - 1;
		e--;
		if (e == -1) e = 2 * n - 1;

		if (!robot.empty()&&robot[0] == e) {
			robot.pop_front();
		}

		for (int i = 0; i < robot.size();i++) {
			int loc = robot[i];
			if (loc == (2 * n - 1)) {
				if (belt[0] > 0) {
					if (i == 0 || robot[i - 1] != 0) {
						robot[i] = 0;
						belt[0]--;
						if (belt[0] == 0) cnt++;
					}
				}
			}
			else {
				if (belt[loc + 1] > 0) {
					if (i == 0 || robot[i - 1] != loc + 1) {
						robot[i] = loc + 1;
						belt[loc + 1]--;
						if (belt[loc + 1] == 0) cnt++;
					}
				}
			}
		}
		if (!robot.empty() && robot[0] == e) {
			robot.pop_front();
		}
		if (belt[s] > 0) {
			robot.push_back(s);
			belt[s]--;
			if (belt[s] == 0) cnt++;
		}
		stage++;
	}
	cout << stage;
	return 0;
}
