#include "functions.h"

unsigned long Fib_Rec(unsigned N) 
{
	return N < 2 ? 1 : Fib_Rec(N - 1) + Fib_Rec(N - 2);
}

unsigned long Fib_It(unsigned N) {
	unsigned first_pred = 1, // первое предыдущее число
		second_pred = 0; // второе предыдущее число
	unsigned long sum = 0;
	for (unsigned i = 0; i < N; i++)
	{
		sum = first_pred + second_pred;
		first_pred = second_pred;
		second_pred = sum;
	}
	return sum;
}