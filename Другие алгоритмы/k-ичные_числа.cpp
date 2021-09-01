#include <iostream>
#define N 1000
using namespace std;

int main() {
	int a[N];
	int n, k, ans;
	cin >> n >> k;
	a[1] = k - 1;
	a[0] = 0;
	for (int i = 2; i <= n; i++)
		a[i] = a[i - 2] * (k - 1) + a[i - 1] * (k - 1);
	ans = a[n] + a[n - 1];
	cout << ans;
	return 0;
}