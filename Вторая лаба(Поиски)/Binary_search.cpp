#include <iostream>

using namespace std;
const int N = 300;
int main()
{
	int a[N];
	int n, x, s = 0, mid;
	cin >> n;
	cin >> x;
	int e = n - 1;
	for (int i = 0; i < n; i++) cin >> a[i];
	cout << "Binary :\n";
	while (1) {
		mid = (s + e) / 2;
		cout << a[mid] << " " << x << endl;
		if (s >= e) return 0;
		if (a[mid] == x) return 0;
		if (a[mid] < x) s = mid + 1;
		else e = mid - 1;
	}
}