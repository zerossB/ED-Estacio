/* 
 * File:   VerificaTipo.cpp
 * Author: guilh
 *
 * Created on 30 de Agosto de 2016, 20:23
 */

#include <cstdlib>
#include <iostream>
#include <ctype.h>

using namespace std;

//Protótipos das funções
bool is_digt(char *);
void x_toupper(char *);

/*
 * Metodo main
 */
int main(int argc, char** argv) {
    char digit;
    char upper;
    char vetor[10];

    cout << "Digite para verificar de é digito: ";
    cin >> digit;
    is_digt(&digit) ? cout << "É Digito!" << endl : cout << "Não é Digito" << endl;

    cout << "Digite para colocar em Maiusculo: ";
    cin >> upper;
    x_toupper(&upper);
    cout << "Letra em maiusculo é: " << upper << endl;

    cout << "Digite uma frase de 10 letras e numeros:";
    cin >> vetor;

    for (int i = 0; i < 10; i++) {
        x_toupper(&vetor[i]);
    }

    cout << "Frase maiuscula é:\n" << vetor << endl;

    return 0;
}

/**
 * Verifica se é digito ou não
 * 
 * @required ctype.h
 * @param digit - char
 * @return bool - Se é digito ou não
 */
bool is_digt(char *digit) {
    return isdigit(*digit);
}

/**
 * Altera o valor na memoria deixando caracter em maiusculo.
 * 
 * @param upper - char
 */
void x_toupper(char *upper) {
    *upper = toupper(*upper);
}
