#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "../funkcje.h"
#include "../struktury.h"

int main() {
	setlocale(LC_ALL, "pl_PL");
	printf("Zadanie3.\n");
	struct drzewo* drzewko = NULL;
	addTreeRekurencyjnie(&drzewko, 3);
	addTreeRekurencyjnie(&drzewko, 1);
	addTreeRekurencyjnie(&drzewko, 5);
	addTreeRekurencyjnie(&drzewko, 2);
	addTreeRekurencyjnie(&drzewko, 4);
	addTreeRekurencyjnie(&drzewko, 6);
	addTreeRekurencyjnie(&drzewko, 7);
	printf("drzewo przed prostowaniem:\n");
	wypiszDrzewko(drzewko);
	printf("drzewo po prostowaniu:\n");
	prostujDrzewko(&drzewko);
	wypiszDrzewko(drzewko);
	return 0;
}