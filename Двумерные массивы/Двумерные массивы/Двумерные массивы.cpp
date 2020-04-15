#include <iostream>
#include "work.h"

using namespace std;

int main()
{
	setlocale(0, "RUS");
	//size_t n, m;
	//cout << "Введите кол-во строк и столбцов матрицы: ";
	//cin >> n >> m;
	vector<vector<int>> a
		= { {1, 2, 3, 4, 5},
	{-3, 18, -24, -79, 30},
	{3, -17, -23, -71, -9},
	{2, 8, 4, -5, 6}, };
	//a = create_vector(n, m);
	ofstream f;
	size_t variant;
	cout << "Введите номер варианта: ";
	cin >> variant;
	if (variant == 8) {
		f.open("8 задание.txt", ios_base::out);
		f << "Исходная матрица: " << "\n";
		matrix2file(a, f);
		sum_elements_var8(a, f);
		a = characteristic_column_var8(a, f);
		f.close();
	}
	else
		if (variant == 13) {
			const int count = 3;

			f.open("13 задание, сдвиг вправо.txt", ios_base::out);
			f << "Исходная матрица: " << "\n";
			matrix2file(a, f);
			f << "После сдвига вправо на " << count << " позиции: " << "\n";
			cyclic_shift_right(a, count, f);
			f.close();

			f.open("13 задание, сдвиг вниз.txt", ios_base::out);
			f << "Исходная матрица: " << "\n";
			matrix2file(a, f);
			f << "После сдвига вниз на " << count << " позиции: " << "\n";
			cyclic_shift_down(a, count, f);
			f.close();
		}
		else cout << "Такого варианта нет!";

	system("pause");
	return 0;
}
