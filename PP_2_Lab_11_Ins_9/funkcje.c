#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include "struktury.h"
#define LICZNIK 10

struct drzewo* createTree(struct drzewo** pointer, int data) {
	struct drzewo* nowy = (struct drzewo*)malloc(sizeof(struct drzewo));
	nowy->data = data;
	nowy->pLewy = nowy->pPrawy = NULL;
	*pointer = nowy;
	return *pointer;
}

void addTreeElementIteracyjnie(struct drzewo** pointer, int data) {
	struct drzewo* nowy = (struct drzewo*)malloc(sizeof(struct drzewo));
	nowy->data = data;
	nowy->pLewy = nowy->pPrawy = NULL;
	struct drzewo* ptr = *pointer;
	while (ptr) {
		if (data >= ptr->data) {
			if (ptr->pPrawy)
				ptr = ptr->pPrawy;
			else {
				ptr->pPrawy = nowy;
				return;
			}
		}
		else {
			if (ptr->pLewy)
				ptr = ptr->pLewy;
			else {
				ptr->pLewy = nowy;
				return;
			}
		}
	}
}

void addTreeIteracyjnie(struct drzewo** pointer, int data) {
	if (*pointer)
		addTreeElementIteracyjnie(pointer, data);
	else
		*pointer = createTree(pointer, data);
}

void addTreeElementRekurencyjnie(struct drzewo** pointer, int data) {
	struct drzewo* ptr = *pointer;
	if (ptr) {
		if (data >= ptr->data) {
			if (ptr->pPrawy)
				addTreeElementRekurencyjnie(&ptr->pPrawy, data);
			else {
				struct drzewo* nowy = (struct drzewo*)malloc(sizeof(struct drzewo));
				nowy->data = data;
				nowy->pPrawy = nowy->pLewy = NULL;
				ptr->pPrawy = nowy;
			}
		}
		else {
			if (ptr->pLewy)
				addTreeElementRekurencyjnie(&(*pointer)->pLewy, data);
			else {
				struct drzewo* nowy = (struct drzewo*)malloc(sizeof(struct drzewo));
				nowy->data = data;
				nowy->pLewy = nowy->pPrawy = NULL;
				ptr->pLewy = nowy;
			}
		}
	}
}

void addTreeRekurencyjnie(struct drzewo** pointer, int data) {
	if (*pointer)
		addTreeElementRekurencyjnie(pointer, data);
	else
		*pointer = createTree(pointer, data);
}

void findAndPrintKey(struct drzewo* pointer, int data) {
	struct drzewo* ptr = pointer;
	if (ptr) {
		if (ptr->data == data)
			printf("Znaleziono klucz! %d", ptr->data);
		else {
			if (data > ptr->data)
				findAndPrintKey(ptr->pPrawy, data);
			else
				findAndPrintKey(ptr->pLewy, data);
		}
	}
	else
		printf("Takiej wartoœci nie ma w drzewie %d", data);
}

void PreOrder(struct drzewo* pointer) {
	if (pointer) {
		printf("%d ", pointer->data);
		PreOrder(pointer->pLewy);
		PreOrder(pointer->pPrawy);
	}
}

void PostOrder(struct drzewo* pointer) {
	if (pointer) {
		PostOrder(pointer->pLewy);
		PostOrder(pointer->pPrawy);
		printf("%d ", pointer->data);
	}
}

void InOrder(struct drzewo* pointer) {
	if (pointer) {
		InOrder(pointer->pLewy);
		printf("%d ", pointer->data);
		InOrder(pointer->pPrawy);
	}
}

void BackwardInOrder(struct drzewo* pointer) {
	if (pointer) {
		BackwardInOrder(pointer->pPrawy);
		printf("%d ", pointer->data);
		BackwardInOrder(pointer->pLewy);
	}
}

int wyskokoscDrzewa(struct drzewo* pointer) {
	if (!pointer)
		return 0;
	else {
		int lWysokosc = wyskokoscDrzewa(pointer->pLewy);
		int pWysokosc = wyskokoscDrzewa(pointer->pPrawy);

		if (lWysokosc > pWysokosc)
			return lWysokosc + 1;
		else
			return pWysokosc + 1;
	}
}

void printPodanyPoziom(struct drzewo* pointer, int poziom) {
	if (pointer == NULL)
		return;
	if (poziom == 1)
		printf("%d ", pointer->data);
	else if (poziom > 1)
	{
		printPodanyPoziom(pointer->pLewy, poziom - 1);
		printPodanyPoziom(pointer->pPrawy, poziom - 1);
	}
}

void printLevelOrder(struct drzewo* pointer, int wysokosc) {
	int h = wysokosc;
	for (int i = 1; i <= h; i++) {
		printPodanyPoziom(pointer, i);
		puts("");
	}
}

void drzewkoSemiGraficzne(struct drzewo* pointer, int odstep) {
	if (!pointer) return;
	odstep += LICZNIK;
	drzewkoSemiGraficzne(pointer->pPrawy, odstep);
	printf("\n");
	for (int i = LICZNIK;i < odstep;i++)
		printf(" ");
	printf("[%d]\n", pointer->data);
	drzewkoSemiGraficzne(pointer->pLewy, odstep);
}

void wypiszDrzewko(struct drzewo* pointer) {
	drzewkoSemiGraficzne(pointer, 0);
}

struct drzewo* rotacjaPrawaDrzewka(struct drzewo* pointer) {
	struct drzewo* lewy = pointer->pLewy;
	pointer->pLewy = lewy->pPrawy;
	lewy->pPrawy = pointer;
	return lewy;
}

struct drzewo* rotacjaLewaDrzewka(struct drzewo* pointer) {
	struct drzewo* prawy = pointer->pPrawy;
	pointer->pPrawy = prawy->pLewy;
	prawy->pLewy = pointer;
	return prawy;
}

void prostujDrzewko(struct drzewo** pointer) {
	if (*pointer) {
		if ((*pointer)->pLewy) {
			*pointer = rotacjaPrawaDrzewka(*pointer);
			prostujDrzewko(pointer);
		}
		else
			prostujDrzewko(&(*pointer)->pPrawy);
	}
}

