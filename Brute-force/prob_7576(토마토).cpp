#include <iostream>
#include <vector>
using namespace std;
int box[1000][1000];
bool visit[1000][1000];
vector<pair<int,int>> ripen;
vector<pair<int, int>> new_ripen;
int m, n;
int tomato;
bool isFin(int cnt) {
	if (tomato == cnt) {
		return false;
	}
	return true;
}

void oneDay(int i, int j) {
	if (i > 0 &&!visit[i-1][j]) {
		if (box[i - 1][j] == 0) {
			box[i - 1][j] = 1;
			new_ripen.push_back({ i - 1,j});
		}
	}
	if ( j < m - 1 && !visit[i][j + 1]) {
		if (box[i][j+1] == 0) {
			box[i][j+1] = 1;
			new_ripen.push_back({ i ,j+1 });
		}
	}
	if (i < n-1 && !visit[i + 1][j]) {
		if (box[i + 1][j] == 0) {
			box[i + 1][j] = 1;
			new_ripen.push_back({ i + 1,j });
		}
	}
	if (j >0 && !visit[i][j - 1]) {
		if (box[i ][j-1] == 0) {
			box[i ][j-1] = 1;
			new_ripen.push_back({ i ,j-1 });
		}
	}
	visit[i][j] = true;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> m >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> box[i][j];
			if (box[i][j] == 1) {
				ripen.push_back({ i,j });
			}
			if (box[i][j] != -1) {
				tomato++;
			}
		}
	}
	int cnt = 0;
	int last_day = ripen.size();
	while (isFin(last_day)) {
		
		for (int i = 0; i < ripen.size(); i++)
		{
			if (!visit[ripen[i].first][ripen[i].second]) {
				oneDay(ripen[i].first, ripen[i].second);
			}
		}
		ripen.clear();
		ripen.swap(new_ripen);
		cnt++;
		if (ripen.size()==0) {
			cout << -1;
			return 0;
		}
		last_day += ripen.size();
	}
	cout << cnt;
	return 0;
}