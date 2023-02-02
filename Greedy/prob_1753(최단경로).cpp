#include <iostream>
#include <algorithm>
#include<vector>
#include <queue>
#include <cstring>
#include <cstdio>
#include<string>
using namespace std;
#define INF 200001


vector<pair<int, int>> dijk[20001];
priority_queue <pair<int,int>, vector<pair<int, int>>, greater<pair<int,int>>> cost;
int result[20001];

int v, e, u, w, k,n;
void pathDijk(int s) {


	result[s] = 0;
	cost.emplace( 0,s );

	while (!cost.empty()) {
		int node = cost.top().second;
		int c = cost.top().first;
		cost.pop();

		for (int i = 0; i < dijk[node].size(); i++) {
			int ch_node = dijk[node][i].first;
			int ch_c = dijk[node][i].second+c;
			if (ch_c < result[ch_node]) {
				result[ch_node] = ch_c;
				cost.emplace(ch_c,ch_node);
			}
		}
	}
	
}

int main() {

	scanf("%d %d", &n, &e);
	scanf("%d", &k);
	for (int i = 0; i < e; i++) {
		scanf("%d %d %d", &u, &v, &w);
		dijk[u].push_back({ v,w });
	}



	for (int i = 1; i <= n; i++) {
		result[i] = INF;
	}

	pathDijk(k);

	for (int i = 1; i <= n; i++) {
		if (result[i] >= INF) {
			printf("%s\n", "INF");
		}
		else {
			printf("%d\n", result[i]);
		}
	}
	
	return 0;
}
