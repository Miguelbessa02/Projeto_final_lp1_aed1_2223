//
// Created by Miguel on 15/12/2022.
//

#ifndef PROJETO_FINAL_LP1_22_23_FUNCOES_AULAS_H
#define PROJETO_FINAL_LP1_22_23_FUNCOES_AULAS_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <inttypes.h>

/**
 * This function receives an integer and iteratively returns the number of digits,
 * e.g. 218 = 3 digits (2, 1, 8).
 *  @param n - an int value to be sperated in digits.
 *  @return the number of digits found on the submitted int value.
 */
int number_digits_iterative(int n);

/**
 * Função que imprime todos o valor de cada elemento de um array
 * @param a - apontador para o primeiro elemento do array
 * @param size - numero de elementos do array
 */
void print_Array(const short* a, int size);

#endif //PROJETO_FINAL_LP1_22_23_FUNCOES_AULAS_H
