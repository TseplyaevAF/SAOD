#include <iostream>
#include "Search.h"
#include <ctime>
#include <fstream>
#include "Sort.h"

using namespace std;

const int N = 5000;
const string filename = "result.txt";

struct MyStruct
{
	int a;
};

bool operator<(const MyStruct& a, const MyStruct& b)
{
	return a.a < b.a ? true : false;
}

int main()
{
	setlocale(0, "");
	unsigned int start_time, end_time; // для снятия временных показателей работы ф-ций
	ofstream fout;
	fout.open(filename, ios_base::app);
	int* arr1 = new int[N];
	int* arr2 = new int[N];
	int* arr3 = new int[N];
	int* arr4 = new int[N];
	int* arr5 = new int[N];
	cout << "N = " << N << endl;
	fout << "N = " << N << endl;
	int min = 0, max = 10000;

	MyStruct struct_array[3] = { {3},{5},{4} };
	// Сортировка элементов типа структуры
	bubbleSort(struct_array, 3);
	// Сортировка элементов вещественного типа
	float float_array[3] = { 1, 42.2, -3 };
	selectSort(float_array, 3);

	init_array(arr1, N, min, max);
	init_array(arr2, N, min, max);
	init_array(arr3, N, min, max);
	init_array(arr4, N, min, max);
	init_array(arr5, N, min, max);

	start_time = clock();
	bubbleSort(arr1, N);
	end_time = clock();
	cout << "Время сортировки \"пузырьком\": " <<
		((float)end_time - start_time) / CLOCKS_PER_SEC << " с " << endl;
	fout << "Время сортировки \"пузырьком\": " <<
		((float)end_time - start_time) / CLOCKS_PER_SEC << " с " << endl;

	start_time = clock();
	selectSort(arr2, N);
	end_time = clock();
	cout << "Время сортировки методом выбора: " <<
		((float)end_time - start_time) / CLOCKS_PER_SEC << " с " << endl;
	fout << "Время сортировки методом выбора: " <<
		((float)end_time - start_time) / CLOCKS_PER_SEC << " с " << endl;

	start_time = clock();
	insertSort(arr3, N);
	end_time = clock();
	cout << "Время сортировки методом вставок: " <<
		((float)end_time - start_time) / CLOCKS_PER_SEC << " с " << endl;
	fout << "Время сортировки методом вставок: " <<
		((float)end_time - start_time) / CLOCKS_PER_SEC << " с " << endl;

	start_time = clock();
	quickSort(arr4, 0, N - 1);
	end_time = clock();
	cout << "Время быстрой сортировки: " <<
		((float)end_time - start_time) / CLOCKS_PER_SEC << " с " << endl;
	fout << "Время быстрой сортировки: " <<
		((float)end_time - start_time) / CLOCKS_PER_SEC << " с " << endl;
	
	start_time = clock();
	shellSort(arr5, N);
	end_time = clock();
	cout << "Время сортировки Шелла: " <<
		((float)end_time - start_time) / CLOCKS_PER_SEC << " с " << endl;
	fout << "Время сортировки Шелла: " <<
		((float)end_time - start_time) / CLOCKS_PER_SEC << " с " << endl;

	//int* arr = new int[N];
	////show_array(arr, N);
	//int key;
	//cout << "Введите ключ: ";
	//cin >> key;
	//int pos = 0; // начать поиск с текущей позиции

	//unsigned int start_time = clock(); // начальное время
	//pos = linear_search(arr, N, pos, key);
	//unsigned int end_time = clock(); // конечное время

	//cout << "Время линейного поиска по ключу : " << setprecision(8) <<
	//	((double)end_time - start_time) / CLOCKS_PER_SEC << " с " << endl;
	//if (pos != -1) {
	//	cout << key << " имеет индекс: " << pos+1 << endl;
	//}
	//else {
	//	cout << "Элемент не найден" << endl;
	//}

	//cout << "-------------------------------------------------------" << endl;

	//bubbleSort(arr, N);

	////cout << "Отсортированный массив: " << endl;
	////show_array(arr, N);

	//start_time = clock();
	//pos = binary_search(arr, N, key);
	//end_time = clock();

	//cout << "Время бинарного поиска по ключу : " << setprecision(8) <<
	//	((double)end_time - start_time) / CLOCKS_PER_SEC << " с " << endl;
	//if (pos != -1) {
	//	cout << key << " имеет индекс: " << pos+1 << endl;
	//}
	//else {
	//	cout << "Элемент не найден" << endl;
	//}
	
	fout << endl;
	fout.close();
	delete[] arr1;
	delete[] arr2;
	delete[] arr3;
	delete[] arr4;
	delete[] arr5;
	system("pause");
	return 0;
}
