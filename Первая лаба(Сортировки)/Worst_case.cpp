#include<iostream>
using namespace std;
const int N = 101; //Количество элементов массива
//Worst Case
void WorstCase(int arr[], int e) {
	int k = 0, c = 0;
	int buf[N];
	int worst_index[N];

	for (int i = 0; i < e + 1; i++) buf[i] = arr[i];//Перезапись массива в буфер
	//Сортировка буфера
	for (int i = 1; i < e + 1; i++)
	{
		k = buf[i];
		c = i - 1;
		while (buf[c] > k) {
			buf[c + 1] = buf[c];
			c--;
		}
		buf[c + 1] = k;
	}
	//Запись индексов в Worst Case
	worst_index[0] = e / 2;
	int r = 1;
	if (e % 2 == 0) {
		for (int i = 1; i < e; i += 2) {
			worst_index[i] = worst_index[0] + r;
			r++;
		}
		r = -1;
		for (int i = 2; i < e + 1; i += 2) {
			worst_index[i] = worst_index[0] + r;
			r--;
		}
	}
	else {
		for (int i = 1; i < e + 1; i += 2) {
			worst_index[i] = worst_index[0] + r;
			r++;
		}
		r = -1;
		for (int i = 2; i < e; i += 2) {
			worst_index[i] = worst_index[0] + r;
			r--;
		}
	}

	//Перезапись из буфера в основной массив
	int j = 0;
	for (int i = e; i >= 0; i--) {
		arr[worst_index[j]] = buf[i];
		j++;
	}
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

int main() {

	int a[N];
	int n;
	cin >> n;
	//Создание массива + вывод
	for (int i = 0; i < n; i++) a[i] = i + 1;

	WorstCase(a, n - 1);
	if (n % 2 != 0) swapArray(a,0,n-1);
	//Вывод Worst Case
	for (int i = 0; i < n; i++) cout << a[i] << " ";

	return 0;
}