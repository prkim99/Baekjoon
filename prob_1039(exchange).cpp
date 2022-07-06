//#include<iostream>
//#include <vector>
//
//using namespace std;
//
//vector<int> n;
////BFS방법을 이용해서 맨 앞에 숫자부터 정렬해주면 될 것 같당.
////강사님은첫번째 점부터 한 정점에 들어갈 수 있는 다른 정점값들을 큐에다 넣어서 정렬하고, 
////중복 제거 후 각 자리수에 들어갈 숫자 정해서 넣어주는 느낌
//
//int main() {
//	int k, t = 0, val;
//	string nn;
//	cin >> nn;
//	for (int i = 0; i < nn.size(); i++) {
//		n.push_back(nn[i]-'0');
//	}
//	cin >> k;
//	int temp, index, kk = 0;
//		for (int i = 0; i < nn.size(); i++) {
//			temp = n[i];
//			index=i;
//			for (int j = i + 1; j < nn.size(); j++) {
//				if (temp <= n[j]) {
//					temp = n[j];
//					index = j;
//				}
//			}
//			n[index] = n[i];
//			n[i] = temp;
//			if (i != index||i==nn.size()-1)
//				kk++;
//			if (kk == k) {
//				break;
//			}
//		}
//		if (kk == k) {
//			for (int i = 0; i < nn.size(); i++) {
//				cout << n[i];
//			}
//		}
//		else {
//			cout << -1;
//		}
//	return 0;
//}