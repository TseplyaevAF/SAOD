#include "Train.h"
#include <iomanip>
#include <fstream>

void createArray(Train train[], unsigned n) {
	
	for (unsigned i = 0; i < n; i++) {
		cout << "Введите название пункта назначения: ";
		cin >> train[i].destination;
		cout << "Введите номер поезда: ";
		cin >> train[i].number;
		cout << "Введите время отправления в формате ЧЧ:мм : ";
		cin >> train[i].departure_time;
		cout << endl;
	}
}

void write_to_file(Train train[], std::ofstream &f, unsigned n) {
	for (size_t i = 0; i < n; i++)
	{
		f.write((char*)&train[i], sizeof(Train));
	}
}

void read_file(Train train[], std::ifstream& f) {
	Train buf;
	short i = 0;
	while (true) {
		f.read((char*)&buf, sizeof(Train));
		if (f.eof()) break;
		train[i] = buf;
		i++;
	}
}

unsigned time2minutes(string time) {
	int min;
	string num1 = time.substr(0, 2);
	string num2 = time.substr(3,2 );

	min = 60 * atoi(num1.c_str()) + atoi(num2.c_str());

	return min;
}

void sortTrain(Train train[], unsigned count) {
	Train tmp;
	for (int i = 0; i < count - 1; ++i)
	{
		for (int j = 0; j < count - 1; ++j)
		{
			if (time2minutes(train[j + 1].departure_time) < time2minutes(train[j].departure_time))
			{
				tmp = train[j + 1];
				train[j + 1] = train[j];
				train[j] = tmp;
			}
		}
	}
}

void showTrain(Train train[], unsigned n) {
	cout << "Номер поезда" << "\t" << "Пункт назначения" << "\t" <<
		"Время отправления" << endl;
	for (size_t i = 0; i < n; i++)
	{
		cout << train[i].number << '\t' << setw(20) << train[i].destination << "\t" << setw(20) <<
			train[i].departure_time;
		cout << endl;
	}
}

void searchTrain(Train train[], unsigned n, string destination) {
	bool flag = false;

	for (size_t i = 0; i < n; i++)
	{
		if (train[i].destination == destination) {
			flag = true;
			cout << "Информация о поезде: " << endl;
			cout << "---------------------------------------" << endl;
			cout << "Номер поезда: " << train[i].number << endl;
			cout << "Пункт назначения: " << train[i].destination << endl;
			cout << "Время отправления" << train[i].departure_time << endl;
			cout << "---------------------------------------" << endl;
		}
	}

	if (!flag) cout << "Поездов, направляющихся в " + destination + " нет." << endl;
}