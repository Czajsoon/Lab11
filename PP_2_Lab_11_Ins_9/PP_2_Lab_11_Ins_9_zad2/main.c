#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "../funkcje.h"

int main() {
	setlocale(LC_ALL, "pl_PL");
	printf("Zadanie2.\n");
	struct drzewo* drzewko = NULL;
	addTreeRekurencyjnie(&drzewko, 4);
	addTreeRekurencyjnie(&drzewko, 2);
	addTreeRekurencyjnie(&drzewko, 5);
	addTreeRekurencyjnie(&drzewko, 1);
	addTreeRekurencyjnie(&drzewko, 3);
	wypiszDrzewko(drzewko);
	drzewko = rotacjaPrawaDrzewka(drzewko);
	printf("drzewko po rotacji w prawo\n");
	wypiszDrzewko(drzewko);
	printf("drzewko po rotacji w lewo\n");
	drzewko = rotacjaLewaDrzewka(drzewko);
	wypiszDrzewko(drzewko);
	return 0;
}