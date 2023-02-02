#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<int>sucnode[32001];
int edge[32001];
queue<int> q;
//priority_queue <vector<pair<int,int>>, pair<int, int>,greater> pq;

void topologySort() {
	while (!q.empty()) {
		int point = q.front();
		q.pop();
		for (int i = 0; i < sucnode[point].size(); i++) {
			edge[sucnode[point][i]]--;
			if (edge[sucnode[point][i]] == 0) {
				q.push(sucnode[point][i]);
			}
		}
		edge[point]--;
		cout << point<<" ";
	}
	return;
}
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, m,a,b;
	cin >> n >>  m;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		sucnode[a].push_back(b);
		edge[b]++;
	}
	for (int i = 1; i <= n; i++){
		if (edge[i] == 0) {
			q.push(i);
		}
	}
	topologySort();
	return 0;
}