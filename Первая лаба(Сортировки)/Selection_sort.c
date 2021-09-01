#include <stdio.h>
#define N 10 // Количество элементов массива
#define M 100 // Диапозон (от 0 до M - 1)
int main() {
	int arr[N];
	int c = 0, n = 0;
	printf("Unsorted Array: ");
	for (int i = 0; i < N; i++) {
		arr[i] = rand() % M;
		printf("%d ", arr[i]);
	}
	//Сортировка методом вставки
	for (int i = 1; i < N; i++)
	{
		n = arr[i];
		c = i - 1;
		while (arr[c] > n) {
			arr[c + 1] = arr[c];
			c--;
		}
		arr[c + 1] = n;
	}
	printf("\n\n");
	printf("Sorted Array:   ");
	//Вывод массива на экран
	for (int i = 0; i < N; i++)
		printf("%d ", arr[i]);

	return 0;
}