#ifndef ROLETA_H
#define ROLETA_H

#include <iostream>

struct no {
    int info;
    struct no * prox;
};
typedef struct no *noPtr;

void inicializarRoleta(noPtr *ult, int *qtd);
void listarRoleta(noPtr ult, int qtd);
void girarRoleta(noPtr ult, int aposta, float *carteira, float valorAposta);

#endif