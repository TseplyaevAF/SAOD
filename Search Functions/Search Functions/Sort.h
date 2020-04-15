#pragma once

// Сортировка методом "пузырька"
template< class T >
void bubbleSort(T* arr, int size)
{
	T tmp;

	for (int i = 0; i < size - 1; ++i) // i - номер прохода
	{
		for (int j = 0; j < size - 1; ++j) // внутренний цикл прохода
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

// Сортировка методом выбора
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

// Сортировка методом вставок
template< class T >
void insertSort(T* a, int size)
{
	int value, i_buf;
	for (int i = 1; i < size; i++)
	{
		value = a[i]; // значение текущего элемента
		i_buf = i; // индекс текущего элемента
		// просматриваем все предшествующие элементы упорядоченной последовательности
		// пока не будет найден элемент со значением больше текущего
		while ((i_buf > 0) && (a[i_buf - 1] > value))
		{
			a[i_buf] = a[i_buf - 1]; // ставим найденный элемент на место текущего
			i_buf--; // переходим к след. элементу в упорядоченной последовательности
		}
		a[i_buf] = value;
	}
}

// Быстрая сортировка
template<class T>
void quickSort(T* a, int left, int right) {
	int pivot; // разрешающий элемент
	int l_hold = left; //левая граница
	int r_hold = right; // правая граница
	pivot = a[left];
	while (left < right) // пока границы не сомкнутся
	{
		while ((a[right] >= pivot) && (left < right))
			right--; // сдвигаем правую границу пока элемент [right] больше [pivot]
		if (left != right) // если границы не сомкнулись
		{
			a[left] = a[right]; // перемещаем элемент [right] на место разрешающего
			left++; // сдвигаем левую границу вправо
		}
		while ((a[left] <= pivot) && (left < right))
			left++; // сдвигаем левую границу пока элемент [left] меньше [pivot]
		if (left != right) // если границы не сомкнулись
		{
			a[right] = a[left]; // перемещаем элемент [left] на место [right]
			right--; // сдвигаем правую границу вправо
		}
	}
	a[left] = pivot; // ставим разрешающий элемент на место
	pivot = left;
	left = l_hold;
	right = r_hold;
	if (left < pivot) // Рекурсивно вызываем сортировку для левой и правой части массива
		quickSort(a, left, pivot - 1);
	if (right > pivot)
		quickSort(a, pivot + 1, right);
}

// Сортировка Шелла
template< class T >
void shellSort(T *a, long size)
{
	int increment = 3;    // начальное приращение сортировки
	while (increment > 0)  // пока существует приращение
	{
		for (int i = 0; i < size; i++)  // для всех элементов массива
		{
			int j = i;          // сохраняем индекс и элемент
			int temp = a[i];
			// просматриваем остальные элементы массива, отстоящие от j-ого
			// на величину приращения
			while ((j >= increment) && (a[j - increment] > temp))
			{  // пока отстоящий элемент больше текущего
				a[j] = a[j - increment]; // перемещаем его на текущую позицию
				j = j - increment;       // переходим к следующему отстоящему элементу
			}
			a[j] = temp; // на выявленное место помещаем сохранённый элемент
		}
		if (increment > 1)      // делим приращение на 2
			increment = increment / 2;
		else if (increment == 1)   // последний проход завершён,
			break;  // выходим из цикла
	}
}