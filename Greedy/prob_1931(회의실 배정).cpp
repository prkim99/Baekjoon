#include <iostream>
#include<algorithm>
#include <vector>
using namespace std;

vector<pair<int,int>> meeting;

bool cmp(pair<int, int> a, pair<int, int> b) {
	if (a.second == b.second) return a.first<b.first;
	return a.second<b.second;
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	int v1, v2;
	for (int i = 0; i < n; i++) {
		cin >> v1 >> v2;
		meeting.push_back({ v1,v2 });
	}
	sort(meeting.begin(), meeting.end(),cmp);
	int cnt = 1;
	int time = meeting[0].second;
	for (int i = 1; i < n; i++) {
		if (time <= meeting[i].first) {
			time = meeting[i].second;
			cnt++;
		}
		
	}
	cout << cnt;

	return 0;
}
