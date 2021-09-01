#include <stdio.h>
#include <math.h>
#define N 101

int main() {
	int number, f, n;

	//Счетчики в корзинах
	int counters[2 * N] = { 0 };

	float min, max, c;
	float a[N];
	float buck[2 * N][N] = { 0 };
	scanf("%d", &n);
	if (n <= 0) return 0;
	for (int i = 0; i < n; i++) scanf("%f", &a[i]);

	printf("Initial array:\n");
	for (int i = 0; i < n; i++) printf("%.2f ", a[i]);

	max = a[0];
	min = a[0];

	//Поиск максимума и минимума 
	for (int i = 1; i < n; i++) {
		if (a[i] > max)
			max = a[i];
		if (a[i] < min)
			min = a[i];
	}

	//Распределение по корзинам
	for (int i = 0; i < n; i++) {
		number = (a[i] - min) * 2 * n / (max - min);
		if (number == 2 * n) number--;
		buck[number][counters[number]] = a[i];
		counters[number]++;
	}

	//Сортировка в корзинах
	for (int i = 0; i < 2 * n; i++)
	{
		if (counters[i] != 0) {
			printf("\n\nBucket:\n");
			for (int j = 0; j < counters[i]; j++) printf("%.2f ", buck[i][j]);

			for (int j = 0; j < counters[i] - 1; j++)
			{
				min = buck[i][j];
				for (int l = j; l < counters[i]; l++)
					if (buck[i][l] <= min) {
						min = buck[i][l];
						f = l;
					}
				c = buck[i][j];
				buck[i][j] = buck[i][f];
				buck[i][f] = c;
			}

			printf("\nSorted bucket:\n");
			for (int j = 0; j < counters[i]; j++) printf("%.2f ", buck[i][j]);
		}
	}

	printf("\n\nFinal array:\n");
	//	Вывод отсортированного массива
	for (int i = 0; i < 2 * n; i++) {
		for (int j = 0; j < counters[i]; j++)
			printf("%.2f ", buck[i][j]);
	}

	return 0;
}