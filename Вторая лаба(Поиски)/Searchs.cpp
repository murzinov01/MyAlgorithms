#include <iostream>

using namespace std;
const int N = 300;

void binary(int arr[], int s, int e, int x) {
	while (1) {
		int mid = (s + e) / 2;
		if (e - s == 1 && x < arr[s])
		{
			cout << arr[s] << " ";
			return;
		}
		if (s >= e) {
			cout << arr[s] << " ";
			return;
		}
		if (arr[mid] == x) {
			cout << x << " ";
			return;
		}
		cout << arr[mid] << " ";
		if (arr[mid] < x) s = mid + 1;
		else e = mid - 1;
	}
}

void Linear(int a[], int n, int x) {
	cout << "\nLinear search:\n";
	for (int i = 0; i < n; i++) {
		if (a[i] == x) {
			cout << x << " ";
			return;
		}
		cout << a[i] << " ";
	}
}

void Doubling(int a[], int n, int x) {
	int s = 0, end, pos = 1, k = 1;
	cout << "\nDoubling search:\n";
	if (a[0] == x) {
		binary(a, 0, 1, x);
		return;
	}
	if (a[pos] == x) {
		cout << a[pos] << " ";
		return;
	}
	while (k) {
		if (a[pos] < x && pos < n) pos *= 2;
		//Вывод, если target на четном индексе
		else if (a[pos] == x) {
			cout << a[pos] << " ";
			return;
		}
		else k = 0;
	}
	if (a[0] > x) binary(a, 0, pos, x);
	else if (pos > n - 1 && n > 2) binary(a, pos / 2 + 1, n - 1, x);
	//else if (pos > n - 1 && n == 2) binary(a, 1, n - 1, x);
	else if (pos > n - 1 && n == 1) {
		cout << a[0] << " ";
		return;
	}
	else if (pos <= n - 1) binary(a, pos / 2 + 1, pos - 1, x);
}

int main()
{
	int a[N];
	int n, x;
	cin >> n;
	cin >> x;
	for (int i = 0; i < n; i++) cin >> a[i];
	cout << "Initial array:\n";
	for (int i = 0; i < n; i++) cout << a[i] << " ";
	Linear(a, n, x);
	cout << "\nBinary search:\n";
	binary(a, 0, n - 1, x);
	Doubling(a, n, x);
	return 0;
}