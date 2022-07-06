#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<queue>


using namespace std;
#define INF 10000

vector<int> subway[10000];
int fast[10000];
bool visited[10000];



void dijkstra(int start,int fin, int n)
{

	priority_queue<pair<int, int>>pq;
	pq.push({ 0,start });
	fast[start] = 0;

	while (!pq.empty())
	{
		int dist = -pq.top().first; //현재 노드까지의 비용
		int now = pq.top().second; // 현재 노드
		pq.pop();

		if (fast[now] < dist) // 이미 최단경로를 체크한 노드인 경우 패스
			continue;
		if (now == fin) {
			return;
		}
		for (int i = 0; i < subway[now].size(); i++)
		{
			int cost = dist +1; // 거쳐서 가는 노드의 비용을 계산
												  // 현재노드까지 비용 + 다음 노드 비용
			if (cost < fast[subway[now][i]]) // 비용이 더 작다면 최단경로 테이블 값을 갱신.
			{
				fast[subway[now][i]] = cost;
				pq.push(make_pair(-cost, subway[now][i]));
			}
		}
	}
}

int main() {
	
	//freopen("input_tr.txt", "r", stdin);
	//ios::sync_with_stdio(false);
	//cin.tie(NULL);

	int t, tt=0,n,m,s,e,val;
	cin >> t;
	while (tt<t){
		vector<int> route[10000];
		int j = 0;
		cin >> n >> m >> s >> e;
		fill_n(fast, n+1, INF);
		fill_n(visited, n+1, false);

		for (int i = 0; i < m; i++) {
			cin >> val;
			route[i].push_back(val);
		}
		for (int i = 0; i <m; i++) {
			for (int j = 0; j < route[i][0]; j++) {
				cin >> val;
				route[i].push_back(val);
			}
		}
		for (int i = 0; i < m; i++) {
			for (int j = 1; j <= route[i][0]; j++) {
				for (int p = 1; p <= route[i][0]; p++) {
					if (p != j)
						subway[route[i][j]].push_back(route[i][p]);
				}
			}
		}
		dijkstra(s, e, n);
		tt++;
		if (fast[e] == INF)
			cout <<"#"<<tt<<" " << -1 << "\n";
		else { cout << "#" << tt << " "<< fast[e]-1<<"\n"; }
		for (int i = 1; i <= n; i++) {
			subway[i].clear();
		}
	}
	return 0;
}