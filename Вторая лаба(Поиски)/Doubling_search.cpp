#include <iostream>

using namespace std;
const int N = 300;

void binary(int arr[], int s, int e, int x) {
	while (1) {
		int mid = (s + e) / 2;
		cout << arr[mid] << " " << x << endl;
		if (s >= e) {
			cout << "Target pos: " << mid;
			return;
		}
		if (arr[mid] == x) {
			cout << "Target pos: " << mid;
			return;
		}
		if (arr[mid] < x) s = mid + 1;
		else e = mid - 1;
	}
}
int main()
{
	int a[N];
	int n, x, s = 0, end, pos = 1, k = 1;
	cin >> n;
	cin >> x;
	for (int i = 0; i < n; i++) cin >> a[i];

	if (a[0] == x) {
		cout << a[0] << " " << x;
		cout << "\nTarget pos: " << 0;
		return 0;
	}

	while (k) {
		if (a[pos] < x && pos < n) pos *= 2;
		//Вывод, если target на четном индексе
		else if (a[pos] == x) {
			cout << a[pos] << " " << x;
			cout << "\nTarget pos: " << pos;
			return 0;
		}
		else k = 0;
	}

	if (pos > n - 1) end = n - 1;
	else end = pos;
	//cout << end << " " << pos / 2 << endl; Вывод pos и pos / 2
	binary(a, pos / 2, end, x);

	return 0;
}