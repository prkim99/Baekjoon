//#define _CRT_SECURE_NO_WARNINGS
//#include<iostream>
//#include<queue>
//#include<vector>
//using namespace std;
//
//bool comp(pair<int, int> a, pair<int, int>b) {
//	return (a.first - a.second) > (b.first - b.second);
//}
//
//
//struct compare {
//	bool operator()(pair<int, int> a, pair<int, int> b) {
//		return (a.first - a.second) < (b.first - b.second);
//
//	}
//};
//
////
//int main() {
//	freopen("input.txt", "r", stdin);
//	ios::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	unsigned long long int day_cut = 0;
//	int t, i = 0, m, n, d, mow, val;
//	cin >> t;
//	while (i < t) {
//		vector<pair<int, int>> lawn;
//		vector<int> day;
//		cin >> n >> m >> d;
//		for (int l = 0; l < n * m; l++) {
//			cin >> val;
//			lawn.push_back(pair<int,int>(val,0));
//
//		}
//		for (int l = 1; l <=d; l++) {
//			cin >> mow;
//			day.push_back(mow);
//		}
//		sort(lawn.begin(), lawn.end(), comp);
//		int k = 0;
//		for (int l = 1; l <= d;l++) {
//			for (int m = 0; m < day[l-1]; m++) {
//				int cut = l * (lawn[k].first + (l - lawn[k].second) - 1);
//				day_cut += cut;
//
//				lawn.push_back(pair<int, int>(1, l));
//				k++;
//			}
//		}
//
//		cout << "#" << i + 1 << " " << day_cut << "\n";
//		day_cut = 0;
//		i++;
//	}
//	i = 0;
//
//	return 0;
//}
//
////int main() {
////	freopen("input.txt", "r", stdin);
////	ios::sync_with_stdio(false);
////	cin.tie(NULL);
////
////	long long int day_cut = 0;
////	int k=0, t, i=0, m, n,d, mow,val;
////	cin >> t;
////	while (i < t) {
////		priority_queue<pair<int, int>, vector<pair<int, int>>, compare > lawn;
////		cin >> n>>m>>d;
////		for (int l = 0; l < n*m; l ++) {
////			cin >> val;
////			lawn.push({ val,0 });
////
////		}
////		for (int l = 1; l <= d; l++) {
////			cin >> mow;
////			for (int m = 1; m <= mow; m++) {
////				int cut = l * (lawn.top().first + (l - lawn.top().second) - 1);
////				day_cut += cut;
////
////				lawn.pop();
////				lawn.push({ 1, l });
////			}
////		}
////
////		cout << "#" << i + 1 << " " << day_cut << "\n";
////		day_cut = 0;
////		i++;
////	}
////	i = 0;
////
////	return 0;
////}