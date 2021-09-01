#include <iostream>
#include <limits>
#define N 100
using namespace std;

int search(long int a[], int used[], int n) {
	int min = std::numeric_limits<int>::max();
	int k;
	for (int i = 0; i < n; i++) 
		if (used[i] == 0 && a[i] < min) {
			min = a[i];
			k = i;
		}
	return k;
}

int path(int a[N][N], int i, int n) {
	for (int j = 0; j < n; j++) if (a[i][j] > -1) {
		int c = j;
		a[i][j] = -1;
		return c;
	}
}

int NumOfBranchs(int a[N][N], int i, int n) {
	int k = 0;
	for (int j = 0; j < n; j++) if (a[i][j] > -1) k++;
	return k;
}

int used_lenght(int a[], int n) {
	int k = 0;
	for (int i = 0; i < n; i++) if (a[i] == 1) k++;
	return k;
}

void ways(int p[], int n) {
	int a[N][N] = { 0 };
	for (int i = 0; i < n; i++) {
		int j = i;
		while (j >= 0) {
			a[i][j] = j + 1;
			j = p[j] - 1;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) if (a[i][j] != 0) cout << a[i][j] << " ";
		cout << endl;
	}
}

int main() {
	int branchs[N][N];
	int branchs_1[N][N];
	long int d[N];
	int p[N] = { 0 };
	int used[N] = { 0 };
	int n, m;	// m - number of branchs
	//Graph initialization

	cin >> n >> m;
	for (int i = 0; i < n; i++) 
		for (int j = 0; j < n; j++) {
			branchs[i][j] = -1;
			branchs_1[i][j] = -1;
		}

	for (int k = 0; k < m; k++) {
		int i, j, x;
		cin >> i >> j >> x;
		branchs[i - 1][j - 1] = x;
		branchs_1[i - 1][j - 1] = x;
	}

	d[0] = 0;
	for (int i = 1; i < n; i++) d[i] = std::numeric_limits<int>::max();

	while (used_lenght(used, n) != n ) {
		int i = search(d, used, n);
		int w = d[i];
		while (NumOfBranchs(branchs_1, i, n) != 0) {
			int j = path(branchs_1, i, n);
			if (branchs[i][j] + w < d[j]) {
				d[j] = branchs[i][j] + w;
				p[j] = i + 1;
			}
		}
		used[i] = 1;
	}

	cout << endl << "D: ";
	for (int i = 0; i < n; i++) cout << d[i] << " ";
	cout << endl << "P: ";
	for (int i = 0; i < n; i++) cout << p[i] << " ";
	cout << endl << "USED: ";
	for (int i = 0; i < n; i++) cout << used[i] << " ";
	cout << endl;
	/*for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) cout << branchs[i][j] << " ";
		cout << endl;
	}*/
	cout << "Shortest paths: "<<endl;
	ways(p, n);
}