#include <stdio.h>
#define N 30 //Количество элементов массива
#define M 100 // Диапозон( от 0 до M)
int main() {
	int arr[N];
	int c = 0, n = 0, p = 1;
	printf("Unsorted Array: ");
	for (int i = 0; i < N; i++) {
		arr[i] = rand() % M;
		printf("%d ", arr[i]);
	}
	//Сортировка пузырьком
	for (int i = 1; i < N; i++)
	{
		n = i;
		while (arr[n] < arr[n - p])
		{
			c = arr[n];
			arr[n] = arr[n - p];
			arr[n - p] = c;
			n--;
		}
	}
	printf("\n\n");
	printf("Sorted Array:   ");
	//Вывод массива на экран
	for (int i = 0; i < N; i++)
		printf("%d ", arr[i]);

	return 0;
}