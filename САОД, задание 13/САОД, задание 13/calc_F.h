#pragma once

// ������� F1 � F2 ��������� �������������� ����� a,b,c,
// ������� [x; x_n] � ��� dx - ��������������
// � ���������� ����������� ��������
float F1(float a, float b, float c, float &x, float x_n, float dx);

float F2(float a, float b, float c, float& x, float x_n, float dx);

// ������� ���������� ��������������� ����� � ������
void to_int(float &a, float &b, float &c);

// ��������� ��� �������� ���������� ������� (������� 13)
bool expression1(float a, float b, float c);

// ��������� ��� �������� ���������� ������� (������� 8)
bool expression2(float a, float b, float c);