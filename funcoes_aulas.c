//
// Created by Miguel on 15/12/2022.
//

#include "funcoes_aulas.h"

/**
 * This function receives an integer and iteratively returns the number of digits,
 * e.g. 218 = 3 digits (2, 1, 8).
 *  @param n - an int value to be sperated in digits.
 *  @return the number of digits found on the submitted int value.
 */
int number_digits_iterative(int n){
    int count=0;
    while (n>0){
        count++;
        n/=10;
    }
    return count;
}

/**
 * Função que imprime todos o valor de cada elemento de um array
 * @param a - apontador para o primeiro elemento do array
 * @param size - numero de elementos do array
 */
void print_Array(const short* a, int size){
    for(int i = 0; i < size; i++){
        printf("%d", *(a + i));
    }
}










