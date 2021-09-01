#include <stdio.h>
#define N 101 // Число элементов массива
void quick_sort(int arr[], int n, int s, int e) {
	if (s >= e)
		return;

	int bufL[N] = { 0 };
	int bufR[N] = { 0 };
	int med = (s + e) / 2;
	int k = s;
	int j = s;
	int l = s;
	printf("\n\nPivot index: %d , pivot element: %d", med, arr[med]);
	//Заполнение буфера числами до медианы 
	for (int i = s; i < med; i++)
		if (arr[i] <= arr[med]) {
			bufL[k] = arr[i];
			k++;
		}
		else {
			bufR[j] = arr[i];
			j++;
		}
	//Заполнение буфера числами после медианы
	for (int i = med + 1; i <= e; i++)
		if (arr[i] <= arr[med]) {
			bufL[k] = arr[i];
			k++;
		}
		else {
			bufR[j] = arr[i];
			j++;
		}
	//Перенос медианы в буфер
	bufL[k] = arr[med];
	//Сложение буферных массивов в основной массив
	for (int i = s; i <= k; i++)
		arr[i] = bufL[i];
	if (j != l)
		for (int i = k + 1; i <= e; i++) {
			arr[i] = bufR[l];
			l++;
		}
	printf("\nArray after partition: ");
	for (int i = 0; i < n; i++) printf("%d ", arr[i]);
	quick_sort(arr, n, s, k - 1); //Рекурсия по левой части от медианы
	quick_sort(arr, n, k + 1, e); //Рекурсия по правой части от медианы

}int main() {
	int a[N];
	int n;
	scanf("%d", &n);
	if (n <= 0) return 0;
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	printf("Initial array:\n");
	for (int i = 0; i < n; i++) printf("%d ", a[i]);
	quick_sort(a, n, 0, n - 1);
	return 0;
}