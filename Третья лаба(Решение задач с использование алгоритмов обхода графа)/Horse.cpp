#include <iostream>
#define N 100
#define M 8
#define A 400

using namespace std;

int chek = 0;
int prevI = 1;
int color_v[A] = { 0 };

int search_i(int prev[A], int x) {
	for (int i = 0; i < prevI; i++) if (x == prev[i]) return i;
}

int numbers(int branchs[A][A], int n, int i) {
	int k = 0;
	for (int j = 0; j < n; j++) if (branchs[i][j] == 1) k++;
	return k;
}

int search(int graph[A][A], int prev[A], int n, int i) {
	int k = 0;
	for (int j = 0; j < n; j++) if (graph[i][j] == 1) {
		for (int u = 0; u < prevI; u++) if (prev[u] == j) k++;
	}
	if (k == numbers(graph, n, i)) return 1;
	else return 0;
}

void dfs(int graph[A][A], int n, int start, int prev[]) {
	int k = 0;
	color_v[start] = 1;
	for (int j = 0; j < n*n; j++) {
		if (graph[start][j] == 1 && color_v[j] == 0) {
			k++;
			prev[prevI] = j;
			prevI++;
			dfs(graph, n, j, prev);
		}
	}
	if (chek == 1) return;
	if (search(graph, prev, n, start) && prevI == n * n) {
		chek = 1;
		return;
		}
	color_v[start] = 0;
	prevI--;
	prev[prevI] = -1;
	return;
}

void horse(int field[N][N], int moves[M][A], int shet[A], int n) {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			if (i - 2 >= 0 && j - 1 >= 0) {
				moves[shet[field[i][j]]][field[i][j]] = field[i - 2][j - 1];
				shet[field[i][j]]++;
			}
			if (i - 2 >= 0 && j + 1 <= n - 1) {
				moves[shet[field[i][j]]][field[i][j]] = field[i - 2][j + 1];
				shet[field[i][j]]++;
			}
			if (i - 1 >= 0 && j - 2 >= 0) {
				moves[shet[field[i][j]]][field[i][j]] = field[i - 1][j - 2];
				shet[field[i][j]]++;
			}
			if (i - 1 >= 0 && j + 2 <= n - 1) {
				moves[shet[field[i][j]]][field[i][j]] = field[i - 1][j + 2];
				shet[field[i][j]]++;
			}
			if (i + 1 <= n - 1 && j - 2 >= 0) {
				moves[shet[field[i][j]]][field[i][j]] = field[i + 1][j - 2];
				shet[field[i][j]]++;
			}
			if (i + 1 <= n - 1 && j + 2 <= n - 1) {
				moves[shet[field[i][j]]][field[i][j]] = field[i + 1][j + 2];
				shet[field[i][j]]++;
			}
			if (i + 2 <= n - 1 && j - 1 >= 0) {
				moves[shet[field[i][j]]][field[i][j]] = field[i + 2][j - 1];
				shet[field[i][j]]++;
			}
			if (i + 2 <= n - 1 && j + 1 <= n - 1) {
				moves[shet[field[i][j]]][field[i][j]] = field[i + 2][j + 1];
				shet[field[i][j]]++;
			}
		}
	for (int j = 0; j < n * n; j++) {
		cout << j << " - ";
		for (int i = 0; i < shet[j]; i++) cout << moves[i][j] << " ";
		cout << endl;
	}
}

int main() {
	int graph[A][A] = { 0 };
	int field[N][N];
	int moves[M][A];
	int prev[A];
	int shet[A] = { 0 };
	int n, x, y, start, k = 0;
	cin >> n;
	cin >> x >> y;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			field[i][j] = k;
			k++;
		}
	for (int i = 0; i < n * n; i++) prev[i] = -1;
	prev[0] = field[x][y];
	cout << "Graph:\n";
	horse(field, moves, shet, n);
	//Создание Графа
	for (int j = 0; j < n * n; j++)
		for (int i = 0; i < shet[j]; i++) graph[j][moves[i][j]] = 1;

	start = field[x][y];
	dfs(graph, n, start, prev);
	if (chek == 1) {
		cout << "Hamiltonian path:\n";
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				field[i][j] = search_i(prev, field[i][j]);
				cout << field[i][j] << " ";
			}
			cout << endl;
		}
	}
	else cout << "Hamiltonian path:\nNo way";
	return 0;
}