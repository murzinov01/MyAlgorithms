#include <stdio.h>
#define N 110 // число элементов
//Функция слияния
void merge(int arr[], int s, int mid, int e) {
	int mas[N] = { 0 };
	int i = s;
	int k = s;
	int j = mid + 1;

	while ((i <= mid) && (j <= e)) {
		if (arr[i] < arr[j]) {
			mas[k] = arr[i];
			i++;
		}
		else {
			mas[k] = arr[j];
			j++;
		}
		k++;
	}

	if (i <= mid)
		while (i <= mid) {
			mas[k] = arr[i];
			k++;
			i++;
		}

	if (j <= e)
		while (j <= e) {
			mas[k] = arr[j];
			k++;
			j++;
		}

	for (int p = s; p <= e; p++)
		arr[p] = mas[p];
	printf("\nMerged parts: ");
	for (int p = s; p <= e; p++) printf("%d ", arr[p]);
}

void merge_sort(int arr[], int s, int e) { //s - start, e - end
	if (s == e) //В том случае, если в массиве 1 элемент
		return;
	int mid;
	if ((s + e) % 2 == 0) mid = (s + e) / 2 - 1;
	else mid = (s + e) / 2;
	//Поиск середин
	merge_sort(arr, s, mid);

	merge_sort(arr, mid + 1, e);
	printf("\n\nLeft part: ");
	for (int i = s; i <= mid; i++) printf("%d ", arr[i]);
	printf("\nRight part: ");
	for (int i = mid + 1; i <= e; i++) printf("%d ", arr[i]);

	merge(arr, s, mid, e);// Вызов функции слияния
}

int main() {
	int a[N];
	int n;

	scanf("%d", &n);
	if (n <= 0) return 0;
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);

	printf("Initial array:\n");
	for (int i = 0; i < n; i++) printf("%d ", a[i]);

	merge_sort(a, 0, n - 1);
	return 0;
}