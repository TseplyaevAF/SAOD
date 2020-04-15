#pragma once
#include <iostream>
#include <string>

using namespace std;

struct Note {
	char name[30],
		tele[11];
	unsigned bday[3];
};

void createNote(Note* note, unsigned n);
void showNote(Note* note, unsigned n);
void sortNote(Note* note, unsigned n);
void searchNote(Note* note, unsigned n, unsigned month);