#include <iostream>
#include "module.h"

using namespace std;

const string filename = "result.txt";
const unsigned n = 5; // множество точек
const unsigned m = 8; // множество окружностей

int main()
{
	setlocale(0, "");
	Point point[n];
	Circle circle[m];
	ofstream f;
	int low = -10, high = 10;
	f.open(filename, ios::out);

	init_dots(point, low, high, n);
	write_dots_file(point, n, f);
	init_circle(circle, low, high, m);
	write_circle_file(circle, m, f);

	int mx, imx, jmx, k;
	mx = 0;
	imx = 0;
	jmx = 0;

	for (int i = 0; i < n-1; i++)
		for (int j = i+1; j < n; j++)
		{
			k = 0;
			for (int p = 0; p < m; p++)
			{
				if (intersects(point[i], point[j], circle[p])) k++;
				if (k > mx) {
					mx = k;
					imx = i;
					jmx = j;
				}
			}
		}
	if (mx == 0) f << "Нет пересекающихся прямых и окружностей" << "\n\n";
	else {
		f << "Максимальное число пересечений прямой с окружностями=" << mx << endl;
		f << "Эта прямая проходит через точки(" << point[imx].x << "; " << point[imx].y << ") и (" <<
			point[jmx].x << "; " << point[jmx].y << ")";
	}

	f.close();
	system("pause");
	return 0;
}
