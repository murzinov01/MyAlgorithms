#include<iostream>
#define N 100
#define M 3
using namespace std;


int number(string str, int i, int n) {
	int x = 0;
	while ((i != n) && (str[i] > 47 && str[i] < 58)) {
		x = x * 10 + (str[i] - 48);
		i++;
	}
	return x;
}

int new_index(int i, int x) {
	int c = 0;
	if (x == 0) c = 1;
	while (x != 0) {
		x /= 10;
		c++;
	}
	return c;
}

int set_priority(char x) {
	if (x == '+' || x == '-') return 1;
	else if (x == '*' || x == '/') return 2;
	else return -1;
}

int result(int a, int b, char c) {
	switch (c)
	{
	case '+': return a + b;
	case '-': return a - b;
	case '*': return a * b;
	case '/': return a / b;
	}
}

int main() {
	string a = {};
	int stack_num[N];
	int mas[N];
	string stack_opp = {};
	string RPN = {};
	int i = 0, j = 0, k = 0, z = 0, u = 0, p = 0;
	cin >> a;
	cout << "Expression:" << endl;
	for (int i = 0; i < a.length(); i++) cout << a[i];
	//Проверка на дурака
	int durak = 0;
	for (int i = 0; i < a.length(); i++)
		if (a[i] > 47 && a[i] < 58) durak = 1;
	if (durak == 0) return 0;

	while (i != a.length()) {
		//Если это число, то добавляем его в стэк чисел
		if (a[i] > 47 && a[i] < 58) {
			int l = i;
			stack_num[k] = number(a, i, a.length());
			i = i + new_index(i, stack_num[k]);
			mas[u] = new_index(i, stack_num[k]);
			u++;
			for (int j = l; j < i; j++) {
				RPN.insert(z, 1, a[j]);
				z++;
			}
			k++;
		}
		//Если это знак операции
		else if (a[i] != 40 && a[i] != 41) {
			//Если стэк пуст
			if (j == 0) {
				stack_opp.insert(j, 1, a[i]);
				j++;
				i++;
			}
			//Если приоритет операции больше, чем приоритет операции в стэке
			else if (set_priority(a[i]) > set_priority(stack_opp[j - 1])) {
				stack_opp.insert(j, 1, a[i]);
				j++;
				i++;
			}
			//Если приоритет операции меньше, чем приоритет операции в стэке
			else {
				while (j >= 1 && set_priority(a[i]) <= set_priority(stack_opp[j - 1])) {
					RPN.insert(z, 1, stack_opp[j - 1]);
					stack_num[k - 2] = result(stack_num[k - 2], stack_num[k - 1], stack_opp[j - 1]);
					stack_opp.erase(j - 1, 1);
					j--;
					k--;
					z++;
				}
				stack_opp.insert(j, 1, a[i]);
				j++;
				i++;
			}
		}
		//Если открывающаяся скобочка
		else if (a[i] != 41) {
			stack_opp.insert(j, 1, a[i]);
			j++;
			i++;
		}
		//Если закрывающаяся скобочка
		else {
			while (stack_opp[j - 1] != '(') {
				RPN.insert(z, 1, stack_opp[j - 1]);
				stack_num[k - 2] = result(stack_num[k - 2], stack_num[k - 1], stack_opp[j - 1]);
				stack_opp.erase(j - 1, 1);
				j--;
				k--;
				z++;
			}
			stack_opp.erase(j - 1, 1);
			j--;
			i++;
		}
	}
	//Когда строка закончилась
	while (j != 0) {
		RPN.insert(z, 1, stack_opp[j - 1]);
		stack_num[k - 2] = result(stack_num[k - 2], stack_num[k - 1], stack_opp[j - 1]);
		stack_opp.erase(j - 1, 1);
		j--;
		k--;
		z++;
	}
	cout << "\nReverse Polish Notation:\n";
	u = 0;

	while (p != RPN.length()) {
		if (RPN[p] > 47 && RPN[p] < 58) {
			for (int j = 0; j < mas[u]; j++) {
				cout << RPN[p];
				p++;
			}
			cout << " ";
			u++;
		}
		else {
			cout << RPN[p] << " ";
			p++;
		}
	}
	cout << "\nResult:\n" << stack_num[k - 1];
	return 0;
}