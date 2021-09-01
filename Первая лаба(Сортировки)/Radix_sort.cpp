#include<iostream>
using namespace std;
const int N = 101; //Число элементов
const int A = 16; //Алфавит
int main() {

	string a[N] = {}; //Основной массив
	string buf[N] = {}; //Буфер
	int mas[A + 1][N] = { -1 }; //"Таблица с индексами"
	int schet[A + 1] = { 0 }; // "Счетчики
	unsigned int maxLength = 0;
	unsigned int r = 1; //Отвечает за сдвиг по разряду
	string index = "0123456789ABCDEF"; //Массив для поиска индекса
	int n;

	cin >> n;
	//Ввод массива с клавиатуры
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (a[i].length() > maxLength) maxLength = a[i].length();
	}

	//Сортировка
	while (maxLength != 0) {
		//Заполнение двумерного массива индексами элементов основного массива
		for (int i = 0; i < n; i++) {
			int pos = 0;
			if (a[i].length() >= r) {
				pos = index.find(a[i][a[i].length() - r]) + 1;
				mas[pos][schet[pos]] = i;
			}
			else {
				mas[pos][schet[pos]] = i;
			}
			schet[pos]++;
		}

		//Заполнение буферного массива в порядке возрастания в разряде
		//Одновременно "обнуление" двумерного массива
		int l = 0; //Счетчик буфера
		for (int i = 0; i < A + 1; i++)
			for (int j = 0; j < schet[i]; j++)
			{
				buf[l] = a[mas[i][j]];
				mas[i][j] = -1;
				l++;
			}
		//Обнуление массива счетчиков
		for (int i = 0; i < A + 1; i++)
			schet[i] = 0;
		//Перезаполнение основного массива из буфера
		for (int i = 0; i < n; i++)
			a[i] = buf[i];
		r++;//Сдвиг по разряду влево

		cout << "Sorting by " << maxLength - 1 << " digit:" << endl;
		for (int i = 0; i < n; i++) cout << a[i] << endl;
		cout << endl;

		maxLength--;
	}
	return 0;
}