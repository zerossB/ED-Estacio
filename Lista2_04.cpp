/* 
 * File:   main.cpp
 * Author: guilh
 *
 * Created on 11 de Outubro de 2016, 19:33
 */

#include <cstdlib>
#include <iostream>

#define WATT 20
#define MAX 50

using namespace std;

typedef struct comodo {
    int largura;
    int altura;
    int area;
    int potencia;
} Comodo;

typedef struct listaC {
    Comodo row[MAX];
    int n;
} ListaComodo;

bool criarLista(ListaComodo *);
bool cheiaLista(ListaComodo *);
bool vaziaLista(ListaComodo *);

bool inserirLista(ListaComodo *, Comodo *, int);
bool deleteLista(ListaComodo *, Comodo *, int);
bool showLista(ListaComodo *);

bool calcArea(ListaComodo *);
bool calcPotencia(ListaComodo *);

/*
 * 
 */
int main(int argc, char** argv) {

    ListaComodo lista;
    int qtdCom;

    criarLista(&lista);

    cout << "Quantos comodos tem na casa? ";
    cin >> qtdCom;
    
    for (int i = 0; i < qtdCom; i++) {
        system("clear");
        Comodo com;
        cout << "Qual a largura do comodo?: ";
        cin >> com.largura;
        cout << "Qual a altura do comodo?: ";
        cin >> com.altura;
        inserirLista(&lista, &com, i);
    }

    calcArea(&lista);
    calcPotencia(&lista);
    
    system("clear");
    showLista(&lista);

    return 0;
}

bool criarLista(ListaComodo *list) {
    list->n = 0;
}

bool cheiaLista(ListaComodo *list) {
    return (list->n == MAX) ? true : false;
}

bool vaziaLista(ListaComodo *list) {
    return (list->n == 0) ? true : false;
}

bool inserirLista(ListaComodo *lista, Comodo *comodo, int pos) {
    int aux;
    if (cheiaLista(lista) || pos > lista->n + 1) return false;

    for (aux = lista->n; aux < pos; aux--)
        lista->row[aux] = lista->row[aux - 1];

    lista->row[aux] = *comodo;
    lista->n++;
    return true;
}

bool deleteLista(ListaComodo *lista, Comodo *comodo, int pos) {
    int aux;
    if (pos <= 0 || pos > lista->n) return false;

    for (aux = pos; aux <= lista->n - 1; aux++)
        lista->row[aux - 1] = lista->row[aux];

    lista->n--;
    return true;
}

bool calcArea(ListaComodo *lista) {
    for (int i = 0; i < lista->n; i++) {
        lista->row[i].area = lista->row[i].altura * lista->row[i].largura;
    }
}

bool calcPotencia(ListaComodo *lista) {
    for (int i = 0; i < lista->n; i++) {
        lista->row[i].potencia = lista->row[i].area * WATT;
    }
}

bool showLista(ListaComodo *lista) {
    cout << "Quantidade de Comodos:  " << lista->n << endl;
    cout << "-------------------------------------"<<endl;
    for (int i = 0; i < lista->n; i++) {
        cout << "Area de cada comodo:     " << lista->row[i].area << endl;
        cout << "Potencia de cada comodo: " << lista->row[i].potencia << endl;
        cout << "-------------------------------------"<<endl;
    }
}
