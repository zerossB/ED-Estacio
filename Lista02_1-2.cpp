/* 
 * File:   main.cpp
 * Author: guilh
 *
 * Created on 15 de Setembro de 2016, 08:27
 */

#include <cstdlib>
#include <iostream>

#define VEND_MAX 10

using namespace std;

typedef struct vende {
    int codVend;
    string nome;
    int totalVend;
    float salFix;
    float percVenda;
    float salFinal;
} Vendedor;

typedef struct lista {
    Vendedor vend[VEND_MAX];
    int n;
} ListaVend;

void exercicio01();
void exercicio02();

void criarLista(ListaVend *);
bool insertLista(ListaVend *, Vendedor *, int);
bool removeLista(ListaVend *, int);
bool cheiaLista(ListaVend *);
bool vaziaLista(ListaVend *);
void showLista(ListaVend *);

void showVendedor(Vendedor *);

Vendedor buscaPNome(ListaVend *, string);
Vendedor buscaPCodVend(ListaVend *, int);

void inserirAut(ListaVend *);

/*
 * Metodo Main
 */
int main() {
    ListaVend lista;

    criarLista(&lista);
    inserirAut(&lista);
    showLista(&lista);

    int aux;
    cout << "Digite um numero para remover: ";
    cin >> aux;
    removeLista(&lista, aux);
    showLista(&lista);

    Vendedor vaucir;
    string nome;
    int codVend;

    /*    
    cout << "Digite um Cod de Vendedor para pesquisar: ";
    cin >> codVend;
    vaucir = buscaPCodVend(&lista, codVend);
     */

    cout << "Digite um Nome para pesquisar: ";
    cin >> nome;
    vaucir = buscaPNome(&lista, nome);

    showVendedor(&vaucir);

    return 0;
}

void inserirAut(ListaVend *lista) {
    for (int i = 0; i <= VEND_MAX; i++) {
        Vendedor vend;
        vend.codVend = i;
        vend.nome = "Vendedor " + to_string(i);
        vend.salFinal = rand() & 1000;
        insertLista(lista, &vend, i);
    }
}

void exercicio01() {
    Vendedor vend;
    cout << "Digite o código do Vededor: ";
    cin >> vend.codVend;
    cout << "Digite o nome do Vededor: ";
    cin >> vend.nome;
    cout << "Digite o Salario do Vendedor: ";
    cin >> vend.salFix;
    cout << "Digite o total de vendas por ele efetuadas: ";
    cin >> vend.totalVend;
    cout << "Qual a porcentagem de ganho sobre venda: ";
    cin >> vend.percVenda;

    vend.percVenda = vend.percVenda / 100;

    vend.salFinal = vend.salFix + ((vend.salFix * vend.percVenda) * vend.totalVend);

    cout << "Numero do Vendedor: " << vend.codVend
            << "\n      Novo Salario: " << vend.salFinal << endl;
}

void criarLista(ListaVend *lista) {
    lista->n = 0;
}

bool cheiaLista(ListaVend *lista) {
    return (lista->n == VEND_MAX) ? true : false;
}

bool vaziaLista(ListaVend *lista) {
    return (lista->n == 0) ? true : false;
}

bool insertLista(ListaVend *lista, Vendedor *vend, int pos) {
    int aux;
    if (cheiaLista(lista) || pos > lista->n + 1) return false;

    for (aux = lista->n; aux < pos; aux--)
        lista->vend[aux] = lista->vend[aux - 1];

    lista->vend[aux] = *vend;
    lista->n++;
    return true;
}

/**
 * Em memória do Valcir 
 * 
 * Vendedor vaucir;
 * vaucir = lista->vend[pos - 1];
 */
bool removeLista(ListaVend *lista, int pos) {
    int aux;
    if (pos <= 0 || pos > lista->n) return false;

    for (aux = pos; aux <= lista->n - 1; aux++)
        lista->vend[aux - 1] = lista->vend[aux];

    lista->n--;
    return true;
}

Vendedor buscaPNome(ListaVend *lista, string nome) {
    Vendedor elias;

    for (int i = 0; i < lista->n; i++) {
        if (lista->vend[i].nome.compare(nome))
            elias = lista->vend[i];
    }

    if (elias.codVend >= 0) {
        return elias;
    } else {
        elias.codVend = -1;
        elias.nome = "Nome não econtrado";
        return elias;
    }
}

Vendedor buscaPCodVend(ListaVend *lista, int codVend) {
    for (int i = 0; i < lista->n; i++) {
        if (lista->vend[i].codVend == codVend)
            return lista->vend[i];
    }
}

void showLista(ListaVend *lista) {
    for (int i = 0; i < lista->n; i++) {
        cout << "     Cod. Vend: " << lista->vend[i].codVend << endl;
        cout << "     Nome Vend: " << lista->vend[i].nome << endl;
        cout << "Sal Final Vend: " << lista->vend[i].salFinal << endl;
        cout << "-------------------------------------------" << endl;
    }
    cout << "\nNumero de elementos: " << lista->n << endl;
}

void showVendedor(Vendedor *vend) {
    cout << "     Cod. Vend: " << vend->codVend << endl;
    cout << "     Nome Vend: " << vend->nome << endl;
    cout << "Sal Final Vend: " << vend->salFinal << endl;
    cout << "-------------------------------------------" << endl;
}
