/*
 * Aufgabe1.cpp
 *
 *  Created on: Jun 4, 2016
 *      Author: nandi
 */

#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

struct lelem {
	int w;
	lelem * pNext;
};

class liste {
private:

	lelem * anchor;    // Zeiger auf den Beginn einer von liste verwalteten einfach verketteten Liste
public:

	liste();    // Konstruktor zum Konstruieren einer leeren Liste
	~liste();    // Destruktor, gibt den gesamten dynamisch angeforderten Speicherplatz frei

	void einfuegen(int x);    // einfuegen eines neuen Listenelementes
	int loeschen(int x);    // loeschen eines Listenelementes
	int count_wert(int wert, int & count);    // Auswertemethode
	int ausgabe_liste_datei(char * filename);    // Ausgabe aller Datenelemente der Liste in Datei
	friend ostream & operator <<(ostream & os, const liste & li);
};

liste::liste() {
	anchor = NULL;
}

liste::~liste() {

	lelem *head = anchor;
	lelem *tmp;

	while (head->pNext != NULL) {

		tmp = head;
		head = head->pNext;
		delete tmp;
	}
}

void liste::einfuegen(int x) {

	lelem *n = new lelem();
	n->w = x;
	n->pNext = NULL;

	//if list is leer
	if (anchor == NULL) {
		anchor = n;
		return;
	}

	lelem *p = anchor;
	while (p->pNext != NULL) {
		p = p->pNext;
	}

	p->pNext = n;

}

int liste::loeschen(int x) {

	lelem *p = anchor;
	lelem *pre = anchor;

	//if delete head
	if (p->w == x) {
		anchor = anchor->pNext;
		delete p;
		return 1;
	}

	while (p->pNext != NULL) {

		pre = p;
		p = p->pNext;
		if (p->w == x) {
			pre->pNext = p->pNext;
			delete p;
			return 1;
		}
	}

	return 0;
}

int liste::count_wert(int wert, int &count) {

	int c = 0;
	int ges_anz = 0;

	lelem *tmp = anchor;

	while (tmp != NULL) {

		if (tmp->w == wert) {
			c++;
		}

		tmp = tmp->pNext;
		ges_anz++;
	}
	count = c;

	return ges_anz;
}

int liste::ausgabe_liste_datei(char* filename) {

	FILE *fp;
	fp = fopen(filename, "w");
	if (fp == NULL) {
		return 0;
	}

	lelem *tmp = anchor;
	while (tmp != NULL) {
		char buffer[10];
		sprintf(buffer, "%d ", tmp->w);
		fputs(buffer, fp);
		tmp = tmp->pNext;
	}
	fclose(fp);
	return 1;
}

ostream & operator <<(ostream & os, const liste & li) {

	lelem *tmp = li.anchor;
	while (tmp != NULL) {
		os << tmp->w << " ";
		tmp = tmp->pNext;
	}
	return os;
}

int main(int argc, char **argv) {

	liste l;

	for (int i = 0; i < 20; ++i) {

		l.einfuegen(i);
	}

	cout << l << endl;
	char *name = "test";
	l.ausgabe_liste_datei(name);

	return 0;
}

