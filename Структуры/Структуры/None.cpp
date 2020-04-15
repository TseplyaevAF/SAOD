#include "Note.h"
#include <iomanip>

void createNote(Note* note, unsigned n) {
	for (size_t i = 0; i < n; i++)
	{
		cout << "Введите имя: ";
		cin >> note[i].name;

		cout << "Введите номер телефона: ";
		cin >> note[i].tele;

		cout << "Введите дату рождения через пробел: ";
		cin >> note[i].bday[0] >> note[i].bday[1] >> note[i].bday[2];

		cout << endl;
	}
}

void showNote(Note* note, unsigned n) {
	cout << "---------------------------------------" << endl;
	cout << "Имя" << "\t" << "\t" << "Телефон" << "\t" << "\t" <<
		"Дата рождения" << "\n\n";
	for (size_t i = 0; i < n; i++)
	{
		cout << note[i].name << '\t' << setw(10) << note[i].tele << "\t" << setw(5) <<
			note[i].bday[0] << "." << note[i].bday[1] << "." << note[i].bday[2]; ;
		cout << endl;
	}
	cout << "---------------------------------------" << endl;
}

void sortNote(Note* note, unsigned n) {
	Note buf;
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
			if (strcmp(note[i].name, note[j].name) > 0)
			{
				buf = note[i];
				note[i] = note[j];
				note[j] = buf;
			}
}

void searchNote(Note* note, unsigned n, unsigned month) {
	bool flag = false;

	for (size_t i = 0; i < n; i++)
	{
		if (note[i].bday[1] == month) {
			flag = true;
			cout << "---------------------------------------" << endl;
			cout << "Имя: " << note[i].name << endl;
			cout << "Телефон: " << note[i].tele << endl;
			cout << "Дата рождения: " << note[i].bday[0] << "." <<
				note[i].bday[1] << "." << note[i].bday[2] << endl;
			cout << "---------------------------------------" << endl;
		}
	}

	if (!flag) cout << "Людей, родившихся в указанном месяце, в списке нет.";
}