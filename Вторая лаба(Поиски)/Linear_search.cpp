#include <iostream>

using namespace std;
const int N = 300;
int main()
{
	int a[N];
	int n, x;
	//int j;
	cin >> n;
	cin >> x;
	for (int i = 0; i < n; i++) cin >> a[i];
	cout << "Linear :\n";
	for (int i = 0; i < n; i++) {
		if (a[i] == x) {
			cout << x;
			//j = i;
			return 0;
		}
		cout << a[i] << " ";
	}
	//	cout << " Target: " << j;
	return 0;
}