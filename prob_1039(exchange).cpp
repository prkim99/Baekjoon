//#include<iostream>
//#include <vector>
//
//using namespace std;
//
//vector<int> n;
////BFS����� �̿��ؼ� �� �տ� ���ں��� �������ָ� �� �� ����.
////�������ù��° ������ �� ������ �� �� �ִ� �ٸ� ���������� ť���� �־ �����ϰ�, 
////�ߺ� ���� �� �� �ڸ����� �� ���� ���ؼ� �־��ִ� ����
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