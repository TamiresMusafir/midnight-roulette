#include "roleta.h"
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <unistd.h>

using namespace std;

string cores(int n){
    int vermelhos[] = {
    1,3,5,7,9,12,14,16,18,
    19,21,23,25,27,30,32,34,36
    };

    if(n == 0)
        return "\x1b[42m\x1b[30m";

        for(int i = 0; i < 18; i++){
            if(n == vermelhos[i]){
                return "\x1b[41m\x1b[37m";
            }
        }
        
    return "\x1b[40m\x1b[37m";
}

void inicializarRoleta(noPtr *ult, int *qtd) {
    for (int i = 0; i <= 36; i++){
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

        cout << "\n========================================\n"
             << "       🎰 MIDNIGHT ROULETTE 🎰          \n"
             << "========================================\n";

        cout << "\nNumeros na roleta: ";
        for (int i = 0; i < qtd; i++) {
            cout << cores(atual->info)
                 << " ["
                 << atual->info
                 << "] "
                 << "\033[0m ";
            atual = atual->prox;

            if (i == 0){
                cout << "\n\n";
            }else if ((i % 12) == 0){
                cout << "\n\n";
            }
        }
        cout << "\n";
    }
}

void girarRoleta(noPtr ult, int aposta, float *carteira, float valorAposta) {
    if (ult == NULL) 
        return;

    noPtr bolinha = ult->prox;
    
    int impulso = (rand() % 50) + 45; 
    int delay = 50000; 

    for (int i = 0; i < impulso; i++) {

        bolinha = bolinha->prox;

        cout << "\033[2J\033[1;1H"
             << "\n* A roleta esta girando... * \n\n";

        noPtr atual = ult->prox;
        for (int j = 0; j <= 36; j++) {
            
            if (atual == bolinha) {
                cout << "\x1b[43m\x1b[30m [" << atual->info << "] \033[0m ";
            } else {
                cout << cores(atual->info) << " [" << atual->info << "] \033[0m ";
            }

            atual = atual->prox;

            if (j == 0) {
                cout << "\n\n";
            } else if ((j % 12) == 0) {
                cout << "\n\n";
            }
        }

        usleep(delay);

        if (i > (impulso - 15)) {
            delay += 25000;
        }
    }

    cout << "========================================";
    cout << "\n>>>  A BOLINHA PAROU NO NUMERO: " << bolinha->info << "  <<<";
    cout << "\n========================================\n";

    if (bolinha->info == aposta) {
        *carteira += (valorAposta * 35);
        cout << "PARABENS! Voce acertou o numero e ganhou R$" << fixed << setprecision(2) << (valorAposta * 35) << "!\n";
    } else {
        *carteira -= valorAposta;
        cout << "Nao foi dessa vez! Voce perdeu R$" << fixed << setprecision(2) << valorAposta << ".\n";
    }
    cout << "Saldo Atual: R$ " << fixed << setprecision(2) << *carteira << "\n";
}