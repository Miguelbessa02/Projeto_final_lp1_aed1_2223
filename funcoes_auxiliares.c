//
// Created by Miguel on 08/01/2023.
//

#include "funcoes_auxiliares.h"


/**
 * Funcao para imprimir uma matriz de ints
 * @param matrix matriz
 * @param lines numero de linhas da matriz
 */
void printMatrixInts(short **matrix, int lines){
    for(int i = 0; i < lines; i++){
        for(int j = 0; *(*(matrix + i) + j) != -1; j++){
            printf("%d", *(*(matrix + i) + j));
        }
        printf("\n");
    }
}

/**
 * Funcao para imprimir uma matriz de ints
 * @param matrix matriz
 * @param lines numero de linhas da matriz
 */
void printMatrixChars(char **matrix, int lines){
    for(int i = 0; i < lines; i++){
        for(int j = 0; *(*(matrix + i) + j) != '\0'; j++){
            printf("%c", *(*(matrix + i) + j));
        }
        printf("\n");
    }
}

/**
 * Function to sort an array with n size by ascending order
 * @param n size of array
 * @param arr array
 */
void sort_array_ascending(int n, int arr[n]){
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (arr[i] < arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

/**
 * Function to sort an array with n size by descending order
 * @param n size of array
 * @param arr array
 */
void sort_array_descending(int n, int arr[n]){
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

/**
 * checks if arr_partialpubkey array exists in arr_kpub array
 * @param arr_kpub array of arr_kpub
 * @param size_kpub size of arr_kpub array
 * @param arr_partialpubkey array of arr_partialpubkey
 * @param size_partialpubkey size of arr_partialpubkey
 * @return returns 1 if the arr_partialpubkey array exists in arr_kpub or 0 if it doesnt
 */
int existsPartial(const short* arr_kpub, int size_kpub, const short* arr_partialpubkey, int size_partialpubkey){

    int flag_size_partial_1 = 0;

    if(size_partialpubkey == 1){
        for(int i = 0; i < size_kpub; i++){
            if(arr_kpub[i] == arr_partialpubkey[0]){
                flag_size_partial_1++;
            }
        }
        if(flag_size_partial_1 > 0){
            return 1;
        }
        else{
            return 0;
        }
    }
    else{
        // Iterate through each element of arr_kpub
        for (int i = 0; i < size_kpub; i++){
            // Check if arr_partialpubkey starts at this element
            if (arr_kpub[i] == arr_partialpubkey[0]){
                // Initialize a flag to track whether all elements of arr_partialpubkey are found in arr_kpub
                int found = 1;
                // Iterate through each element of arr_partialpubkey
                for (int j = 0; j < size_partialpubkey; j++){
                    // Check if the element at this index in arr_kpub matches the element at this index in arr_partialpubkey
                    if (arr_kpub[i+j] != arr_partialpubkey[j]){
                        found = 0;
                        break;
                    }
                }
                // If all elements of arr_partialpubkey are found in arr_kpub, return 1
                if (found){
                    return 1;
                }
            }
        }
        // If arr_partialpubkey is not found in arr_kpub, return 0
        return 0;
    }
}

/**
 * checks if arr_partialpubkey array exists in arr_kpub array
 * @param arr_kpub array of arr_kpub
 * @param size_kpub size of arr_kpub array
 * @param arr_partialpubkey array of arr_partialpubkey
 * @param size_partialpubkey size of arr_partialpubkey
 * @return returns 1 if the arr_partialpubkey array exists in arr_kpub or 0 if it doesnt
 */
int existsPartialChars(const char* arr_kpub, int size_kpub, const char* arr_partialpubkey, int size_partialpubkey){

    int flag_size_partial_1 = 0;

    if(size_partialpubkey == 1){
        for(int i = 0; i < size_kpub; i++){
            if(arr_kpub[i] == arr_partialpubkey[0]){
                flag_size_partial_1++;
            }
        }
        if(flag_size_partial_1 > 0){
            return 1;
        }
        else{
            return 0;
        }
    }
    else{
        // Iterate through each element of arr_kpub
        for (int i = 0; i < size_kpub; i++){
            // Check if arr_partialpubkey starts at this element
            if (arr_kpub[i] == arr_partialpubkey[0]){
                // Initialize a flag to track whether all elements of arr_partialpubkey are found in arr_kpub
                int found = 1;
                // Iterate through each element of arr_partialpubkey
                for (int j = 0; j < size_partialpubkey; j++){
                    // Check if the element at this index in arr_kpub matches the element at this index in arr_partialpubkey
                    if (arr_kpub[i+j] != arr_partialpubkey[j]){
                        found = 0;
                        break;
                    }
                }
                // If all elements of arr_partialpubkey are found in arr_kpub, return 1
                if (found){
                    return 1;
                }
            }
        }
        // If arr_partialpubkey is not found in arr_kpub, return 0
        return 0;
    }
}

/**
 * Passar os numeros de um array para uma variavel long long
 * @param a - array que contem os numeros
 * @return retorna o numero numa variavel long long
 */
unsigned long long array_para_numero(const int* a, int size){
    int num = 0;

    for(int i = 0; i < size; i++){
        num *= 10;
        num += a[i];
    }
    return num;
}

/**
 * Calcular se um numero é bipolar ou não
 * @param bipolar_number
 * @return retorna 1 se é bipolar ou 0 se não é bipolar
 */
int verificar_se_e_bipolar(unsigned long long bipolar_number){
    int digits_count = number_digits_iterative(bipolar_number); // numero de digitos do bipolar_number
    int arr[digits_count];

    for(int i = --digits_count; i >= 0; i--){ //guardar no array o numero
        arr[i] = bipolar_number % 10;
        bipolar_number /= 10;
    }

    int count = 0;
    for(int i = 0; i < digits_count; i++){ // contar quantas vezes os digitos do numero mudam
        if(arr[i] != arr[i + 1]){
            count++;
        }
    }

    if(count == 1){ // se mudar mais que uma vez nao e bipolar
        return 1;
    }
    else{
        return 0;
    }
}

/**
 * Calcular se o numero bipolar é multiplo de pubkey
 * @param bipolar_number
 * @return retorna 1 se é multiplo ou 0 se não é multiplo
 */
int verificar_se_e_multiplo(unsigned long long pubkey, unsigned long long bipolar_number){
    return bipolar_number % pubkey == 0;
}

/**
* @param matrix - matrix with keys
* @param lines - matrix number of lines
* @param key - key to check if it exists
* @return i (index of the line where is the key) or -1 if it doesn´t exist
*/
int index_key_int(short **matrix, int lines, unsigned long long key){
    short* arrKey = key_long_2_digits_int(key);
    int sizeKey = number_digits_iterative(key);
    int count = 0;

    for (int i = 0; i < lines; i++) {

        for (int j = 0; *(arrKey + j) != -1; j++){
            if(*(*(matrix + i) + j) == *(arrKey + j)){
                count++;
                if(count == sizeKey){
                    return i;
                }
            }
        }
        count = 0;

    }
    return -1;
}