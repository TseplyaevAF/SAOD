#include "Note.h"
#include <iomanip>

void createNote(Note* note, unsigned n) {
	for (size_t i = 0; i < n; i++)
	{
		cout << "������� ���: ";
		cin >> note[i].name;

		cout << "������� ����� ��������: ";
		cin >> note[i].tele;

		cout << "������� ���� �������� ����� ������: ";
		cin >> note[i].bday[0] >> note[i].bday[1] >> note[i].bday[2];

		cout << endl;
	}
}

void showNote(Note* note, unsigned n) {
	cout << "---------------------------------------" << endl;
	cout << "���" << "\t" << "\t" << "�������" << "\t" << "\t" <<
		"���� ��������" << "\n\n";
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
			cout << "���: " << note[i].name << endl;
			cout << "�������: " << note[i].tele << endl;
			cout << "���� ��������: " << note[i].bday[0] << "." <<
				note[i].bday[1] << "." << note[i].bday[2] << endl;
			cout << "---------------------------------------" << endl;
		}
	}

	if (!flag) cout << "�����, ���������� � ��������� ������, � ������ ���.";
}