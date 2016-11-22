/* 
 * File:   main.cpp
 * Author: haynes
 *
 * Created on 14 de Novembro de 2016, 20:40
 */

#include <cstdlib>
#include <math.h>
#include <iostream>

using namespace std;

/* ========================================================================= */
/* =                                                                       = */
/* =                           Estruturas bases                            = */
/* =                                                                       = */
/* ========================================================================= */

/* ========================== Estruturas da Lista ========================== */

/*
 *  Estrutura de um caixa do supermercado
 */
typedef struct caixa {
    int numCaixa;
    int tmpMedio;
} tCaixa;

/*
 *  Estrutura de lista, para pode listar todos os caixas de
 *      supermercados abertos
 */
typedef struct lista_caixa {
    tCaixa dado;
    struct lista_caixa *prox;
} tLCaixas;

//Primeiro caixa aberto
struct lista_caixa *primeiro;

//Ultimo caixa aberto
struct lista_caixa *ultimo;

int tmpMedioCaixa;


/* ========================================================================= */
/* =                                                                       = */
/* =                        Estruturas das funções                         = */
/* =                                                                       = */
/* ========================================================================= */

/* ====================== Funções da Lista de caixas ======================= */
void criaLista();
void showLista();
void insertLista(int);
void deleteLista(int);
int tamanhoLista();
bool vaziaLista();

/* ====================== Funções da Pilha de Clientes ===================== */

/*
 * Metodo Main
 */
int main(int argc, char** argv) {

    cout << "Qual o tempo médio dos caixas? ";
    cin >> tmpMedioCaixa;

    criaLista();
    int count = 0;

    for (int i = 0; i < 10; i++) {
        insertLista(tmpMedioCaixa);
    }

    showLista();

    cout << "Digite o numero do caixa para excluir: ";
    cin >> count;

    deleteLista(count);

    showLista();

    return 0;
}

/* ========================================================================= */
/* =                                                                       = */
/* =                 Funções para manipulações da Lista                    = */
/* =                                                                       = */
/* ========================================================================= */

void criaLista() {
    tLCaixas *aux;
    aux = (tLCaixas *) malloc(sizeof (tLCaixas));
    primeiro = aux;
    ultimo = primeiro;
}

void insertLista(int tmpMedio) {
    tCaixa dado;
    tLCaixas *aux;
    aux = (tLCaixas *) malloc(sizeof (tLCaixas));

    dado.numCaixa = ultimo->dado.numCaixa + 1;
    dado.tmpMedio = tmpMedio;

    aux->dado = dado;
    ultimo->prox = aux;
    ultimo = ultimo->prox;
    aux->prox = NULL;
}

void deleteLista(int codCaixa) {
    tLCaixas *aux, *last;
    int flag = 0;
    
    last = primeiro;
    aux = primeiro->prox;
    
    do{
        if(aux->dado.numCaixa == codCaixa){
            last->prox = aux->prox;
            free(aux);
            flag == 1;
        }else{
            last = last->prox;
            aux = aux->prox;
        }
    }while(aux != NULL);
    
    if(flag == 0)
        cout << "Caixa não encontrado" << endl;
}

void showLista() {
    tLCaixas *aux;
    aux = primeiro->prox;
    while (aux != NULL) {
        cout << "\n";
        cout << "=====================================================" << endl;
        cout << "Numero do Caixa: " << aux->dado.numCaixa << endl;
        cout << "Tempo médio para o caixa: " << aux->dado.tmpMedio << endl;
        aux = aux->prox;
    }
}

int tamanhoLista() {
    tLCaixas *aux;
    int i = 0;
    aux = primeiro->prox;
    while (aux != NULL) {
        aux = aux->prox;
        i++;
    }
    return i;
}

bool vaziaLista(){
    return (primeiro->prox == NULL) ? true : false;
}
