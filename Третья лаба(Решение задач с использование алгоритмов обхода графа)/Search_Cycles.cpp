#include <iostream>
#include <limits>
#define N 100
using namespace std;

int chek = 0;

int numbers(int branchs[N][N], int n, int i) {
	int k = 0;
	for (int j = 0; j < n; j++) if (branchs[i][j] == 1) k++;
	return k;
}

void swapArray(int arr[], int s, int e) {
	int c;
	int k = 0;
	for (int i = s; i <= (e + s) / 2; i++) {
		c = arr[i];
		arr[i] = arr[e - k];
		arr[e - k] = c;
		k++;
	}
}

void search_cycle(int i, int n, int branchs[N][N], int color[],long int prev[], int target) {
	if (numbers(branchs, n, i) == 0 || chek == 1) {
		color[i] = 2;
		cout << endl;
		return;
	}

	for (int j = 0; j < n; j++) {
		if (branchs[i][j] == 1) {
			color[i] = 1;
			if (color[j] == 1 && target == j) {
				prev[j] = i;
				chek = 1;
				return;
			}
			else if (color[j] == 0) {
				prev[j] = i;
				search_cycle(j, n, branchs, color, prev, target);
			}
			else if (color[j] > 0 && j != target) {
				if (numbers(branchs, n, i) > 1) continue;
				else return;
			}
		}
	}
}

int main() {
	int branchs[N][N];
	int color_v[N] = { 0 };//0 - white, 1 - grey, 2 = black
	long int prev[N];
	int output[N];
	int n, m;
	// m - number of branchs
	//Graph initialization

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		prev[i] = std::numeric_limits<int>::max();
		for (int j = 0; j < n; j++)
			branchs[i][j] = 0;
	}

	for (int k = 0; k < m; k++) {
		int i, j;
		cin >> i >> j;
		branchs[i][j] = 1;
	}
	for (int i = 0; i < n; i++) {
		search_cycle(i, n, branchs, color_v, prev, i);
		if (chek == 1) {
			//for (int i = 0; i < n; i++) cout << prev[i] << " ";
			int k = prev[i];
			int j = 0;
			while (1) {
				output[j] = k;
				k = prev[k];
				j++;
				if (k == i) { 
					output[j] = k;
					j++;
					break;
				}
			}
			swapArray(output, 0, j - 1);
			cout << "Cycle:" << endl;
			for (int u = 0; u < j; u++) cout << output[u] << " ";
			return 0;
		}
		for (int i = 0; i < n; i++) {
			color_v[i] = 0;
			prev[i] = std::numeric_limits<int>::max();
		}
	}
	cout << "No cycles";
	return 0;
}
