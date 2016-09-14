/*
 * Lista 01 do Camacho
 *   Entregar até 15/09/2016
 */

/* 
 *   File: main.cpp
 * Author: guilh
 *
 * Created on 9 de Setembro de 2016, 07:32
 */

#include <cstdlib>
#include <cstdio>
#include <iostream>

#define LEN_USER 2

using namespace std;

//Tipos de dados

typedef struct users {
    char nome[50];
    int option;
    int nume;
} User;

//Prototipos
void exercicio01();
void exercicio02();
void exercicio03();
void exercicio04();
void exercicio05();
void exercicio06();
void exercicio07();
void exercicio08();
void exercicio09();
void exercicio10();

/*
 * Metodo main
 */
int main() {
    int action;

    system("clear");
    cout << "Menu do Haynes\n"
            "Digite um numero para corresponder ao Exercicio\n"
            "    1- Media Aritmetica e Harmonica\n"
            "    2- Salario do Vendedor\n"
            "    3- Salario Funcionario + 25%\n"
            "    4- Calcula porção Gato após 5 dias\n"
            "    5- Degraus x Usuario\n"
            "    6- Par ou Impar\n"
            "    7- Calcula média COC\n"
            "    8- Qual é a sua idade\n"
            "    10- Seguro Franquia"
            "\n    0- Para sair\n"
            "Digite um numero para acessar o exercicio:" << endl;
    cin >> action;

    switch (action) {
        case 0: return EXIT_SUCCESS;
        case 1: exercicio01();
            break;
        case 2: exercicio02();
            break;
        case 3: exercicio03();
            break;
        case 4: exercicio04();
            break;
        case 5: exercicio05();
            break;
        case 6: exercicio06();
            break;
        case 7: exercicio07();
            break;
        case 8: exercicio08();
            break;
        case 10: exercicio10();
            break;

        default: main();
            break;
    }

    return 0;
}

/**
 * Metodo que faz um retorno ao main após executar alguma função
 */
void retornaMain() {
    char esp;
    cout << "\nDigite '0' para continuar...";
    cin >> esp;
    if (esp == '0') {
        main();
    } else {
        retornaMain();
    }
}

/**
 * Metodo que faz a média Artimética e Harmonica
 * 
 */
void exercicio01() {
    system("clear");
    float a, b, c, result;
    cout << "Digite primeiro numero:";
    cin >> a;
    cout << "Digite segundo numero:";
    cin >> b;
    cout << "Digite terceiro numero:";
    cin >> c;

    result = (a + b + c) / 3;
    cout << "\nMédia Aritmética: " << result << endl;

    result = 3 / ((1 / a) + (1 / b) + (1 / c));
    cout << "Média Harmonica: " << result << endl;

    retornaMain();
}

/**
 * Recebe o numero de um vendedor e o salario fixo
 *  o total de vendas por ele efetuadas e o percentual que ganha
 *  sobre o total de vendas
 * Calcule o salário total do vendedor e o retorna
 */
void exercicio02() {
    system("clear");

    int codVend, totalVendas;
    float salFix, percentVenda, newSal;
    cout << "Digite o código Vendedor: ";
    cin >> codVend;
    cout << "Digite o salario do Vendedor: ";
    cin >> salFix;
    cout << "Digite o total de vendas do Vendedor: ";
    cin >> totalVendas;
    cout << "Digite o percentual de vendas do Vendedor: ";
    cin >> percentVenda;

    //Transformando xx% em 0.xx
    percentVenda = percentVenda / 100;
    //Fazendo calculo
    newSal = salFix + ((salFix * percentVenda) * totalVendas);

    cout << "Código do vendedor: " << codVend
            << "\n      Novo Salario: " << newSal << endl;

    retornaMain();
}

/**
 * Pega o salario de um funcionario e adiciona 25% nesse valor
 * 
 */
void exercicio03() {
    system("clear");

    float salFix;
    cout << "Qual o salario do funcionario: ";
    cin >> salFix;

    salFix = salFix * 1.25;

    cout << "\nO novo salario é: " << salFix << endl;
    retornaMain();
}

void exercicio04() {
    system("clear");
    float saco, cats, rest;

    cout << "Digite o peso do saco em 'Kg': ";
    cin >> saco;
    cout << "Digite o quanto de ração seu gato come em 'g': ";
    cin >> cats;

    rest = (saco - (((cats * 2) / 1000) * 5));

    cout << "Após 5 dias restará " << rest << "kg" << endl;
    retornaMain();
}

void exercicio05() {
    system("clear");
    float altDeg, altUsu, altRes;

    cout << "Digite a altura do degrau: ";
    cin >> altDeg;
    cout << "Digite a altura que deseja subir: ";
    cin >> altUsu;

    altRes = altUsu / altDeg;

    cout << "Você devera subit " << altRes << " degraus" << endl;

    retornaMain();
}

void exercicio06() {
    system("clear");
    User user[2];
    int soma;

    for (int i = 0; i < LEN_USER; i++) {
        system("clear");
        cout << "Digite seu nome: ";
        cin >> user[i].nome;
        cout << "Digite seu palpite (0 = Par | 1 = Impar): ";
        cin >> user[i].option;
        cout << "Digite seu Numero: ";
        cin >> user[i].nume;
    }

    soma = user[0].nume + user[1].nume;


    if ((soma % 2) == user[0].option && (soma % 2) == user[1].option) {
        cout << "Empatou!!" << endl;
    } else if ((soma % 2) == user[0].option) {
        cout << "Jogador " << user[0].nome << " Ganhou!!!" << endl;
    } else {
        cout << "Jogador " << user[1].nome << " Ganhou!!!" << endl;
    }

    retornaMain();
}

void exame07(float nota, float *exame, float *media) {
    cout << "Você ficou de exame :c\nPor favor digite a nota do exame: ";
    cin >> *exame;

    *media = (nota + *exame) / 2;
}

void exercicio07() {
    system("clear");
    float b1, b2, b3, media;

    cout << "Digite a primeira nota:";
    cin >> b1;
    cout << "Digite a segunda nota:";
    cin >> b2;

    media = (b1 + b2) / 2;
    cout << "Média antes da bosta: " << media << endl;

    if (b1 < 4 && b2 < 4) {
        cout << "Parabens você reprovou!" << endl;
        retornaMain();
    } else if (b2 < 4) {
        exame07(b1, &b3, &media);
    } else if (b1 < 4) {
        exame07(b2, &b3, &media);
    }

    if (media >= 6) {
        cout << "Parabens você passou!\n" << media << endl;
    } else {
        cout << "Parabens você reprovou!\n" << media << endl;
    }

    retornaMain();
}

void exercicio08() {
    system("clear");
    int idade;

    cout << "Digite sua idade: ";
    cin >> idade;

    if (idade >= 0 && idade <= 12)
        cout << "Você é uma Criança!" << endl;
    if (idade >= 13 && idade <= 18)
        cout << "Você é uma Adolecente!" << endl;
    if (idade >= 19 && idade <= 59)
        cout << "Você é uma Adulto!" << endl;
    if (idade >= 60)
        cout << "Você é uma Criança de mais idade!" << endl;

    retornaMain();
}

void exercicio09() {
    system("clear");
    int tipo, regiao;
    float perCarro, perRegiao, valSeg, valFran, valInic;

    cout << "Digite o valor inicial do carro";
    cin >> valInic;
    cout << "Digite o tipo do carro\n"
            "   1 - para carros pequenos\n"
            "   2 - para carros medios\n"
            "   3 - para carros grandes\n";
    cin >> tipo;
    cout << "Digite a regiao de licenciamento do carro\n"
            "   1 - para norte e nordeste\n"
            "   2 - para sul e centro oeste\n"
            "   3 - para sudeste (exceto Sao paulo e Rio)\n"
            "   4 - para Sao Paulo\n"
            "   5 - para Rio de Janeiro\n";
    cin >> regiao;
    
    //Verifica o tipo de carro
    if (tipo == 1)
        perCarro = 0.08;
    if (tipo == 2)
        perCarro = 0.12;
    if (tipo == 3)
        perCarro = 0.10;
    
    //Verifica Região do carro
    if (regiao == 1)
        perRegiao = 0.03;
    if (regiao == 2)
        perRegiao = 0.05;
    if (regiao == 3)
        perRegiao = 0.08;
    if (regiao == 4)
        perRegiao = 0.10;
    if (regiao == 5)
        perRegiao = 0.15;

    //Calcula o valor do seguro
    valSeg = (perCarro + perRegiao) * valInic;
    
    //Verifica o valor da franquida de acordo com o seguro
    if (valSeg < 300)
        valFran = 400;
    if (valSeg >= 300 && valSeg < 500)
        valFran = 600;
    if (valSeg >= 500)
        valFran = 800;
    
    //Mostra o valor do seguro e da franquia
    cout << "Seguro: " << valSeg << endl;
    cout << "Franquia: " << valFran << endl;
    retornaMain();
}
void exercicio10(){
    exercicio09();
}
