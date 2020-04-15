#pragma once

// ���������� ������� "��������"
template< class T >
void bubbleSort(T* arr, int size)
{
	T tmp;

	for (int i = 0; i < size - 1; ++i) // i - ����� �������
	{
		for (int j = 0; j < size - 1; ++j) // ���������� ���� �������
		{
			if (arr[j + 1] < arr[j])
			{
				tmp = arr[j + 1];
				arr[j + 1] = arr[j];
				arr[j] = tmp;
			}
		}
	}
}

// ���������� ������� ������
template< class T >
void selectSort(T* arr, int size)
{
	unsigned i_buf;
	T tmp;
	for (unsigned i = 0; i < size - 1; i++)
	{
		i_buf = i;
		for (unsigned j = i + 1; j < size; j++)
			if (arr[j] < arr[i_buf]) i_buf = j;

		if (i_buf != i) {
			tmp = arr[i];
			arr[i] = arr[i_buf];
			arr[i_buf] = tmp;
		}
	}
}

// ���������� ������� �������
template< class T >
void insertSort(T* a, int size)
{
	int value, i_buf;
	for (int i = 1; i < size; i++)
	{
		value = a[i]; // �������� �������� ��������
		i_buf = i; // ������ �������� ��������
		// ������������� ��� �������������� �������� ������������� ������������������
		// ���� �� ����� ������ ������� �� ��������� ������ ��������
		while ((i_buf > 0) && (a[i_buf - 1] > value))
		{
			a[i_buf] = a[i_buf - 1]; // ������ ��������� ������� �� ����� ��������
			i_buf--; // ��������� � ����. �������� � ������������� ������������������
		}
		a[i_buf] = value;
	}
}

// ������� ����������
template<class T>
void quickSort(T* a, int left, int right) {
	int pivot; // ����������� �������
	int l_hold = left; //����� �������
	int r_hold = right; // ������ �������
	pivot = a[left];
	while (left < right) // ���� ������� �� ���������
	{
		while ((a[right] >= pivot) && (left < right))
			right--; // �������� ������ ������� ���� ������� [right] ������ [pivot]
		if (left != right) // ���� ������� �� ����������
		{
			a[left] = a[right]; // ���������� ������� [right] �� ����� ������������
			left++; // �������� ����� ������� ������
		}
		while ((a[left] <= pivot) && (left < right))
			left++; // �������� ����� ������� ���� ������� [left] ������ [pivot]
		if (left != right) // ���� ������� �� ����������
		{
			a[right] = a[left]; // ���������� ������� [left] �� ����� [right]
			right--; // �������� ������ ������� ������
		}
	}
	a[left] = pivot; // ������ ����������� ������� �� �����
	pivot = left;
	left = l_hold;
	right = r_hold;
	if (left < pivot) // ���������� �������� ���������� ��� ����� � ������ ����� �������
		quickSort(a, left, pivot - 1);
	if (right > pivot)
		quickSort(a, pivot + 1, right);
}

// ���������� �����
template< class T >
void shellSort(T *a, long size)
{
	int increment = 3;    // ��������� ���������� ����������
	while (increment > 0)  // ���� ���������� ����������
	{
		for (int i = 0; i < size; i++)  // ��� ���� ��������� �������
		{
			int j = i;          // ��������� ������ � �������
			int temp = a[i];
			// ������������� ��������� �������� �������, ��������� �� j-���
			// �� �������� ����������
			while ((j >= increment) && (a[j - increment] > temp))
			{  // ���� ��������� ������� ������ ��������
				a[j] = a[j - increment]; // ���������� ��� �� ������� �������
				j = j - increment;       // ��������� � ���������� ���������� ��������
			}
			a[j] = temp; // �� ���������� ����� �������� ���������� �������
		}
		if (increment > 1)      // ����� ���������� �� 2
			increment = increment / 2;
		else if (increment == 1)   // ��������� ������ ��������,
			break;  // ������� �� �����
	}
}