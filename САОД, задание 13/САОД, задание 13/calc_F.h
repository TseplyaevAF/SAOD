#pragma once

// Функции F1 и F2 принимают действительные числа a,b,c,
// отрезок [x; x_n] и шаг dx - действительные
// и возвращают вычисленное значение
float F1(float a, float b, float c, float &x, float x_n, float dx);

float F2(float a, float b, float c, float& x, float x_n, float dx);

// Функция приведения действительного числа к целому
void to_int(float &a, float &b, float &c);

// Выражение для проверки начального условия (Задание 13)
bool expression1(float a, float b, float c);

// Выражение для проверки начального условия (Задание 8)
bool expression2(float a, float b, float c);