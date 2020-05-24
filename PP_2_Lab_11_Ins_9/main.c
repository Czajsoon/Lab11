#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include "funkcje.h"

int main() {
	setlocale(LC_ALL, "pl_PL");
	printf("Zadanie1.\n");
	struct drzewo* drzewko = NULL;
	addTreeRekurencyjnie(&drzewko, 10);
	addTreeRekurencyjnie(&drzewko, 10);
	addTreeRekurencyjnie(&drzewko, 11);
	addTreeRekurencyjnie(&drzewko, 10);
	addTreeRekurencyjnie(&drzewko, 4);
	addTreeRekurencyjnie(&drzewko, 3);
	addTreeRekurencyjnie(&drzewko, 5);
	addTreeRekurencyjnie(&drzewko, 4);
	addTreeRekurencyjnie(&drzewko, 6);
	findAndPrintKey(drzewko, 10);
	puts("");
	findAndPrintKey(drzewko, 11);
	puts("");
	findAndPrintKey(drzewko, 4);
	puts("");
	findAndPrintKey(drzewko, 3);
	puts("");
	findAndPrintKey(drzewko, 2);
	puts("");
	findAndPrintKey(drzewko, 80);
	puts("");
	findAndPrintKey(drzewko, 1);
	puts("");
	findAndPrintKey(drzewko, 5);
	puts("");
	printf("PreOrder: ");
	PreOrder(drzewko);
	puts("");
	printf("PostOrder: ");
	PostOrder(drzewko);
	puts("");
	printf("InOrder: ");
	InOrder(drzewko);
	puts("");
	printf("odwrotna kolejnosc InOrder: ");
	BackwardInOrder(drzewko);
	puts("");
	printf("LevelOrder\n");
	printLevelOrder(drzewko, wyskokoscDrzewa(drzewko));
	printf("Wysokoœæ drzewa to: %d", wyskokoscDrzewa(drzewko));
	puts("");
	wypiszDrzewko(drzewko);
	return 0;
}