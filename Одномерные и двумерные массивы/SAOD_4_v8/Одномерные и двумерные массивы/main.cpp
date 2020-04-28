#include <iostream>
#include "module.h"

using namespace std;

const string filename = "result.txt";
const unsigned n = 5; // число точек
const unsigned r = 8; // радиус круга

int main()
{
	setlocale(0, "RUS");
	Point point[n];
	ofstream f;
	int low = -10, high = 10, dot1, dot2;
	f.open(filename, ios::app);

	init_dots(point, low, high, n);
	write_dots_file(point, n, f);
	choice_dots(point, dot1, dot2, r, n, f);

	f << "Выбранные точки:" << std::endl;
	f << "(" << point[dot1].x << "; " << point[dot1].y << ")" << std::endl;
	f << "(" << point[dot2].x << "; " << point[dot2].y << ")" << std::endl;

	f.close();

	system("pause");
	return 0;
}
