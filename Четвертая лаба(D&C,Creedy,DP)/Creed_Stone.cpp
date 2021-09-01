#include <iostream>
#include <limits>
#define N 100
using namespace std;
//Finding correct way
int get_min_cost(int costs[], int prev[][N], int n) {
	int min = std::numeric_limits<int>::max();
	int j = -1;
	for (int i = 0; i < n; i++)
		if (prev[i][n] != -1 && costs[i] < min) {
			min = costs[i];
			j = i;
		}
	return j;
}
//Searching min in row
int search_min(int used[], int a[][N], int i, int n) {
	int min = std::numeric_limits<int>::max();
	int k = -1;
	for (int j = 0; j < n; j++)
		if (used[j] == 0 && a[i][j] != 0 && a[i][j] < min) {
			min = a[i][j];
			k = j;
		}
	return k;
}
//The number of visited vertexes
int used_length(int used[], int n) {
	int sum = 0;
	for (int i = 0; i < n; i++)
		if (used[i] == 1) sum++;
	if (sum == n) return 0;
	else return 1;
}

int main() {
	int n, finish;
	int P[N][N] = { 0 };
	int Prev[N][N];
	int used[N] = { 0 };
	int costs[N] = { 0 };
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) cin >> P[i][j];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n + 1; j++) Prev[i][j] = -1;
	//Going from every vertex
	for (int i = 0; i < n; i++) {
		int j = 0, k = i;
		used[i] = 1;
		Prev[i][j++] = i;
	//Creating path from vertex
		while (used_length(used, n)) {
			int x = search_min(used, P, k, n);
			if (x == -1) break;
			Prev[i][j++] = x;
			used[x] = 1;
			costs[i] += P[k][x];
			k = x;
		}
	//If we have passed all the vertexes
		if (P[Prev[i][j - 1]][i] != 0) {
			costs[i] += P[Prev[i][j - 1]][i];
			Prev[i][j++] = i;
		}
	//Clearing an 'used' array
		for (int i = 0; i < n; i++) used[i] = 0;
	}

	finish = get_min_cost(costs, Prev, n);
	if (finish != -1) {
		cout << "Path:\n";
		for (int j = 0; j <= n; j++) cout << Prev[finish][j] << " ";
		cout << "\nCost: " << costs[finish];
	}
	else {
		cout << "Lost";
	}

	return 0;
}