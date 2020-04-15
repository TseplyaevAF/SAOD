#pragma once
#include <iostream>
#include <string>

using namespace std;

// ���������, ����������� �����
struct Train {
	char destination[30]; // ����� ����������
	char departure_time[10]; // ����� �����������
	int number; // ����� ������
};

void createArray(Train train[], unsigned n); // �������� ������� �� ��������� ���������
void write_to_file(Train train[], std::ofstream& f, unsigned n);
void read_file(Train train[], std::ifstream& f);
void showTrain(Train train[], unsigned n); // ����� ��������� ��������� �� �������
void sortTrain(Train train[], unsigned count); // ���������� �� ������� ����������� �������
void searchTrain(Train train[], unsigned n, string destination); // ����� �������
unsigned time2minutes(string time); //�������������� ������� � ������