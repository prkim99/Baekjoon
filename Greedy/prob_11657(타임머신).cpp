#include <iostream>
#include <algorithm>
#include<vector>
#include <queue>
#include <cstring>
#include <cstdio>
#include<string>
using namespace std;
#define INF 0X7FFFFFFFFFFFFFFF


vector<pair<int, int>> Bellman[501];
long long int result[501];

int n, m, a, b, c;
bool negativeCycle = false;
void BFM(int s) {
	result[s] = 0;
	for (int k = 1; k < n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j < Bellman[i].size(); j++) {
				int node = Bellman[i][j].first;
				int cost = Bellman[i][j].second;
				if (result[i] != INF && result[node] > result[i] + cost) {
					result[node] = result[i] + cost;
				}
				}
			}
		}
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < Bellman[i].size(); j++) {
			int node = Bellman[i][j].first;
			int cost = Bellman[i][j].second;
			if (result[i] != INF && result[node] > result[i] + cost) {
				negativeCycle = true;
			}
		}
	}
}

int main() {

	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &a, &b, &c);
		Bellman[a].push_back({ b,c });
	}



	for (int i = 1; i <= n; i++) {
		result[i] = INF;
	}
	
	BFM(1);

	if (negativeCycle) {
		printf("%d", -1);
	}
	else {
		for (int i = 2; i <= n; i++) {
			if (result[i] >= INF) {
				printf("%d\n", -1);
			}
			else {
				printf("%d\n", result[i]);
			}
		}
	}

	
	return 0;
}
