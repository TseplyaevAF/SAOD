#pragma once
#include <vector>
#include <fstream>

using vector_int = std::vector<std::vector<int>>;

// �������� ������� � ���������� ���������� ������� �� min_limit �� max_limit
vector_int create_vector(unsigned n, unsigned m, int min_limit, int max_limit);

// �������� ������� � ���������� �������
vector_int create_vector(unsigned n, unsigned m);

//������ ������� � ����
void matrix2file(vector_int a, std::ofstream& f);


// ������� 8, �������������� ��������
vector_int characteristic_column_var8(vector_int a, std::ofstream& f);

// ������� 8, ����� ���������
void sum_elements_var8(vector_int a, std::ofstream& f);

// ������� ������ ����������
void swap(int &a, int &b);

// ������� 13, ����������� ����� ������
void cyclic_shift_right(vector_int a, unsigned count, std::ofstream& f);

// ������� 13, ����������� ����� ����
void cyclic_shift_down(vector_int a, unsigned count, std::ofstream& f);