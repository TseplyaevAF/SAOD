#include <iostream>
#include "Queue.h"
#include <iomanip>
#include <random>

using namespace std;

enum DigitKind { ones, tens };

void Distribute(int L[], Queue<int> digitQueue[], int n,
	DigitKind kind)
{
	int i;
	// цикл для массива из п элементов
	for (i = 0; i < n; i++)
		if (kind == ones)
			// вычислить цифру единиц и использовать ее как номер очереди
			digitQueue[L[i] % 10].QInsert(L[i]);
		else
			// вычислить цифру десятков и использовать ее как номер очереди
			digitQueue[L[i] / 10].QInsert(L[i]);
}

// собрать элементы из очередей в массив
void Collect(Queue<int> digitQueue[], int L[])
{
	int i = 0, digit = 0;
	// сканировать массив очередей,
	// используя индексы 0, 1, 2, и т.д.
	for (digit = 0; digit < 10; digit++)
		// собирать элементы, пока очередь не опустеет,
		// копировать элементы снова в массив
		while (!digitQueue[digit].QEmpty())
			L[i++] = digitQueue[digit].QDelete();
}

// сканировать массив из п элементов и печатать каждый элемент.
// в каждой строке печатать 10 элементов
void PrintArray(int L[], int n)
{
	int i = 0;
	while (i < n)
	{
		cout.width(5);
		cout << L[i];
		if (++i % 10 == 0)
			cout << endl;
	}
	cout << endl;
}

int main()
{
	setlocale(0, "");
	// 10 десять очередей для моделирования бункеров
	Queue<int> digitQueue[10];
	// массив из 50 целых
	int L[50];
	int i = 0;
	// инициализировать массив случайными числами
	// в диапазоне 0-99
	for (i = 0; i < 50; i++)
		L[i] = 0 + rand() % 100;
	// распределить в 10 бункеров по цифрам единиц;
	// собрать и распечатать
	Distribute(L, digitQueue, 50, ones);
	Collect(digitQueue, L);
	cout << "После сортировки по позициям единиц: " << endl;
	PrintArray(L, 50);
	// распределить в 10 бункеров по цифрам десятков;
	// собрать и распечатать отсортированный массив
	Distribute(L, digitQueue, 50, tens);
	Collect(digitQueue, L);
	cout << "После сортировки по позициям десяток: " << endl;
	PrintArray(L, 50);

	system("pause");
	return 0;
}