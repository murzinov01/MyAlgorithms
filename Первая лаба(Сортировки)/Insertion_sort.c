#include <stdio.h>
#define N 120// Количество элементов массива
int main() {
	int arr[N];
	int m, k, n;

	scanf("%d", &n);
	if (n <= 0) return 0;
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	printf("Initial array:\n");

	for (int i = 0; i < n; i++) printf("%d ", arr[i]);
	printf("\n");
	//Сортировка методом вставки
	for (int i = 1; i < n; i++)
	{
		m = i;
		while ((m - 1) >= 0 && arr[m] < arr[m - 1]) {
			k = arr[m - 1];
			arr[m - 1] = arr[m];
			arr[m] = k;
			m--;
		}

		printf("Insertion - Element #%d\n", i);
		for (int i = 0; i < n; i++) printf("%d ", arr[i]);
		printf("\n");
	}

	return 0;
}