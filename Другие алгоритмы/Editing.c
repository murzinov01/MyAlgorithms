#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define N 100
#define M 20

int minimum(int a, int b, int c) {
	if (a < b && a < c) return a;
	else if (b < a && b < c) return b;
	else return c;
}

int editing(int n, int m, char s1[N], char s2[]) {
	int a[N][N];
	a[0][0] = 0;
	for (int i = 1; i <= n; i++) a[i][0] = a[i - 1][0] + 1;
	for (int j = 1; j <= m; j++) a[0][j] = a[0][j - 1] + 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (s1[i - 1] == s2[j - 1]) a[i][j] = a[i - 1][j - 1];
			else a[i][j] = minimum(a[i - 1][j] + 1, a[i][j - 1] + 1, a[i - 1][j - 1] + 1);
		}
	}
	return a[n][m];
}

void output(int distance[], int indexes[], char words[][M], int count) {
	int min = distance[0];
	for (int i = 1; i < count; i++)
		if (min > distance[i])
			min = distance[i];
	for (int i = 0; i < count; i++) 
		if (distance[i] == min) {
			for (int j = 0; j < indexes[i]; j++) printf("%c", words[i][j]);
			printf(" ");
		}
}

int main() {
	char s1[N];
	char s2[N];
	char words[N][M];
	int distance[N];
	int indexes[N] = { 0 };
	int n, m, count = 0, k = 0;
	gets(s1);
	gets(s2);
	m = strlen(s2);
	
	for (int i = 0; i < strlen(s1); i++) {
		if (s1[i] == ' ' || i == strlen(s1) - 1) {
			int flag = 0;
			if (s1[i - 1] == ',' || s1[i - 1] == '.' || s1[i - 1] == '?' || s1[i - 1] == '!') {
				flag = 1;
				i--;
			}
			if (i == strlen(s1) - 1 && (s1[i] != ',' && s1[i] != '.' && s1[i] != '?' && s1[i] != '!')) i++;
			char word[M];
			int x = k;
			for (int j = 0; j < i - k; j++) word[j] = s1[x++];
			for (int z = 0; z < i - k; z++) {
				words[count][z] = word[z];
			}
			indexes[count] = i - k;
			distance[count++] = editing(i - k, m, word, s2);
			if (flag) i++;
			k = i + 1;
		}
	}

	output(distance, indexes, words, count);
	
	return 0;
}