#ifndef CALCLIB_H
#define CALCLIB_H

#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif
void printString(char*);
void readString(char*);
char forDigit(int nombre,int base);
int digit(char caractere,int base);
int toInt(int nombre,int base,char *res);
int parseInt(char *ch,int base,int *resultat);
int inverse8bits(int nbr);
int inverse16bits(int nbr);
int rotationGauche(int nbr);
int rotationDroite(int nbr);
int operation(char op);
int calcul(int n1,int n2,int *resultat,int operation);
void calculatrice(int n1,int n2, int resultat,int base);
#ifdef __cplusplus
}
#endif

#endif // CALCLIB_H
