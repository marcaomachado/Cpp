#include <iostream>
using namespace std;

int main(){
    // int vet[2] = {9, 0};

    // cout << vet << endl;
    // cout << &vet << endl;
    // cout << &vet[0] << endl;
    // cout << vet[0] << endl;


    // 1) Declare uma variável do tipo inteiro e atribua o valor '10'
    int var = 10;

    // 2) Declare um ponteiro para inteiros e inicialize com valor nulo
    int *ptr = nullptr;

    // 3) Declare um vetor de inteiros e inicialize com valores de 9 a 0 (nessa ordem)
    int vet[2] = {9, 0};

    // 4) Imprima o ENDEREÇO da variável declarada em (1)
    cout << &var << endl;

    // 5) Imprima o VALOR da variável declarada em (1)
    cout << var << endl;

    // 6) Imprima o ENDEREÇO da variável declarada em (2)
    cout << &ptr << endl;
    
    // 7) Imprima o VALOR da variável declarada em (2)
    cout << ptr << endl;

    // 8) Imprima o ENDEREÇO da variável declarada em (3)
    cout << &vet << endl;

    // 9) Imprima o ENDEREÇO da primeira posição da variável declarada em (3)
    cout << vet << endl;

    // 10) Imprima o VALOR da primeira posição da variável declarada em (3)
    cout << vet[0] << endl;

    // 11) Atribua o ENDEREÇO da variável declarada em (1) à variável declarada em (2)
    ptr = &var;

    // 12) Imprima o VALOR da variável declarada em (2)
    cout << ptr << endl;

    // 13) Imprima o VALOR guardado no ENDEREÇO apontado por (2)
    cout << *ptr << endl;

    // 14) Imprima o resultado da comparação do ENDEREÇO de (1) e do VALOR de (2)
    cout << (&var == ptr) << endl;

    // 15) Coloque o VALOR '5' no ENDEREÇO apontado por (2)
    *ptr = 5;

    // 16) Imprima o VALOR da variável declarada em (1)
    cout << var << endl;

    // 17) Atribua o ENDEREÇO da variável (3) à variável declarada em (2)
    ptr = vet;

    // 18) Imprima o VALOR da variável declarada em (2)
    cout << ptr << endl;

    // 19) Imprima o VALOR guardado no ENDEREÇO apontado por (2)
    cout << *ptr << endl;

    // 20) Atribua o ENDEREÇO da primeira posição de (3) à variável declarada em (2)
    ptr = vet;

    // 21) Imprima o VALOR da variável declarada em (2)
    cout << ptr << endl;

    // 22) Imprima o VALOR guardado no ENDEREÇO apontado por (2)
    cout << *ptr << endl;

    // 23) Multiplique todos os valores do vetor declarado em (3) por '10', porém manipulando apenas a variável (2)
    *ptr = *ptr * 10;
    *(ptr + 1) = *(ptr + 1) * 10;
    
}