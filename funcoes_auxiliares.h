//
// Created by Miguel on 08/01/2023.
//

#ifndef PROJETO_FINAL_LP1_22_23_FUNCOES_AUXILIARES_H
#define PROJETO_FINAL_LP1_22_23_FUNCOES_AUXILIARES_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <inttypes.h>

#include "funcoes_aulas.h"
#include "projeto_lp1_aed1_ints.h"
#include "projeto_lp1_aed1_chars.h"

/**
 * Funcao para imprimir uma matriz de ints
 * @param matrix matriz
 * @param lines numero de linhas da matriz
 */
void printMatrixInts(short **matrix, int lines);

/**
 * Funcao para imprimir uma matriz de ints
 * @param matrix matriz
 * @param lines numero de linhas da matriz
 */
void printMatrixChars(char **matrix, int lines);

/**
 * Function to sort an array with n size by ascending order
 * @param n size of array
 * @param arr array
 */
void sort_array_ascending(int n, int arr[n]);

/**
 * Function to sort an array with n size by descending order
 * @param n size of array
 * @param arr array
 */
void sort_array_descending(int n, int arr[n]);

/**
 * checks if partial key exists
 * @param matrix - matrix with keys
 * @param lines - matrix number of lines
 * @param key - key to check if it exists
 * @return 1 if it exists, 0 if it doesn't
 */
int existsPartial(const short* arr_kpub, int size_kpub, const short* arr_partialpubkey, int size_partialpubkey);

/**
 * checks if arr_partialpubkey array exists in arr_kpub array
 * @param arr_kpub array of arr_kpub
 * @param size_kpub size of arr_kpub array
 * @param arr_partialpubkey array of arr_partialpubkey
 * @param size_partialpubkey size of arr_partialpubkey
 * @return returns 1 if the arr_partialpubkey array exists in arr_kpub or 0 if it doesnt
 */
int existsPartialChars(const char* arr_kpub, int size_kpub, const char* arr_partialpubkey, int size_partialpubkey);

/**
 * Passar os numeros de um array para uma variavel long long
 * @param a - array que contem os numeros
 * @return retorna o numero numa variavel long long
 */
unsigned long long array_para_numero(const int* a, int size);

/**
 * Calcular se um numero é bipolar ou não
 * @param bipolar_number
 * @return retorna 1 se é bipolar ou 0 se não é bipolar
 */
int verificar_se_e_bipolar(unsigned long long bipolar_number);

/**
 * Calcular se o numero bipolar é multiplo de pubkey
 * @param bipolar_number
 * @return retorna 1 se é multiplo ou 0 se não é multiplo
 */
int verificar_se_e_multiplo(unsigned long long pubkey, unsigned long long bipolar_number);

/**
* @param matrix - matrix with keys
* @param lines - matrix number of lines
* @param key - key to check if it exists
* @return i (index of the line where is the key) or -1 if it doesn´t exist
*/
int index_key_int(short **matrix, int lines, unsigned long long key);



#endif //PROJETO_FINAL_LP1_22_23_FUNCOES_AUXILIARES_H
