#include <iostream>
using namespace std;
#define N 100
int main() {
	long int branch[N][N];
	int p[N][N] = { 0 };
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) 
			branch[i][j] = -1;

	for (int k = 0; k < m; k++) {
		int i, j, x;
		cin >> i >> j >> x;
		branch[i - 1][j - 1] = x;
	}

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			if (i == j) branch[i][j] = 0;
			else if(branch[i][j] == -1) branch[i][j] = std::numeric_limits<int>::max();
		}
	/*for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) cout << branch[i][j] << " ";
		cout << endl;
	}*/
	for (int k = 0; k < n; k++)
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++) 
				if (branch[i][k] < std::numeric_limits<int>::max() && branch[k][j] < std::numeric_limits<int>::max()) {
					if (branch[i][k] + branch[k][j] < branch[i][j]) {	
						branch[i][j] = branch[i][k] + branch[k][j];
						p[i][j] = k+1;

					}
				}
	cout << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) cout << branch[i][j] << " ";
		cout << endl;
	}
	cout << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) cout << p[i][j] << " ";
		cout << endl;
	}

	return 0;
}