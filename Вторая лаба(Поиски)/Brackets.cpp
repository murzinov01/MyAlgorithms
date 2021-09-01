#include<iostream>
#define M 3
using namespace std;

int search(char arr[], char x) {
	for (int i = 0; i < M; i++)
		if (arr[i] == x) return 1;
	return 0;
}

char U_turn(char x) {
	switch (x)
	{
	case ']': x = '[';
		break;
	case '}': x = '{';
		break;
	case ')': x = '(';
		break;
	}
	return x;
}

int main() {
	string a;
	string stack = {};
	char op_bracket[M] = { '[' , '{' , '(' }; // [ - 0   { - 1   ( - 2
	char cl_bracket[M] = { ']' , '}' , ')' }; // ] - 0   } - 1   ) - 2
	cin >> a;
	int end = 0;

	if (search(cl_bracket, a[0])) {
		cout << "Not balanced";
		return 0;
	}
	
	for (int i = 0; i < a.length(); i++) {
		if (search(op_bracket, a[i])) {
			stack.insert(end, 1, a[i]);
			end++;
		}
		else if (stack[end - 1] == U_turn(a[i])) {
			end--;
			stack.erase(end, 1);
		}
		else {
			cout << "Not balanced";
			return 0;
		}
	}

	if (end == 0) cout << "Balanced";
	else cout << "Not balanced";

	return 0;
}