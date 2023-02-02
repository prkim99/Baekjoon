#include <iostream>
#include <algorithm>
#include<vector>
#include <queue>
#include <cstring>
#include <cstdio>
#include<string>
using namespace std;


vector<int> graph[10001];
bool cutVertex[10001];
int visitOrder[10001];
int order;
int cutNum = 0;
int dfs(int curr, int parent) {
	visitOrder[curr] = ++order;

	int minOrder = visitOrder[curr];
	int child = 0;
	for (int i = 0; i < graph[curr].size(); i++) {
		int ch_node = graph[curr][i];
		if (ch_node == parent)
			continue;
		//이미 탐색된 노드라면, 탐색된 노드의 방문순서를 확인하여 가장 작은 값을 찾는다.
		else if (visitOrder[ch_node] > 0) {
			if (visitOrder[ch_node] < minOrder) {
				minOrder = visitOrder[ch_node];
			}
		}
		else { 
			//탐색된 적이 없는 노드라면
			child++;
			//해당 해당 노드의 자식들에 대해 재귀를 수행하여
			//접근할 수 있는 가장 작은 방문순서를 가진 노드를 리턴받는다.
			int low = dfs(ch_node, curr); 
			//현재노드가 루트가 아니고 방문순서가 자식들이 접근할 수 있는 모든 노드에 비해 작다면
			//(즉 자식들이 자신을 거치지 않고 더 작은 방문번호인 노드로 가는 길이 없다면
			if (parent != 0 && visitOrder[curr] <= low){
				cutVertex[curr] = 1;//단절점 확인
			}
			
			minOrder = min(low, minOrder);
		}
	}
	//루트로 잡은 노드의 자식이 둘 이상이면 단절점.
	if (parent == 0 && child >= 2) {
		cutVertex[curr] = 1;
	}

	return minOrder;
}

int main() {
	int v, e,v1,v2;
	scanf("%d %d", &v, &e);
	for (int i = 0; i < e; i++) {
		scanf("%d %d", &v1, &v2);
		graph[v1].push_back(v2);
		graph[v2].push_back(v1);
	}

	//그래프가 여러개로 나눠져 있을 가능성이 있기때문
	for (int i = 1; i <= v; i++) {
		if (visitOrder[i] <= 0) {
			dfs(i, 0);
		}
	}
	string str;
	for (int i = 1; i <= v; i++) {
		if (cutVertex[i] == 1) {
			cutNum++;
			str += to_string(i)+" ";
		}
	}
	printf("%d\n", cutNum);
	printf("%s", str.c_str());

	return 0;
}
