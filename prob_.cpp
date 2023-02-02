#include <iostream>
using namespace std;

int main() {
	double x,y,z;
	cin >> x >> y;
	int z_score = y*100/x;
	int z_int;
	if (z_score == 100) {
		cout << -1;
		return 0;
}
	int add,s,m,e;
	s = 1;
	e = x;
	m = (s + e) / 2;
	while (s<e) {
		z_int=(y + m)*100 / (x+m);
		if (z_int!=z_score) {
			e = m;
		}
		else {
			s = m + 1;
		}

		m = (s + e) / 2;
	}
	cout << e;
	return 0;
}