/* 
 * File:   main.cpp
 * Author: haynes
 *
 * Created on 14 de Novembro de 2016, 20:40
 */

#include <stdlib.h>
#include <cstdlib>
#include <iostream>

using namespace std;

/* ========================================================================= */
/* =                                                                       = */
/* =                           Estruturas bases                            = */
/* =                                                                       = */
/* ========================================================================= */


/* ========================== Estruturas da Pilha ========================== */

/**
 *  Estrutura do cliente
 */
typedef struct cliente {
    int codClient;
    int tempo;
} tCliente;

/**
 * Estrutura de fila, para poder listar todos os clientes
 *      do caixa aberto
 */
typedef struct tipo_fila {
    tCliente dado;
    struct tipo_fila *prox;
} tTFila;

//Primeiro Cliente
struct tipo_fila *fFirst;

//Ultimo Cliente
struct tipo_fila *fLast;


/* ========================== Estruturas da Lista ========================== */

/*
 *  Estrutura de um caixa do supermercado
 */
typedef struct caixa {
    int numCaixa;
    int tmpMedio;
    tTFila fila;
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
struct lista_caixa *lFirst;

//Ultimo caixa aberto
struct lista_caixa *lLast;
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
void criaFila();
void showFila();
void insertFila(int);
void deleteFila();
int tamanhoFila();
bool vaziaFila();

/*
 * Metodo Main
 */
int main(int argc, char** argv) {
    

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
    lFirst = aux;
    lLast = lFirst;
}

void insertLista(int tmpMedio) {
    tCaixa dado;
    tLCaixas *aux;
    aux = (tLCaixas *) malloc(sizeof (tLCaixas));

    dado.numCaixa = lLast->dado.numCaixa + 1;
    dado.tmpMedio = tmpMedio;

    aux->dado = dado;
    lLast->prox = aux;
    lLast = lLast->prox;
    aux->prox = NULL;
}

void deleteLista(int codCaixa) {
    tLCaixas *aux, *last;
    int flag = 0;

    last = lFirst;
    aux = lFirst->prox;

    do {
        if (aux->dado.numCaixa == codCaixa) {
            last->prox = aux->prox;
            free(aux);
            flag == 1;
        } else {
            last = last->prox;
            aux = aux->prox;
        }
    } while (aux != NULL);

    if (flag == 0)
        cout << "Caixa não encontrado" << endl;
}

void showLista() {
    tLCaixas *aux;
    aux = lFirst->prox;
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
    aux = lFirst->prox;
    while (aux != NULL) {
        aux = aux->prox;
        i++;
    }
    return i;
}

bool vaziaLista() {
    return (lFirst->prox == NULL) ? true : false;
}

/* ========================================================================= */
/* =                                                                       = */
/* =                  Funções para manipulações da Fila                    = */
/* =                                                                       = */
/* ========================================================================= */

void criaFila() {
    tTFila *aux;
    aux = (tTFila *) malloc(sizeof (tTFila));
    fFirst = aux;
    fLast = fFirst;
}

void showFila() {
    tTFila *aux;
    aux = fFirst->prox;
    while (aux != fFirst) {
        cout << "\n";
        cout << "=====================================================" << endl;
        cout << "Cliente " << aux->dado.codClient << endl;
        cout << "Tempo de Atendimento: " << aux->dado.tempo << "\n" << endl;
        aux = aux->prox;
    }
}

void insertFila(int tmpMedio) {
    tCliente dado;
    tTFila *aux;
    aux = (tTFila *) malloc(sizeof (tTFila));

    dado.codClient = fLast->dado.codClient + 1;
    dado.tempo = tmpMedio;
    
    aux->dado = dado;
    fLast->prox = aux;
    fLast = fLast->prox;
    aux->prox = fFirst;
}

void deleteFila() {
    if(vaziaFila()) return;

    fFirst->prox = fFirst->prox->prox;
}

int tamanhoFila() {
    tTFila *aux;
    int i = 0;
    aux = fFirst->prox;
    while (aux != NULL) {
        aux = aux->prox;
        i++;
    }
    return i;
}

bool vaziaFila() {
    return (fFirst->prox == NULL) ? true : false;
}
