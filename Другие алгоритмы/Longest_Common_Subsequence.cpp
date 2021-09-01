#include <iostream>
#include <string>
#define N 100
using namespace std;

int max(int a, int b) {
	if (a > b) return a;
	else return b;
}

int main() {
	string s1 = "";
	string s2 = "";
	int n, m;
	int a[N][N];
	cin >> s1 >> s2;
	n = s1.length();
	m = s2.length();
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= m; j++) {
			if (i == 0 || j == 0) {
				a[i][j] = 0;
				continue;
			}
			if (s1[i-1] == s2[j-1]) a[i][j] = a[i - 1][j - 1] + 1;
			else a[i][j] = max(a[i - 1][j], a[i][j - 1]);
		}
	}
	
	/*for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= m; j++) cout << a[i][j] << " ";
			cout << endl;
	}*/
	int i = n, j = m;
	int k = 0;
	char end[N];
	while (i != 0 && j != 0) {
		if (a[i - 1][j - 1] < a[i][j] && a[i - 1][j - 1] >= a[i - 1][j] && a[i - 1][j - 1] >= a[i][j - 1]) {
			i--;
			j--;
			end[k] = s1[i];
			k++;
		}
		else if (a[i - 1][j - 1] == a[i][j]) {
			i--;
			j--;
		}
		else {
			if (a[i - 1][j] > a[i][j - 1]) {
				i--;
			}
			else j--;
		}
	}

	for (int i = k-1; i >=0; i--) cout << end[i];
	return 0;
}