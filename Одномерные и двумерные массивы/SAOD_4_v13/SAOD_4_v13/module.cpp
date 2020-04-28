#include "module.h"
#include <random>
#include <ctime>

bool intersects(Point a, Point b, Circle c) {
	float s, ab, h;
	/*строим треугольник на точках прямой о центре окружности
	определяем его площадь, длину стороны на прямой и высоту на нее*/
	s = abs(a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y));
	ab = sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
	h = s / ab;

	// если высота меньше радиуса, перемекаются
	return h < c.r;
}

void init_dots(Point* point, int low, int high, int n) {
	srand(time(NULL));
	for (int i = 0; i < n; i++)
	{
		point[i].x = rand() % (high - low + 1) + low;
		point[i].y = rand() % (high - low + 1) + low;
	}
}

void init_circle(Circle* circle, int low, int high, int n) {
	srand(time(NULL));
	for (int i = 0; i < n; i++)
	{
		circle[i].x = rand() % (high - low + 1) + low;
		circle[i].y = rand() % (high - low + 1) + low;
		circle[i].r = rand() % 5 * high;
	}
}

void write_dots_file(Point* point, int n, std::ofstream& f) {
	f << "Координаты точек:" << std::endl;
	f << "X: ";
	for (int i = 0; i < n; i++)
	{
		f << point[i].x << "  ";
	}
	f << std::endl;
	
	f << "Y: ";
	for (int i = 0; i < n; i++)
	{
		f << point[i].y << "  ";
	}
	f << "\n\n";
}

void write_circle_file(Circle* circle, int n, std::ofstream& f) {
	f << "Параметры окружностей:" << std::endl;
	f << "X: ";
	for (int i = 0; i < n; i++)
	{
		f << circle[i].x << "  ";
	}
	f << std::endl;

	f << "Y: ";
	for (int i = 0; i < n; i++)
	{
		f << circle[i].y << "  ";
	}
	f << std::endl;

	f << "R: ";
	for (int i = 0; i < n; i++)
	{
		f << circle[i].r << "  ";
	}
	f << "\n\n";
}