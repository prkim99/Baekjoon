#include <iostream>
#include <algorithm>
#include<vector>
#include <queue>
#include <cstring>
using namespace std;


vector<int> height[501];
vector<int> bheight[501];
bool visit[501];
queue <int> q;
int n, m, val1, val2;
int bfs(int a) {
	q.push(a);
	int back_prson = 0;
	memset(visit, 0, n+1 );
	while (!q.empty()) {
		int node = q.front();
		q.pop();
		for (int i = 0; i < height[node].size(); i++) {
			int ch_node = height[node][i];
			if (!visit[ch_node]) {
				visit[ch_node]=true;
				q.push(ch_node);
				back_prson++;
			}
		}
	}
	return back_prson;
}
int b_bfs(int a) {
	q.push(a);
	int front_prson = 0;
	memset(visit, 0, n+1 );
	while (!q.empty()) {
		int node = q.front();
		q.pop();
		for (int i = 0; i < bheight[node].size(); i++) {
			int ch_node = bheight[node][i];
			if (!visit[ch_node]) {
				visit[ch_node] = true;
				q.push(ch_node);
				front_prson++;
			}
		}
	}
	return front_prson;
}
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	string row;
	cin >> n>>m;
	for (int i =  1; i <= m; i++) {
		cin >> val1 >> val2;
		height[val1].push_back(val2);
		bheight[val2].push_back(val1);
	}

	int result = 0;
	for (int i = 1; i <= n; i++) {
		if ((bfs(i) + b_bfs(i)) == n - 1) {
			result++;
		}
	}
	cout << result << "\n";
	return 0;
}
