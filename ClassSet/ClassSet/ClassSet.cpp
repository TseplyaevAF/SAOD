#include "Set.h"
#include <iostream>
#include <fstream>

using namespace std;
const string FILE_NAME = "result.txt";

int main()
{
	ofstream out(FILE_NAME, ios::app);
	Set<int> set1;
	set1.insert(66);
	set1.insert(22);
	set1.insert(-124);
	set1.insert(36);
	out << "Заданный Set1 : ";
	set1.printFile(out);
	set1.print();

	Set<int> set2;
	set2.insert(32);
	set2.insert(41);
	set2.insert(21);
	set2.insert(36);
	set2.insert(99);
	out << "Заданный Set2 : ";
	set2.printFile(out);

	Set<int> set3 = set1.unification(set2);
	out << "Объединенный Set ";
	set3.printFile(out);

	set1.difference(set2);
	out << "Разность Set1 и Set2 : ";
	set1.printFile(out);
	out << endl;
	out << endl;
	system("pause");
	out.close();
}