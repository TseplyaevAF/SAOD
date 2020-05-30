#include <iostream>
#include "String.h"

using namespace std;

// возвращает символ первого вхождения строки str в строку pattern
// поиск осуществляется, начиная с позиции startindex
int FindPat(String pattern, String str, int startindex)
{
	//первый символ подстроки
	char firstChar = str.getSymbol(0);
	//длина подстроки
	int length = str.getSize();
	//временная строка для проверки
	String searchStr;

	for (int i = startindex; i < pattern.getSize(); i++)
	{
		//Поиск в строке символа совпадающего с первым символом подстроки
		if (pattern.getSymbol(i) == firstChar)
		{
			//При нахождении символа, с текущей позиции
			//из строки выделяется подстрока длинной length
			searchStr = pattern.Substr(i, length);
			//Если выделенная подстрока совпадает 
			//с подстрокой, которую нужно найти
			//происходит возврат индекса, с которого эта подстрока начинается
			if (searchStr == str)
				return i;
		}
	}
	//В случае неудачи происходит возврат -1
	return -1;
}


int main()
{
	setlocale(0, "");

	// определить строку-образец и строку для поиска
	String pattern, str;
	//
	int startindex = 0, // поиск подстроки с текущего индекса
		index = 0, // индекс, с которого подстрока начинается в исходной строке
		count = 0; // кол-во вхождений подстроки в строку
	cout << "Введите подстроку для поиска: ";
	str.ReadString();
	cout << "Введите строку:" << endl;
	pattern.ReadString();
	while (startindex < pattern.getSize()) {
		index = FindPat(pattern, str, startindex);
		if (index == -1)
			break;
		startindex = index + 1;
		count++;
	}
	cout << "Исходная строка: " << pattern.getStr() << endl;
	cout << "Подстрока \"" << str.getStr() << "\" встречалась " << count << " раз(а) \n\n";

	system("pause");
	return 0;
}
