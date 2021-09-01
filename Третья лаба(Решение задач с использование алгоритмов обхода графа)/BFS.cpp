#include <iostream>
#include <queue>
#define N 100
#define A 400
using namespace std;

int chek = 0;
queue <int> Myqueue;
int color_v[A] = { 0 };
int dist[A] = { 0 };

void print_labyrinth(string table[N], int n, int m) {
	cout << "Initial labyrinth:" << endl;
	for (int i = 0; i < n; i++) {
		cout << table[i];
		cout << endl;
	}
}

void print_graph(string table[N], int a[N][N], int schet[A], int moves[4][A], int n, int m) {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			if (table[i][j] != '#') {
				int k = 0;
				if (i - 1 >= 0 && table[i - 1][j] != '#') {
					moves[schet[a[i][j]]][a[i][j]] = a[i - 1][j];
					schet[a[i][j]]++;
					k++;
				}
				if (j - 1 >= 0 && table[i][j - 1] != '#') {
					moves[schet[a[i][j]]][a[i][j]] = a[i][j - 1];
					schet[a[i][j]]++;
					k++;
				}
				if (j + 1 <= m - 1 && table[i][j + 1] != '#') {
					moves[schet[a[i][j]]][a[i][j]] = a[i][j + 1];
					schet[a[i][j]]++;
					k++;
				}
				if (i + 1 <= n - 1 && table[i + 1][j] != '#') {
					moves[schet[a[i][j]]][a[i][j]] = a[i + 1][j];
					schet[a[i][j]]++;
					k++;
				}
				if (k == 0) moves[schet[a[i][j]]][a[i][j]] = -1;
			}
			else {
				moves[schet[a[i][j]]][a[i][j]] = -1;
			}
		}
	cout << "Graph:\n";
	for (int j = 0; j < n * m; j++) {
		cout << j << " - ";
		if (moves[0][j] >= 0) for (int i = 0; i < schet[j]; i++) cout << moves[i][j] << " ";
		else cout << "None";
		cout << endl;
	}
}

void create_graph(int graph[A][A], int moves[4][A], int schet[A], int n, int m) {
	for (int j = 0; j < n * m; j++)
		if (moves[0][j] != -1) for (int i = 0; i < schet[j]; i++) graph[j][moves[i][j]] = 1;
}

int set_start(int a[N][N], string table[N], int n, int m) {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) if (table[i][j] == 'S') return a[i][j];
}

int set_finish(int a[N][N], string table[N], int n, int m) {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) if (table[i][j] == 'F') return a[i][j];
}

void bfs(int graph[A][A], int n, int m, int start, int finish) {
	color_v[start] = 1;
	int neighbour = 0;
	while (!Myqueue.empty()) {
		int x = Myqueue.front();
		Myqueue.pop();
		for (int j = 0; j < n * m; j++) if (graph[x][j] == 1 && color_v[j] == 0) {
			color_v[j] = 1;
			Myqueue.push(j);
			dist[j] = dist[x] + 1;
			if (j == finish) {
				neighbour = j;
				chek = 1;
				break;
			}
		}
		if (chek == 1) {
			while (Myqueue.front() != neighbour) {
				int x = Myqueue.front();
				Myqueue.pop();
				for (int j = 0; j < n * m; j++) if (graph[x][j] == 1 && color_v[j] == 0) {
					color_v[j] = 1;
					dist[j] = dist[x] + 1;
				}
			}
			break;
		}
	}
}

void print_final_map(int a[N][N], int n, int m, int start) {
	for (int i = 0; i < n * m; i++) if (i != start && dist[i] == 0) dist[i] = -1;
	cout << "BFS result is :" << endl;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++) {
			a[i][j] = dist[a[i][j]];
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
}

int main() {
	string table[N] = {};
	int a[N][N];
	int graph[A][A] = { 0 };
	int moves[4][A] = { 0 };
	int schet[A] = { 0 };
	int n, m, k = 0, start, finish;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> table[i];
		for (int j = 0; j < m; j++) {
			a[i][j] = k;
			k++;
		}
	}

	print_labyrinth(table, n, m);
	print_graph(table, a, schet, moves, n, m);
	create_graph(graph, moves, schet, n, m);
	start = set_start(a, table, n, m);
	finish = set_finish(a, table, n, m);
	Myqueue.push(start);
	bfs(graph, n, m, start, finish);
	print_final_map(a, n, m, start);
	return 0;
}