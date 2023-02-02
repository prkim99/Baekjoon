#include<iostream>

using namespace std;
long long int val[4];

void mult(long long int m1[][2], long long int m2[][2]){

	val[0] = (m1[0][0] * m2[0][0] + m1[0][1] * m2[1][0]) % 1000000;
	val[1] = (m1[0][0] * m2[0][1] + m1[0][1] * m2[1][1]) % 1000000;
	val[2] = (m1[1][0] * m2[0][0] + m1[1][1] * m2[1][0]) % 1000000;
	val[3] = (m1[1][0] * m2[0][1] + m1[1][1] * m2[1][1]) % 1000000;

}

	int main() {
		long long int n;
		cin >> n;
		
		long long int matrix[2][2] = { {1, 1}, {1, 0} };
		long long int result[2][2] = { {1, 0}, {0, 1} };

		for (long long int i = n; i >0; i/=2) {
			if (i%2==1) {
				mult(matrix, result);
				result[0][0] = val[0];
				result[0][1] = val[1];
				result[1][0] = val[2];
				result[1][1] = val[3];

				
			}
			mult(matrix, matrix);
			matrix[0][0] = val[0];
			matrix[0][1] = val[1];
			matrix[1][0] = val[2];
			matrix[1][1] = val[3];
		}
		cout << result[0][1] << endl;
		return 0;
	}
