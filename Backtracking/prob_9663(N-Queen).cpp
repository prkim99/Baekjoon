#include <iostream>
using namespace std;

int line[16];
int n;
int result = 0;


void setQueen(int index) {
	if (index == n+1) {
		result++;
		return;
	}
	bool d[16]={0,};
	int space;
	for (int i = 1; i <= n; i++) {
		if (line[i] != 0) {
			d[line[i]] = true;
			space = index - i;
			if (line[i] + space <= n) d[line[i] + space] = true;
			if (line[i] - space >=1 ) d[line[i] - space] = true;
		}
	}
	for(int i=1;i<=n;i++){
		if (d[i]==false) {
			line[index] = i;
			setQueen(index + 1);
			line[index] = 0;
		}
	}
}
int main() {
	cin >> n;
	setQueen(1);

	cout << result;
	return 0;
}