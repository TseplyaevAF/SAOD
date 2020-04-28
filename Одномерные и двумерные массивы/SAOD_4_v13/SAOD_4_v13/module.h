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

// определяет, пересекается прямая с окружностью или нет
bool intersects(Point a, Point b, Circle c);

//  иницализация n точек в пределе от low до high
void init_dots(Point* point, int low, int high, int n);

//  иницализация n окружностей в пределе от low до high
void init_circle(Circle* circle, int low, int high, int n);

// вывод координат точек в файл
void write_dots_file(Point* point, int n, std::ofstream& f);

// вывод параметров окружностей точек в файл
void write_circle_file(Circle* circle, int n, std::ofstream& f);