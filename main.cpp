#include <iostream>
#include <cstdlib> 
#include <ctime>  
#include <iomanip> 
#include "roleta.h"

using namespace std;

int main(){
    srand(time(NULL));

    noPtr ult = NULL;
    int op, qtd = 0;
    float carteira = 100.0;
    float valorAposta;

    inicializarRoleta(&ult, &qtd);

    cout << "=====================================\n"
         << "  Bem vindo a Roleta da Meia Noite   \n"
         << "=====================================\n"
         << "\nA roleta possui " << qtd << " numeros.\n";

    listarRoleta(ult, qtd);

    cout << "Opcoes: \n"
         << "\n1 - Apostar um numero na roleta\n"
         << "\n0 - Sair\n"
         << "\nDigite uma opcao: ";
    cin >> op;

    while(op != 0){
        switch (op){
            case 1:
                int aposta;
                cout << "\nSeu saldo atual: R$" << fixed << setprecision(2) << carteira
                     << "\n==== Ganho = valor apostado x 35 ===="
                     << "\nQuanto voce deseja apostar? ";
                cin  >> valorAposta;

                if(valorAposta >= 0 && valorAposta <= carteira){
                    cout << "\nDigite o numero da sua aposta (0 a 36): ";
                    cin >> aposta;

                    if(aposta < 0 || aposta > 36){
                        cout << "\nNumero invalido. Tente novamente.\n";
                    } else {
                        girarRoleta(ult, aposta, &carteira, valorAposta);
                    }
                } else {
                    cout << "\nSaldo insuficiente ou valor invalido! Tente novamente!\n";
                }
                break;
            case 2:
                listarRoleta(ult, qtd);
                break;
                
            default:
                cout << "Opcao invalida. Tente novamente.\n";
                break;
        }

        if(carteira <= 0){
            cout << "\nVOCE FALIU! Seu saldo acabou!\n";
            op = 0;
        } else {
            char novaAposta;
            cout << "\nDeseja continuar no jogo? (S-SIM / N-NAO): ";
            cin >> novaAposta;

            if(novaAposta == 'S' || novaAposta == 's'){ 
                cout << "\nEscolha uma opcao: \n"
                    << "1 - Apostar um numero na roleta\n"
                    << "2 - Visualizar numeros da roleta\n"
                    << "0 - Sair\n"
                    << "Sua opcao: ";
                cin >> op; 
            }
            else if(novaAposta == 'N' || novaAposta == 'n'){
                cout << "\nEncerrando o jogo. Obrigado por jogar!\n";
                op = 0;
            }
            else {
                cout << "\nEntrada invalida! Encerrando o jogo por seguranca.\n";
                op = 0;
            }
        }
    }

    cout << "\nVoce saiu do cassino com: R$" << fixed << setprecision(2) << carteira << "\n";
    return 0;
}