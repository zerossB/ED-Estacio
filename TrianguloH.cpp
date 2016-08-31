/* 
 * File:   TrianguloH.cpp
 * Author: guilh
 *
 * Created on 30 de Agosto de 2016, 19:20
 * 
 */

#include <cstdlib>
#include <iostream>
#include <cmath>

using namespace std;

//Protótipo da função
float hipotenusa(float *, float *);

/*
 * Metodo Main
 */
int main(int argc, char** argv) {
    float cat1, cat2, cat3;
    
    cout << "Digite o primeiro cateto:";
    cin >> cat1;
    cout << "Digite o segundo cateto:";
    cin >> cat2;
    
    cout << "Digite o terceiro cateto:";
    cin >> cat3;
    
    float hip = hipotenusa(&cat1, &cat2);
    hip = hipotenusa(&hip, &cat3);
    
    cout << "\n\nO valor da Hipotenusa é: " << hip << endl;
    
    return 0;
}

/*
 * Calcula o valor da hipotenusa
 *  @param *cat1 = Endereço de memória do cateto 1
 *    *cat2 = Endereço de memória do cateto 2
 *  
 *  @return float - Valor da hipotenusa
 */
float hipotenusa(float *cat1, float *cat2){
    float hip;
    hip = sqrt(pow(*cat1, 2) + pow(*cat2, 2));
    return hip;
}