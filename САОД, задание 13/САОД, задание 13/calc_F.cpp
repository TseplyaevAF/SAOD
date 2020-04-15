#include "calc_F.h"
#include <cmath>

void to_int(float& a, float& b, float& c) {
	a = int(a);
	b = int(b);
	c = int(c);
}

float F1(float a, float b, float c, float &x, float x_n, float dx) {
	if ((x - 1 < 0) && (b - x != 0)) return a * pow(x, 2) + b;
	else if ((x - 1 > 0) && (b + x == 0)) return (x - a) / x;
	else return x / c;
}

float F2(float a, float b, float c, float& x, float x_n, float dx) {
	if ((c < 0) && (a != 0)) return -a * x * x;
	else if ((c > 0) && (a == 0)) return (a - x) / c * x;
	else return x / c;
}

bool expression1(float a, float b, float c) {
	return ((int)a | (int)b) ^ (int(b) & int(c));
}

bool expression2(float a, float b, float c) {
	return ((int)a ^ (int)b) & ~(int(b) | int(c));
}