#include <cstdlib>
#include <iostream>
#include <locale.h>

#define MAX 50
using namespace std;

typedef struct com {
    string nome;
    int comprimento;
    int largura;
    int area;
    float media;
    int numero;
    float potencia;
    float lumens;


} COMODO;

typedef struct residencia {
    COMODO comodo[MAX];
    int cont;
    float valorW;
    float valorLed;
} RESIDENCIA;

void criar(RESIDENCIA *resid);
int residVazia(RESIDENCIA resid);
int residCheia(RESIDENCIA resid);
int inserirPosicao(RESIDENCIA *resid, int pos, COMODO c1);
void eliminarComodo(RESIDENCIA *resid, int numero, int pos);
void residenciaCompleta(RESIDENCIA resid);
int trocaPorLeds(RESIDENCIA *resid);
int calcularPot(RESIDENCIA *resid);
int calcularValor(RESIDENCIA *resid);

int main(int argc, char *argv[]) {
    setlocale(LC_ALL, "Portuguese");
    RESIDENCIA resid;
    COMODO c1;
    int pos = 1;
    int numero;

    int op;

    do {
        cout << " ___________________________________________" << endl;
        cout << "|             ...::: MENU :::.              |" << endl;
        cout << "|                                           |" << endl;
        cout << "| [1] - Criar Residência                    |" << endl;
        cout << "| [2] - Inserir cômodo:                     |" << endl;
        cout << "| [3] - Remover cômodo:                     |" << endl;
        cout << "| [4] - Verificar se está cheia             |" << endl;
        cout << "| [5] - Verificar se está vazia             |" << endl;
        cout << "| [6} - Acessar todos cômodos da residência |" << endl;
        cout << "| [7] - Sair                                |" << endl;
        cout << "|___________________________________________|" << endl;
        cout << "Opção: " << endl;
        cin>>op;
        
        system("clear");
        switch (op) {
            case 1:
                criar(&resid);
                break;

            case 2:
                inserirPosicao(&resid, pos, c1);
                break;

            case 3:
                eliminarComodo(&resid, numero, pos);
                break;

            case 4:
                residCheia(resid);
                break;

            case 5:
                residVazia(resid);
                break;

            case 6:
                residenciaCompleta(resid);
                break;
        }

    } while (op != 7);

    //system("PAUSE");
    return EXIT_SUCCESS;
}




//CRIAR

void criar(RESIDENCIA *resid) {
    resid->cont = 0;
    cout << "Residência criada" << endl << endl;
}

//VAZIA

int residVazia(RESIDENCIA resid) {
    if (resid.cont == 0) {
        cout << "Residência está vazia" << endl << endl;
    } else {
        cout << "A residência contém cômodos!" << endl << endl;
    }
}

//CHEIA

int residCheia(RESIDENCIA resid) {
    if (resid.cont == MAX) {
        cout << "Residência está cheia" << endl << endl;
    } else {
        cout << "Residência com espaço" << endl << endl;
    }
}

//INSERIR COMODO

int inserirPosicao(RESIDENCIA *resid, int pos, COMODO c1) {
    cout << "Nome do cômodo: " << endl;
    cin >> c1.nome;
    cout << "Valor do comprimento: " << endl;
    cin >> c1.comprimento;
    cout << "Valor da largura: " << endl;
    cin >> c1.largura;
    cout << "Posição: " << endl;
    cin >> c1.numero;
    cout << "Média de horas diárias que as luzes ficam ligadas: " << endl;
    cin >> c1.media;

    int i;

    if (resid->cont == MAX || pos > resid->cont + 1) {
        return (0);
    }
    for (i = resid->cont; i > resid->cont; i--) {
        resid->comodo[i] = resid->comodo[i - 1];
    }

    resid->comodo[i] = c1;
    resid->cont++;
    return (1);
}

//ELIMINAR

void eliminarComodo(RESIDENCIA *resid, int numero, int pos) {
    cout << "Digite a posição do cômodo que deseja apagar: " << endl;
    cin>>numero;
    int i;
    bool aux;
    for (i = 0; i <= pos; i++) {
        if (numero == resid->comodo[i].numero) {
            resid->comodo[i] = resid->comodo[i + 1];
            cout << "Removido com sucesso!" << endl;
            aux = false;
        }
    }
    resid->cont--;
    if (aux) {
        cout << "Posição não encontrada!" << endl;
    }
}


//CALCULAR 

int calcularValor(RESIDENCIA *resid) {

    float calcularPotencia = 0;
    float valorComodo = 0;

    for (int i = 0; i < resid->cont; i++) {
        calcularPotencia = resid->comodo[i].potencia * 0.41; // potencia * valor do quillowat

        valorComodo += resid->comodo[i].media * calcularPotencia;

    }
    resid->valorW = valorComodo;
}

int calcularPot(RESIDENCIA *resid) {
    for (int i = 0; i < resid->cont; i++) {
        resid->comodo[i].area = resid->comodo[i].comprimento * resid->comodo[i].largura; //area = comprimento * largura
        resid->comodo[i].potencia = resid->comodo[i].area * 20; //20 =  valor por m²
        resid->comodo[i].lumens = resid->comodo[i].potencia * 4; // potencia lumens = potencia * 4  
    }
}

int trocaPorLeds(RESIDENCIA *resid) {
    resid->valorLed = resid->valorW / 8;
}

//TODOS CÔMODOS

void residenciaCompleta(RESIDENCIA resid) {
    calcularPot(&resid);
    calcularValor(&resid);
    trocaPorLeds(&resid);
    for (int i = 0; i < resid.cont; i++) {
        cout << "Posição: " << resid.comodo[i].numero << endl;
        cout << "Nome: " << resid.comodo[i].nome << endl;
        cout << "Comprimento do Cômodo: " << resid.comodo[i].comprimento << endl;
        cout << "Largura do Cômodo: " << resid.comodo[i].largura << endl;
        cout << "Média de horas diárias que as luzes ficam ligadas: " << resid.comodo[i].comprimento << endl;
        cout << "Área do cômodo: " << resid.comodo[i].area << endl;
        cout << "Pôtencia em quillowats necessária para iluminar seu cômodo: " << resid.comodo[i].potencia << endl;
        cout << "Pôtencia em lumens necessária para iluminar seu cômodo: " << resid.comodo[i].lumens << endl << endl;
    }
    cout << "Valor da conta de sua residência ao trocar por leds: " << resid.valorLed << " R$. " << endl;
    cout << "Valor da conta de sua residência com outros tipos de lâmpadas: " << resid.valorW << " R$. " << endl;


}
