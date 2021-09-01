#include <iostream>
#include <string>
#define N 100
using namespace std;

int n, m, start_X, start_Y, ans = 0;
int field[N][N] = { 0 };
string str = {};
string s1 = "";

//Select a number from string
int number(string str, int i) {
	int x = 0;
	while ((i != str.length()) && (str[i] > 47 && str[i] < 58)) {
		x = x * 10 + (str[i] - 48);
		i++;
	}
	return x;
}
//Shift after select
int new_index(int i, int x) {
	int c = 0;
	if (x == 0) c = 1;
	while (x != 0) {
		x /= 10;
		c++;
	}
	return c;
}

void input() {
	for (int i = 0; i < n; i++) {
		int k = 0;
		getline(cin, str);
		for (int j = 0; j < str.length(); j++) {
			if (str[j] == 'S') {
				start_X = k;
				start_Y = i;
				field[i][k++] = 0;
			}
			else if (str[j] != 32) {
				field[i][k] = number(str, j);
				j = j + new_index(j, field[i][k++]);
			}
		}
	}
}

void output() {
	cout << "Path:" << endl;
	int i = start_Y;
	int j = start_X;
	cout << "(" << i << "," << j << ") ";
	while (i != n - 1 || j != m - 1) {
		if (j + 1 < m && field[i][j + 1] >= field[i + 1][j]) 
			cout << "(" << i << "," << 1 + j++ << ") ";
		else if (i + 1 < n) 
			cout << "(" << 1 + i++ << "," << j << ") ";
	}
	cout << "\nCoins: " << ans;
}

int main() {
	cin >> n >> m;
	getline(cin, s1);
	input();
	int i = n - 1, j = m - 1;

	for (int x = m - 2; x >= start_X; x--)
		field[i][x] += field[i][x + 1];
	for (int y = n - 2; y >= start_Y; y--)
		field[y][j] += field[y + 1][j];
	i--;
	j--;

	while (i >= start_Y && j >= start_X) {
		for (int x = j; x >= start_X; x--) {
			if (field[i][x + 1] > field[i + 1][x]) field[i][x] += field[i][x + 1];
			else field[i][x] += field[i + 1][x];
		}
		for (int y = i - 1; y >= start_Y; y--) {
			if (field[y][j + 1] > field[y + 1][j]) field[y][j] += field[y][j + 1];
			else field[y][j] += field[y + 1][j];
		}
		i--;
		j--;
	}

	if (field[start_Y][start_X + 1] >= field[start_Y + 1][start_X]) ans = field[start_Y][start_X + 1];
	else ans = field[start_Y + 1][start_X];
	output();

	return 0;
}