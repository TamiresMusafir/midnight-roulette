#include "roleta.h"
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

void inicializarRoleta(noPtr *ult, int *qtd) {
    for (int i = 0; i <= 36; i++) {
        noPtr p = new no;
        p->info = i;

        if (*ult == NULL) {
            *ult = p;
            (*ult)->prox = p;
        } else {
            p->prox = (*ult)->prox;
            (*ult)->prox = p;
            *ult = p;
        }
        *qtd += 1;
    }
}

void listarRoleta(noPtr ult, int qtd) {
    if (ult != NULL) {
        noPtr atual = ult->prox; 
        cout << "\nNumeros na roleta: ";
        for (int i = 0; i < qtd; i++) {
            cout << atual->info << " ";
            atual = atual->prox;
        }
        cout << "\n";
    }
}

void girarRoleta(noPtr ult, int aposta, float *carteira, float valorAposta) {
    noPtr bolinha = ult->prox;
    int impulso = (rand() % 50) + 45;

    cout << "\n* A roleta esta girando...";
    for (int i = 0; i < impulso; i++) {
        bolinha = bolinha->prox;
    }

    cout << "\n=======================================";
    cout << "\n>>>  A BOLINHA PAROU NO NUMERO: " << bolinha->info << "  <<<";
    cout << "\n=======================================\n";

    if (bolinha->info == aposta) {
        *carteira += (valorAposta * 35);
        cout << "PARABENS! Voce acertou o numero e ganhou R$" << fixed << setprecision(2) << (valorAposta * 35) << "!\n"
             << "Saldo: R$ " << fixed << setprecision(2) << *carteira << "\n";
    } else {
        *carteira -= valorAposta;
        cout << "Nao foi dessa vez! Voce perdeu R$" << fixed << setprecision(2) << valorAposta << ".\n"
             << "Saldo: R$ " << fixed << setprecision(2) << *carteira << "\n";
    }
}