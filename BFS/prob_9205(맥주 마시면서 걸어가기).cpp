#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;


bool bfs(int sx, int sy, vector<pair<int, int>>c, int dx, int dy) {
	queue<pair<int, int>> q;
	int visit[101] = { 0, };
	q.push({ sx,sy });
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		if (abs(x - dx) + abs(y - dy) <= 1000)
			return true;
		for (int i = 0; i < c.size(); i++) {
			if (!visit[i]) {
				int cx = c[i].first;
				int cy = c[i].second;
				if (abs(cx - x) + abs(cy - y) <= 1000){
					visit[i] = true;
					q.push({ cx,cy });
				}
			}
		}
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t;
	int tt = 0;
	cin >> t;
	while (t > tt) {
		int n;
		cin >> n;
		int sx, sy;
		cin >> sx >> sy;
		int v1, v2;
		vector<pair<int, int>> c;
		for (int i = 0; i < n; i++) {
			cin >> v1 >> v2;
			c.push_back({ v1,v2 });
		}
		int dy, dx;
		cin >> dx >> dy;
		if (bfs(sx, sy, c, dx, dy)) {
			cout << "happy\n";
		}
		else {
			cout << "sad\n";
		}
		c.clear();
		tt++;
	}

	return 0;
}
