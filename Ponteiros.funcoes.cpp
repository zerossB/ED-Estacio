/* 
 * File:   main.cpp
 * Author: Haynes
 *
 * Created on 19 de Agosto de 2016, 13:34
 */

#include <cstdlib>
#include <iostream>

using namespace std;

//Prototipos das funções
void orden(int *, int *, int *);

/*
 * Metodo Main
 */
int main(int argc, char** argv) {
    int a, b, c;

    cout << "Digite o primeiro numero: ";
    cin >> a;
    cout << "Digite o segundo numero: ";
    cin >> b;
    cout << "Digite o ultimo numero: ";
    cin >> c;

    orden(&a, &b, &c);

    cout << "A: " << a << " B: " << b << " C: " << c << endl;

    return 0;
}

/*
 * Ordena os numeros independente da ordem que forem colocados
 * 
 * Parametros
 *     a - &int
 *     b - &int
 *     c - &int
 * 
 * Obs.
 *     & = Endereço de memória
 */
void orden(int *a, int *b, int *c) {
    int aux;
    if (*a < *b) {
        aux = *a;
        *a = *b;
        *b = aux;
    }else if (*a < *c) {
        aux = *a;
        *a = *c;
        *c = aux;
    }
    if (*b < *c) {
        aux = *b;
        *b = *c;
        *c = aux;
    }
}
