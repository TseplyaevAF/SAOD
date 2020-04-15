#pragma once

// ��������� ������� ��������� ������ ��������� � ������� �� �����
// ������ ������ ���������� ��������
template <class T>
int linear_search(T* arr, int n, int start, T key) {

	for (int i = start; i < n; i++)
	{
		if (arr[i] == key) {
			return i;
		}
	}
	return -1;
}

// ��������� ������� ��������� ������ ��������� � ������� �� �����
// ������ ������ ���������� ��������
template <class T>
int binary_search(T* arr, int n, T key) {
	int left = 0; // ������ ����� � ������ ������� ������
	int right = n-1;
	//std::vector<int> vec = {-1};
	while (left <= right) // ���� ����� ������� �� "����������" ������
	{
		int mid = (left + right) / 2; // ���� �������� �������
		if (key == arr[mid]) {  // ���� �������� ���� ����� ��������
			return mid; // �� ����� ��������� �������
		}
		if (key < arr[mid])     // ���� ������� �������� ���� ������ ��������� ��������
			right = mid - 1;  // ������� ������ �������, ��������� ����� � ����� �����
		else                  // �����
			left = mid + 1;   // ������� ����� �������, ��������� ����� � ������ �����
	}
	return -1;
}

// ���������� ������� ���������� �������
void init_array(int* array, int n, int min, int max);

// ���������� ������� �������
void init_array(int* array, int n);

// ����� ������� � �������
void show_array(int* array, int n);