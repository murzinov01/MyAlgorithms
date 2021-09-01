#include <iostream>
#include <string>
#include <math.h>
#include <limits>
#define N 100
using namespace std;

string s[N] = {};
string s1 = "";
string target = "";
string towns[N];
int coor[N][2];
int graph[N][N] = { 0 };
int n, townI = 0, coorJ = 0, current_town = 0;;

int number(string str, int i, int n) {
	int x = 0;
	while ((i != n) && (str[i] > 47 && str[i] < 58)) {
		x = x * 10 + (str[i] - 48);
		i++;
	}
	return x;
}

int new_index(int i, int x) {
	int c = 0;
	if (x == 0) c = 1;
	while (x != 0) {
		x /= 10;
		c++;
	}
	return c;
}

int search_town(string word, int counter) {
	if (counter == 0) return 0;
	for (int i = 0; i < counter; i++) if (towns[i].find(word) != -1) return 1;
	return 0;
}

int search_index_of_town(string word, int counter) {
	for (int i = 0; i < counter; i++) if (towns[i].find(word) != -1) return i;
}

void create_towns_and_graph() {
	for (int i = 0; i < n; i++) {
		int start = -1, finish = -1, current_town = -1;
		int end = 0;
		if (s[i][s[i].length() - 1] == 32) end = s[i].length() - 1;
		else end = s[i].length();
		for (int j = 0; j < end; j++) {
			if (start < 0 && s[i][j] != 32 && (s[i][j] > 57 || s[i][j] < 48)) start = j;
			else if (s[i][j] != 32 && (s[i][j] > 57 || s[i][j] < 48) && (j == s[i].length() - 1 || s[i][j + 1] == 32)) {
				finish = j;
				string word = {};
				int h = start;
				for (int z = 0; z <= finish - start; z++) {
					word.insert(z, 1, s[i][h]);
					h++;
				}
				if (search_town(word, townI) == 0) {
					towns[townI] = word;
					if (current_town == -1) current_town = townI;
					graph[current_town][townI] = 1;
					townI++;
				}
				else {
					if (current_town == -1) current_town = search_index_of_town(word, townI);
					graph[current_town][search_index_of_town(word, townI)] = 1;
				}
				start = -1;
				finish = -1;
			}
		}
	}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) if (i == j) graph[i][j] = 0;
}

void create_coor() {
	for (int i = 0; i < n; i++) {
		for (int k = 0; k < n; k++) {
			int finish = -1;
			for (int u = 0; u < s[k].length(); u++) if (s[k][u + 1] == 32) {
				finish = u;
				break;
			}
			string word = "";
			for (int z = 0; z <= finish; z++) word.insert(z, 1, s[k][z]);
			if (towns[i] == word) {
				for (int j = 0; j < s[k].length(); j++) {
					if (s[k][j] > 47 && s[k][j] < 58) {
						int x = number(s[k], j, s[k].length());
						j = j + new_index(j, x);
						coor[i][coorJ] = x;
						coorJ++;
					}
				}
				coorJ = 0;
				break;
			}
		}
	}
}

int get_start() {
	string word = "";
	for (int i = 0; i < target.length(); i++) {
		if (target[i] != 32) word.insert(i, 1, target[i]);
		else break;
	}
	for (int i = 0; i < n; i++) {
		if (towns[i].find(word) != -1) return i;
	}
}

int get_finish() {
	int space = 0;
	for (int i = 0; i < target.length(); i++)
		if (target[i] == 32) {
			space = i;
			break;
		}
	string finish = "";
	int k = 0;
	for (int j = space + 1; j < target.length(); j++) {
		finish.insert(k, 1, target[j]);
		k++;
	}

	for (int i = 0; i < n; i++) {
		if (towns[i].find(finish) != -1) return i;
	}
}

int search(double a[], int used[], int n) {
	double min = std::numeric_limits<int>::max();
	int k = -1;
	for (int i = 0; i < n; i++)
		if (used[i] == 0 && a[i] < min) {
			min = a[i];
			k = i;
		}
	if (k == -1) return -1;
	else return k;
}

int used_lenght(int a[], int n) {
	int k = 0;
	for (int i = 0; i < n; i++) if (a[i] == 1) k++;
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

void ways(int p[], int n, int j, int start) {
	int a[N] = { 0 };
	int i = 0;
	while (1) {
		if (p[j] == 0 && start == j) {
			a[i] = j;
			i++;
			break;
		}
		a[i] = j;
		i++;
		j = p[j];
	}
	swapArray(a, 0, i - 1);
	for (int k = 0; k < i; k++) cout << towns[a[k]] << " ";
}

int main() {
	double branchs[N][N];
	double d[N];
	int p[N] = { 0 };
	int used[N] = { 0 };
	int start = 0, finish = 0;
	cin >> n;
	getline(cin, s1);
	for (int i = 0; i < n; i++) {
		getline(cin, s[i]);
	}
	getline(cin, target);

	create_towns_and_graph();
	create_coor();

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			if (graph[i][j] == 0) branchs[i][j] = -1;
			else branchs[i][j] = (double)sqrt((coor[i][0] - coor[j][0]) * (coor[i][0] - coor[j][0]) + (coor[i][1] - coor[j][1]) * (coor[i][1] - coor[j][1]));		
		}

	start = get_start();
	finish = get_finish();

	int schet = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) if (graph[i][j] == 1) schet++;
	schet = schet / 2 + 1;
	for (int i = 0; i < n; i++) d[i] = std::numeric_limits<int>::max();
	d[start] = 0;
	while (used_lenght(used, n) != n) {
		int i = search(d, used, n);
		if (i == -1) break;
		double w = d[i];
		for(int j = 0; j < n; j++){
			if (graph[i][j] == 1) {
				if (float(branchs[i][j] + w) < d[j]) {
					d[j] = float(branchs[i][j] + w);
					p[j] = i;
				}
			}
		}
		used[i] = 1;
	}
	if (d[finish] != std::numeric_limits<int>::max()) {
		cout << "Path is not greater than " << ceil(d[finish]) << endl;
		cout << "Path:\n";
		ways(p, n, finish, start);
	}
	else cout << "Path:\nNo way";
	return 0;
}