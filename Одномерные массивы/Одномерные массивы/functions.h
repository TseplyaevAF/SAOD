#pragma once
#include <string>

// �������� ������������� ������� �������
float* create_array(unsigned n);

// �������� ������������� ������� ��������
float* create_array(unsigned n, int min_limit, int max_limit);

// ������ ������� � ����
void array2file(float* a, std::ofstream& f, unsigned n);

// ����� ������ ������������ ��������
unsigned short search_min(float* a, unsigned n);

// ���������� ����� ��������� �������, 
// ������������� ����� ������ � ������ �������������� ����������
float sum_elements(float *a, unsigned n);

// ���������� ���������. ������� �������� ������ ������� < 1, ����� ��� ���������
void sort_array(float *a, unsigned n);

// ������ ����������� � ���� �������� 8
void write2text(float* a, std::ofstream& f, unsigned n, unsigned min, float sum);

// ���-�� ��������� � ��������� �� A �� B
unsigned count_elements(float *a, unsigned n, int A, int B);

// ����� ��������� ����� max
float sum_elements_var13(float* a, unsigned n);

// ���������� ��������� �� �������� �������
void sort_array_var13(float* a, unsigned n);

// ������ ����������� � ���� �������� 13
void write2text_var13(float* a, std::ofstream& f, unsigned n, float sum);