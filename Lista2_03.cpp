/* 
 * File:   main.cpp
 * Author: guilh
 *
 * Created on 9 de Outubro de 2016, 16:27
 */

#include <cstdlib>
#include <iostream>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    int qtdQW;
    float result, valor;

    valor = 0.41964;

    cout << "Digite quantos quilowatt você gastou esse mês: ";
    cin >> qtdQW;

    result = valor * qtdQW;

    cout << "\nValor de Cada Quilowatt é " << qtdQW << endl;
    cout << "Valor a ser pago:         " << result << endl;
    cout << "Valor a ser pago com 15%: " << result - (result * 0.15) << endl;

    return 0;
}

