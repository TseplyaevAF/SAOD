#include "module.h"
#include <random>
#include <ctime>

void init_dots(Point* point, int low, int high, int n) {
	srand(time(NULL));
	for (int i = 0; i < n; i++)
	{
		point[i].x = rand() % (high - low + 1) + low;
		point[i].y = rand() % (high - low + 1) + low;
	}
}

void write_dots_file(Point* point, int n, std::ofstream& f) {
	f << " Координаты точек:" << std::endl;
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

void choice_dots(Point* point, int& res1, int& res2, int r, int n, std::ofstream& f) {
	int rx, ry, high, low, res, i = 0, j = 0, t = 0;

	rx = 0; // x - координата центра круга
	ry = 0; // y - координата центра круга

	res = n + 1; // инициализация просто большим числом

	for (i = 0; i < n; i++) 
		if (pow(point[i].x - rx, 2) + pow(point[i].y - ry, 2) > (r* r))
			j++; // считаем точки вне круга

	if (j == n) {
		f << "Все точки вне круга!" << "\n";
		return;
	}

	for (i = 0; i < n-1; i++) // выборка двух точек из n без повторений
		for (j = i+1; j < n; j++)
		{
			high = 0; // начальные условия: high - для подсчёта точек выше прямой или справа, если
			low = 0; // прямая параллельна Oy; low - для подсчёта точек ниже и ,соответственно, слева
			for (t = 0; t < n; t++)
			{
				if (pow(point[t].x - rx, 2) + pow(point[t].y - ry, 2) < (r * r)) { // которые внутри круга
					if ((point[i].x == point[j].x) && (point[t].x > point[i].x)) high++; // прямая || Oy, точки справа
					if ((point[i].x == point[j].x) && (point[t].x < point[i].x)) low++; // прямая || Oy, точки слева

					if (point[i].x != point[j].x) { // прямая не||Oy, подставляем координаты в уравнение прямой
						if (point[t].y > ((point[i].y - point[j].y) / (point[i].x - point[j].x))
							* (point[t].x - point[i].x) + point[i].y) high++;

						if (point[t].y < ((point[i].y - point[j].y) / (point[i].x - point[j].x))
							* (point[t].x - point[i].x) + point[i].y) low++;
					}
				}
			}
			if (res > abs(high - low)) {// вычисляем разницу high - low по модулю 
				res = abs(high - low); // если меньше результата, полученного ранее
				res1 = i; // эти две точки будут новым решением
				res2 = j;
			}
		}
}