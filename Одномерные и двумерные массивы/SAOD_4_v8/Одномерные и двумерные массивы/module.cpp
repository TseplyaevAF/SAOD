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
	f << "����������� �����:" << std::endl;
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

	rx = 0; // x - ���������� ������ �����
	ry = 0; // y - ���������� ������ �����

	res = n + 1; // ������������� ������ ������� ������

	for (i = 0; i < n; i++) 
		if (pow(point[i].x - rx, 2) + pow(point[i].y - ry, 2) > (r* r))
			j++; // ������� ����� ��� �����

	if (j == n) {
		f << "��� ����� ��� �����!" << "\n";
		return;
	}

	for (i = 0; i < n-1; i++) // ������� ���� ����� �� n ��� ����������
		for (j = i+1; j < n; j++)
		{
			high = 0; // ��������� �������: high - ��� �������� ����� ���� ������ ��� ������, ����
			low = 0; // ������ ����������� Oy; low - ��� �������� ����� ���� � ,��������������, �����
			for (t = 0; t < n; t++)
			{
				if (pow(point[t].x - rx, 2) + pow(point[t].y - ry, 2) < (r * r)) { // ������� ������ �����
					if ((point[i].x == point[j].x) && (point[t].x > point[i].x)) high++; // ������ || Oy, ����� ������
					if ((point[i].x == point[j].x) && (point[t].x < point[i].x)) low++; // ������ || Oy, ����� �����

					if (point[i].x != point[j].x) { // ������ ��||Oy, ����������� ���������� � ��������� ������
						if (point[t].y > ((point[i].y - point[j].y) / (point[i].x - point[j].x))
							* (point[t].x - point[i].x) + point[i].y) high++;

						if (point[t].y < ((point[i].y - point[j].y) / (point[i].x - point[j].x))
							* (point[t].x - point[i].x) + point[i].y) low++;
					}
				}
			}
			if (res > abs(high - low)) {// ��������� ������� high - low �� ������ 
				res = abs(high - low); // ���� ������ ����������, ����������� �����
				res1 = i; // ��� ��� ����� ����� ����� ��������
				res2 = j;
			}
		}
}