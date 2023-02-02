#include<iostream>
#include <queue>
#include<algorithm>
using namespace std;

int computer[1001];
//오름차순 sort는 왼쪽 기준.
//bool cmp(pair<int, pair<int, int>> a, pair<int, pair<int, int>>b) {
//	return a.first < b.first;
//}
vector<pair<int, pair<int, int>>> q;
int find(int a) {
	if (a == computer[a])
		return a;
	else {
		return computer[a] = find(computer[a]);
	}
}
bool uni(int a, int b) {
	if (a == b) {
		return 0;
	}
	int ap = find(a);
	int bp = find(b);
	if (ap == bp) {
		return 0;
	}
	else {
		computer[ap] = bp;
		return 1;
	}
}
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, m,a,b,c;
	cin >> n >>  m;
	for (int i = 0; i < m; i++) {
		cin >> a>> b>> c;
		q.push_back({ c,{a,b} });
		computer[a] = a;
		computer[b] = b;
	}
	sort(q.begin(), q.end());
	int result = 0;
	for (int i = 0; i < q.size(); i++) {
		c = q[i].first;
		a = q[i].second.first;
		b = q[i].second.second;
		
		if (uni(a, b)) {
			result += c;
		}
	}
	cout << result;
	return 0;
}