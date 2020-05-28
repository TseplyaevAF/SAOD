#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	int n;
	ofstream f;
	f.open("result.txt", ios::out | ios::app);
	cout << "n= ";
	cin >> n;
	f << "n =" << n << endl;
	int* a = new int[n + 1];
	for (int i = 0; i < n + 1; i++)
		a[i] = i;
	for (int p = 2; p < n + 1; p++)
	{
		if (a[p] != 0)
		{
			f << a[p] << endl;
			for (int j = p * p; j < n + 1; j += p)
				a[j] = 0;
		}
	}
	f.close();
	cin.get(); cin.get();
	return 0;
}