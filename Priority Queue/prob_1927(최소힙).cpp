#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<queue>
#include<algorithm>
#include<stdio.h>
using namespace std;


priority_queue<int, vector<int>, greater<int>> minheap;

int main() {
	int n, val;
	scanf("%d",&n);
	int input;
	for (int i = 0; i < n; i++) {
		scanf("%d", &input);
		if (input != 0) {
			minheap.push(input);
		}
		else {
			if (minheap.empty())
			{
				printf("%d\n", 0);
				//cout << 0 << endl;
			}
			else {
				printf("%d\n", minheap.top());
				//cout << minheap.top() << endl;
				minheap.pop();
				
			}
		}

	}
	return 0;
}

//vector<int> minheap;
//int main() {
//	int n, val;
//	cin >> n;
//	int input;
//	for (int i = 0; i < n; i++) {
//		cin >> input;
//		if (input != 0) {
//			minheap.push_back(input);
//		}
//		else {
//			if (minheap.empty())
//			{
//				cout << 0 << endl;
//			}
//			else {
//				min(minheap.begin(),minihea
//)
//				cout << minheap.top() << endl;
//				minheap.pop();
//
//			}
//		}
//
//	}
//	return 0;
//}