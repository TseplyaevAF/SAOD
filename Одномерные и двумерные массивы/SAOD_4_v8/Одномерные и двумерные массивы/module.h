#pragma once
#include <fstream>

struct Point {
	int x;
	int y;
};

//  ������������ n ����� � ������� �� low �� high
void init_dots(Point *point, int low, int high, int n); 

// ����� ��������� ����� � ����
void write_dots_file(Point *point, int n, std::ofstream &f);

// ������� ������ �����
// res1, res2 - ���������� ��� ������ ����������
// r - ������ �����
void choice_dots(Point* point, int& res1, int& res2, int r, int n, std::ofstream& f);