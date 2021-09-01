#include<iostream>
#include <limits>
#define N 100
using namespace std;

void ways(int p[], int n) {
	int a[N][N] = { 0 };
	for (int i = 0; i < n; i++) {
		int j = i;
		int k = i;
		while (j >= 0) {
			a[i][k] = j + 1;
			j = p[j] - 1;
			k++;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) if (a[i][j] != 0) cout << a[i][j] << " ";
		cout << endl;
	}
}

int NegativeCycle(long int branchs[N][N], long int d[], int n) {
	int shet = 0;
	for (int i = 0; i < n; i++) {
		int x = d[i];
		if (x == std::numeric_limits<int>::max()) continue;
		for (int j = 0; j < n; j++)
			if (branchs[i][j] < std::numeric_limits<int>::max()) {
				if (branchs[i][j] + x < d[j]) {					
					d[j] = branchs[i][j] + x;
					shet++;
				}
			}
	}		
	return shet;
}

int main() {
	long int branchs[N][N];
	long int d[N];
	int p[N] = { 0 };
	int n, m;	// m - number of branchs
	
	//Graph initialization
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			branchs[i][j] = std::numeric_limits<int>::max();
		}

	for (int k = 0; k < m; k++) {
		int i, j, x;
		cin >> i >> j >> x;
		branchs[i - 1][j - 1] = x;
	}

	d[0] = 0;
	for (int i = 1; i < n; i++) d[i] = std::numeric_limits<int>::max();

	for (int k = 0; k < n - 1; k++) 
		for (int i = 0; i < n; i++) {
			int x = d[i];
			if (x == std::numeric_limits<int>::max()) continue;
			for (int j = 0; j < n; j++) 
				if (branchs[i][j] < std::numeric_limits<int>::max()) {
					if (branchs[i][j] + x < d[j]) {
						d[j] = branchs[i][j] + x;
						p[j] = i + 1;
					}
				}		
		}
	if (NegativeCycle(branchs, d, n) != 0) {
		cout << "\nNegative Cycle is exit";
		return 0;
	}
	cout << endl << "D: ";
	for (int i = 0; i < n; i++) cout << d[i] << " ";
	cout << endl << "P: ";
	for (int i = 0; i < n; i++) cout << p[i] << " ";
	cout << "\nShortest paths: " << endl;
	ways(p, n);
	return 0;
}