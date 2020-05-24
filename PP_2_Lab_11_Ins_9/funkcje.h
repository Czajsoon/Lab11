#ifndef _FUNKCJE_H_
#define _FUNKCJE_H_
struct drzewo* createTree(struct drzewo** pointer, int data);
void addTreeElementIteracyjnie(struct drzewo** pointer, int data);
void addTreeIteracyjnie(struct drzewo** pointer, int data);
void addTreeElementRekurencyjnie(struct drzewo** pointer, int data);
void addTreeRekurencyjnie(struct drzewo** pointer, int data);
void findAndPrintKey(struct drzewo* pointer, int data);
void PreOrder(struct drzewo* pointer);
void PostOrder(struct drzewo* pointer);
void InOrder(struct drzewo* pointer);
void BackwardInOrder(struct drzewo* pointer);
int wyskokoscDrzewa(struct drzewo* pointer);
void printPodanyPoziom(struct drzewo* pointer, int poziom);
void printLevelOrder(struct drzewo* pointer, int wysokosc);
void drzewkoSemiGraficzne(struct drzewo* pointer, int odstep);
void wypiszDrzewko(struct drzewo* pointer);
struct drzewo* rotacjaPrawaDrzewka(struct drzewo* pointer);
struct drzewo* rotacjaLewaDrzewka(struct drzewo* pointer);
void prostujDrzewko(struct drzewo** pointer);
void skaldaniedrzewa(struct drzewo** pointer);
#endif // !_FUNKCJE_H_