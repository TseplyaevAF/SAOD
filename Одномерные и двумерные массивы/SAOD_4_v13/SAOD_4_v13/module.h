#pragma once
#include <fstream>

struct Point {
	float x;
	float y;
};

struct Circle {
	float x;
	float y;
	float r;
};

// ����������, ������������ ������ � ����������� ��� ���
bool intersects(Point a, Point b, Circle c);

//  ������������ n ����� � ������� �� low �� high
void init_dots(Point* point, int low, int high, int n);

//  ������������ n ����������� � ������� �� low �� high
void init_circle(Circle* circle, int low, int high, int n);

// ����� ��������� ����� � ����
void write_dots_file(Point* point, int n, std::ofstream& f);

// ����� ���������� ����������� ����� � ����
void write_circle_file(Circle* circle, int n, std::ofstream& f);