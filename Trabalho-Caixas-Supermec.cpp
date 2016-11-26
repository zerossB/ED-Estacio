/* 
 * File:   main.cpp
 * Author: haynes
 *
 * Created on 14 de Novembro de 2016, 20:40
 * 
 * =============================================================================
 *  Programa:
 *  Faça um programa que simule o comportamento de Filas de supermercado.
 * =============================================================================
 * 
 *  - O usuário que controla o programa será responsável por:
 *      # Informar quando um novo cliente chega para ser atendido no caixa,
 *          indicando o tempo estimado deste cliente.
 *      # Indicar o tempo máximo de atendimento permitido numa Fila
 *          (este tempo valerá para todas as filas em questão).
 * 
 *  - O sistema deve encaminhar o cliente para a Fila com menor tempo médio de atendimento.
 *      # Ao encaminhar o cliente para uma Fila o sistema deve verificar se o tempo máximo
 *          de atendimento da mesma não ultrapassará o limite permitido
 *          (informado pelo operador do sistema). Em caso positivo, o cliente deve ser
 *          encaminhado para outra Fila. Se o tempo máximo para todas as filas violar
 *          o limite permitido ao tentar inserir um novo cliente para ser atendido então
 *          o sistema deve solicitar a abertura de um novo “caixa” e encaminhar o cliente a ele.
 *  
 *  - Quando a Fila de um caixa estiver vazia você deve fechar este caixa.
 */

#include <stdlib.h>
#include <cstdlib>
#include <iostream>

using namespace std;

/* ========================================================================== */
/* =                                                                        = */
/* =                            Estruturas bases                            = */
/* =                                                                        = */
/* ========================================================================== */

/* ========================== Estruturas da Fila ============================ */

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
typedef struct no_fila {
    tCliente dado;
    struct no_fila *prox;
} tTNo;

typedef struct tipo_fila {
    tTNo *inicio;
    tTNo *fim;
    int quantidade;
} tTFila;

/* ========================== Estruturas da Lista =========================== */

/*
 *  Estrutura de um caixa do supermercado
 */
typedef struct caixa {
    int numCaixa;
    int tmpMedio;
    tTFila *fila;
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


/* ========================================================================== */
/* =                                                                        = */
/* =                         Estruturas das funções                         = */
/* =                                                                        = */
/* ========================================================================== */

/* ======================= Funções da Lista de caixas ======================= */
void criaLista();
void showLista();
void insertLista(int, tTFila *);
void deleteLista(int);
int tamanhoLista();
bool vaziaLista();
tCaixa * getCaixa(int);

/* ====================== Funções da Fila de Clientes ======================= */
void criaFila(tTFila *);
void showFila(tTFila *);
void insertFila(int, tTFila *);
void deleteFila(tTFila *);
int tamanhoFila(tTFila *);
bool vaziaFila(tTFila *);
int getTempoFila(tTFila *);

/* ======================== Funções do Supermercado ========================= */
void definirTempoMedio();
void criaCliente();
void atendeCliente();
void showStatus();

/*
 * Metodo Main
 */
int main(int argc, char** argv) {
    criaLista();
    definirTempoMedio();

    tTFila fila;
    criaFila(&fila);

    for (int i = 0; i < 10; i++) {
        insertFila(1, &fila);
    }

    insertLista(tmpMedioCaixa, &fila);

    showStatus();

    return 0;
}

/* ========================================================================== */
/* =                                                                        = */
/* =                   Funções para manipulações da Lista                   = */
/* =                                                                        = */
/* ========================================================================== */

void criaLista() {
    tLCaixas *aux;
    aux = (tLCaixas *) malloc(sizeof (tLCaixas));
    lFirst = aux;
    lLast = lFirst;
}

void insertLista(int tmpMedio, tTFila *inicio) {
    tCaixa dado;
    tLCaixas *aux;
    aux = (tLCaixas *) malloc(sizeof (tLCaixas));

    dado.numCaixa = lLast->dado.numCaixa + 1;
    dado.tmpMedio = tmpMedio;
    dado.fila = inicio;

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

tCaixa * getCaixa(int codCaixa) {
    tLCaixas *aux;
    aux = lFirst->prox;
    while (aux != NULL) {
        if (aux->dado.numCaixa == codCaixa) {
            return &aux->dado;
            break;
        }
        aux = aux->prox;
    }
}

/* ========================================================================== */
/* =                                                                        = */
/* =                   Funções para manipulações da Fila                    = */
/* =                                                                        = */
/* ========================================================================== */

void criaFila(tTFila *fila) {
    tTNo *aux;
    aux = (tTNo *) malloc(sizeof (tTNo));
    fila->inicio = aux;
    fila->fim = fila->inicio;
}

void showFila(tTFila *fila) {
    tTNo *aux;
    aux = fila->inicio->prox;
    while (aux != fila->inicio) {
        cout << "\n";
        cout << "=====================================================" << endl;
        cout << "Cliente " << aux->dado.codClient << endl;
        cout << "Tempo de Atendimento: " << aux->dado.tempo << "\n" << endl;
        aux = aux->prox;
    }
}

void insertFila(int tmpMedio, tTFila *fila) {
    tCliente dado;
    tTNo *aux;
    aux = (tTNo *) malloc(sizeof (tTNo));

    dado.codClient = fila->fim->dado.codClient + 1;
    dado.tempo = tmpMedio;

    aux->dado = dado;
    fila->fim->prox = aux;
    fila->fim = fila->fim->prox;
    fila->fim = aux;
    fila->quantidade = fila->quantidade + 1;
}

void deleteFila(tTFila *fila) {
    if (vaziaFila(fila)) return;
    fila->inicio->prox = fila->inicio->prox->prox;
    fila->quantidade = fila->quantidade - 1;
}

int tamanhoFila(tTFila *fila) {
    tTNo *aux;
    int i = 0;
    aux = fila->inicio->prox;
    while (aux != fila->inicio) {
        aux = aux->prox;
        i++;
    }
    return i;
}

bool vaziaFila(tTFila *fila) {
    //return (fila->inicio->prox == fila->fim) ? true : false;
    return (fila->inicio->prox == NULL) ? true : false;
}

int getTempoFila(tTFila *fila) {
    tTNo *aux;
    int i = 0;
    aux = fila->inicio->prox;
    while (aux != fila->inicio) {
        aux = aux->prox;
        i += aux->dado.tempo;
    }
}


/* ========================================================================== */
/* =                                                                        = */
/* =                   Funções para manipulações Basicas                    = */
/* =                                                                        = */
/* ========================================================================== */

void definirTempoMedio() {
    cout << "Qual o tempo médio de cada caixa? ";
    cin >> tmpMedioCaixa;
}

void criaCliente() {
    int tmp;
    tLCaixas *aux;

    cout << "Digite o tempo que esse cliente levará para ser atendido: ";
    cin >> tmp;

    aux = lFirst->prox;
    while (aux != NULL) {
        //For menor igual o tempo médio |E| tmp for menor igual a diferença entre os 2
        if (aux->dado.tmpMedio < tmpMedioCaixa && tmp <= (aux->dado.tmpMedio - tmpMedioCaixa)) {
            //insertLista();
            break;
        } else if (aux->dado.tmpMedio >= tmpMedioCaixa) {
            //criaFila();
            //insertFila();
            //insertLista();
            break;
        }
        aux = aux->prox;
    }

}

void atendeCliente() {
    int caixa;
    tCaixa *cax;

    cout << "Qual caixa deseja eliminar o cliente? ";
    cin >> caixa;

}

void showStatus() {
    tLCaixas *aux;
    aux = lFirst->prox;
    while (aux != NULL) {
        cout << "\n";
        cout << "=====================================================" << endl;
        cout << "Numero do Caixa: " << aux->dado.numCaixa << endl;
        cout << "Tempo médio para o caixa: " << aux->dado.tmpMedio << endl;
        showFila(aux->dado.fila);
        aux = aux->prox;
    }
}
