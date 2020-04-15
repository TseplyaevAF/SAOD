#pragma once
#include <iostream>
#include <string>

using namespace std;

// структура, описывающая поезд
struct Train {
	char destination[30]; // пункт назначения
	char departure_time[10]; // время отправления
	int number; // номер поезда
};

void createArray(Train train[], unsigned n); // создание массива из элементов структуры
void write_to_file(Train train[], std::ofstream& f, unsigned n);
void read_file(Train train[], std::ifstream& f);
void showTrain(Train train[], unsigned n); // вывод элементов структуры на консоль
void sortTrain(Train train[], unsigned count); // сортировка по времени отправления поездов
void searchTrain(Train train[], unsigned n, string destination); // поиск поездов
unsigned time2minutes(string time); //преобразование времени в минуты