#include <stdio.h>
#define N 100

int main() {
	int array[N] = { 0 };
	int mas[10];
	//Задание массива с клавиатуры
	for (int i = 0; i < 10; i++)
		scanf("%d", &mas[i]);
	//Подсчет элементов массива mas
	for (int i = 0; i < 10; i++)
		array[mas[i]]++;
	//Вывод на экран
	for (int i = 0; i < N; i++)
		if (array[i] != 0)
			for (int j = 0; j < array[i]; j++)
				printf("%d ", i);
	return 0;
}