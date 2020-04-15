#include <iostream>
#include "Train.h"
#include <windows.h>
#include "Note.h"
#include <fstream>

const unsigned m = 5;
const unsigned n = 3;

int main()
{
	setlocale(0, "RUS");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	unsigned number;
	cout << "Номер задания: ";
	cin >> number;

	if (number == 8) {
		Train trains[n];
		char c;
		cout << "Создать новый массив? (Y/N):";
		cin >> c;
		if (c == 'Y') {
			createArray(trains, n);
			ofstream f("trains.dat", ios::binary);
			write_to_file(trains, f, n);
			f.close();
		} else {
			ifstream f("trains.dat");
			read_file(trains, f);
			f.close();
		}

		sortTrain(trains, n);
		showTrain(trains, n);
		string destination;
		cout << "Введите пункт для поиска поездов: ";
		cin >> destination;

		searchTrain(trains, n, destination);
	}
	else if (number == 13) {

		Note blocknote[m];
		createNote(blocknote, m);
		cout << "После сортировки записей по алфавиту: " << endl;
		sortNote(blocknote, m);
		showNote(blocknote, m);
		unsigned month;
		cout << "Введите месяц: ";
		cin >> month;

		searchNote(blocknote, m, month);
	}
	else {
		cout << "...";
	}

	system("pause");
	return 0;
}