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
		//�̹� Ž���� �����, Ž���� ����� �湮������ Ȯ���Ͽ� ���� ���� ���� ã�´�.
		else if (visitOrder[ch_node] > 0) {
			if (visitOrder[ch_node] < minOrder) {
				minOrder = visitOrder[ch_node];
			}
		}
		else { 
			//Ž���� ���� ���� �����
			child++;
			//�ش� �ش� ����� �ڽĵ鿡 ���� ��͸� �����Ͽ�
			//������ �� �ִ� ���� ���� �湮������ ���� ��带 ���Ϲ޴´�.
			int low = dfs(ch_node, curr); 
			//�����尡 ��Ʈ�� �ƴϰ� �湮������ �ڽĵ��� ������ �� �ִ� ��� ��忡 ���� �۴ٸ�
			//(�� �ڽĵ��� �ڽ��� ��ġ�� �ʰ� �� ���� �湮��ȣ�� ���� ���� ���� ���ٸ�
			if (parent != 0 && visitOrder[curr] <= low){
				cutVertex[curr] = 1;//������ Ȯ��
			}
			
			minOrder = min(low, minOrder);
		}
	}
	//��Ʈ�� ���� ����� �ڽ��� �� �̻��̸� ������.
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

	//�׷����� �������� ������ ���� ���ɼ��� �ֱ⶧��
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
