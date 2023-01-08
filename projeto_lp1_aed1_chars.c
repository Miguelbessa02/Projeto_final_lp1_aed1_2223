//
// Created by Miguel on 07/12/2022.
//

#include "projeto_lp1_aed1_chars.h"
#include "projeto_lp1_aed1_ints.h"

int main_chars(int argc, const char * argv[]){
    srand(time(NULL));
    printf("Main Chars\n\n");

    char **s;
    char **ss;
    char **sss;
    int linesS = 4;
    s = alloc_matrix_char(linesS, 20);
    ss = alloc_matrix_char(linesS, 20);
    sss = alloc_matrix_char(linesS, 20);

    //store_key_char(s, linesS, 8);
    //store_key_char(s, linesS, 18);
    //store_key_char(s, linesS, 251);
    //store_key_char(s, linesS, 2013);

    //store_key_char(ss, linesS, 16);
    //store_key_char(ss, linesS, 36);
    //store_key_char(ss, linesS, 5522);
    //store_key_char(ss, linesS, 555588);

    //store_key_char(sss, linesS, 1116);
    //store_key_char(sss, linesS, 1316);
    //store_key_char(sss, linesS, 2522);
    //store_key_char(sss, linesS, 4528);


    //Teste calcular run-length
    //int bipolar_number = 66000;
    //calc_runlength_char(bipolar_number);
    //printf("%d\n", calc_runlength_char(bipolar_number));


    //Teste calcular bipolar a partir da run-length
    //int run_length = 3433;
    //private_key_from_runlength_char(run_length);
    //printf("%d\n", private_key_from_runlength_char(run_length));


    //Teste calcular bipolar a partir da pubkey
    //int pubkey = 8;
    //calc_private_key_char(pubkey);
    //printf("%d\n", calc_private_key_char(pubkey));


    //Teste Get:
    //printf("Private key -> %d\n", get_private_key_char(s, ss, linesS, 18));
    //printf("Run length key -> %d\n", get_runlength_char(ss, sss, linesS, 36));


    //Teste Delete:
    //delete_key_char(s, ss, sss, linesS, 18);
    //list_keys_char(s, ss, sss, linesS, 0);


    //Teste Bulks:
    //bulk_populate_public_keys_char(s, linesS);
    //bulk_compute_private_keys_char(s, ss, linesS);
    //bulk_compute_runlengths_char(ss, sss, linesS);
    //list_keys_char(s, ss, sss, linesS, 0);


    //Teste Partial:
    short a[] = {1, 2, 3, 4};
    short b[] = {1, 2, 3, 4};
    int sizeA = 4;
    int sizeB = 4;
    //printf("%d\n",existsPartial(a, sizeA, b, sizeB));
    //char** ssss = search_private_keys_char(s, ss, linesS, 201);
    //printMatrixChars(ssss, linesS);


    //Teste sort:
    //list_keys_char(s, ss, sss, linesS, 0);
    //sort_matrix_char(s, linesS, 0);
    //sort_all_matrices_char(s, ss, sss, linesS, 0);
    //list_keys_char(s, ss, sss, linesS, 0);


    //Teste files:


    //save_txt_keys_char(s, ss, sss, linesS, "C:\\Users\\Miguel\\OneDrive\\Ambiente de Trabalho\\LP1 22_23\\projeto_final_lp1_22_23\\data\\textchars.txt");
    //load_txt_keys_char(s, ss, sss, linesS, "C:\\Users\\Miguel\\OneDrive\\Ambiente de Trabalho\\LP1 22_23\\projeto_final_lp1_22_23\\data\\textchars.txt");
    //list_keys_char(s, ss, sss, linesS, 0);

    //save_bin_keys_char(s, ss, sss, linesS, "C:\\Users\\Miguel\\OneDrive\\Ambiente de Trabalho\\LP1 22_23\\projeto_final_lp1_22_23\\data\\textchars.bin");
    load_bin_keys_char(s, ss, sss, linesS, "C:\\Users\\Miguel\\OneDrive\\Ambiente de Trabalho\\LP1 22_23\\projeto_final_lp1_22_23\\data\\textchars.bin");
    list_keys_char(s, ss, sss, linesS, 0);
}

/**
 * Create an array of digits in ascii i.e. chars for a given key.
* @param key - long key
 * @return address of array of digits in ascii for a given key
 */
char* key_long_2_digits_char(unsigned long long key){
    int sizearr = number_digits_iterative(key);

    char *psh = calloc(sizearr + 1, sizeof(char));
    *(psh + sizearr) = '\0';
    int index = sizearr - 1;

    while (key > 0) {
        psh[index] = (key % 10) + '0';
        key /= 10;
        index--;
    }

    return psh;
}

/**
 * Receives an array of digits in ascii i.e. chars and returns the long key.
 * @param keydigits - array of digits of key
 * @return address of array of digits for a given key
 */
unsigned long long key_digits_2_long_char(char* keydigits){
    unsigned long long key = 0;
    for (int i = 0; keydigits[i] != '\0'; i++) {
        key = key * 10 + (keydigits[i] - '0');
    }
    return key;
}

/**
 * Calculate the bipolar private key from a given public key (returns the bipolar private key).
 * @param pubkey - public key for which to calculate the private key
 * @return bipolar number representing the private key
 */
unsigned long long calc_private_key_char(unsigned long long pubkey){
    return calc_private_key_int(pubkey);
}

/**
 * Calculate the run-length from a given private key.
 * @param privkey - private key for which to calculate the run-length
 * @return run-length number representing the private key
 */
unsigned long long calc_runlength_char(unsigned long long privkey){
    return calc_runlength_int(privkey);
}

/**
 * Calculate the private key from a run-length.
 * @param runlengthkey - run-length for which to calculate the private key
 * @return private key that corresponds to the runlengthkey arg
 */
unsigned long long private_key_from_runlength_char(unsigned long long runlengthkey){
    return private_key_from_runlength_int(runlengthkey);
}

/**
 * Memory allocation for a char matrix with nlines and ncolumns
 * @param nlines - number of lines
 * @param ncolumns - number of columns
 * @return pointer to the allocated memory of the matrix
 */
char** alloc_matrix_char(int nlines, int ncolumns){
    char **p = NULL;
    p = (char**)malloc(sizeof(char*) * nlines);
    if(p != NULL){
        for(int i = 0; i < nlines; i++){
            *(p + i) = (char *) malloc(sizeof(char) * nlines);
        }

        for(int lin = 0; lin < nlines; lin++){
            for(int col = 0; col < ncolumns; col++){
                *(*(p + lin) + col) = '\0';
            }
        }

        return p;
    }
    printf("Nao conseguiu allocar memoria!\n");
    return p;
}

/**
 * Store a key (pub, priv or run-length) into the first available position of given matrix.
 * @param matrix - matrix to store the key
 * @param lines - matrix number of lines
 * @param key - key to be stored
 */
void store_key_char(char **matrix, int lines, unsigned long long key){
    for (int i = 0; i < lines; i++) {

        if (*(*(matrix + i) + 0) == '\0') {
            char* arrKey = key_long_2_digits_char(key);

            for (int j = 0; *(arrKey + j) != '\0'; j++){
                *(*(matrix + i) + j) = *(arrKey + j);
            }
            free(arrKey);
            return;
        }
    }
}

/**
 * Verify if a given key exists in the matrix.
 * @param matrix - matrix with keys
 * @param lines - matrix number of lines
 * @param key - key to check if it exists
 * @return 1 if it exists, 0 if it doesn't
 */
int exists_key_char(char **matrix, int lines, unsigned long long key){
    char* arrKey = key_long_2_digits_char(key);
    int sizeKey = number_digits_iterative(key);
    int count = 0;

    for (int i = 0; i < lines; i++) {

        for (int j = 0; *(arrKey + j) != '\0'; j++){
            if(*(*(matrix + i) + j) == *(arrKey + j)){
                count++;
                if(count == sizeKey){
                    return 1;
                }
            }
        }
        count = 0;
    }
    return 0;
}

/**
 * Returns the private key corresponding to the given public key
 * @param matrix_kpub - public keys matrix
 * @param matrix_kpriv - private keys matrix
 * @param lines - matrix number of lines
 * @param pubkey - public key for which we want the private key
 * @return private key of the given pubkey
 */
unsigned long long get_private_key_char(char **matrix_kpub, char **matrix_kpriv, int lines, unsigned long long pubkey){
    char* arrKpub = key_long_2_digits_char(pubkey);
    int sizeKey = number_digits_iterative(pubkey);
    int count_kpub = 0;
    int sizeKeypriv = 0;

    if(exists_key_char(matrix_kpub, lines, pubkey) == 1){
        for(int i = 0; i < lines; i++){

            for (int j = 0; *(arrKpub + j) != '\0'; j++){//ciclo for para percorrer a matriz publica

                if(*(*(matrix_kpub + i) + j) == *(arrKpub + j)){
                    count_kpub++;

                    if(count_kpub == sizeKey){

                        return key_digits_2_long_char(*(matrix_kpriv + i));
                    }
                }
            }
        }
    }
    else{
        return -1;
    }
}

/**
 * Returns the run-length key of a given private key
 * @param matrix_kpriv - private keys matrix
 * @param matrix_kcod - run-lengths matrix
 * @param lines - matrix number of lines
 * @param pubkey - public key for which we want the private key
 * @return private key runlength of the given pubkey
 */
unsigned long long get_runlength_char(char **matrix_kpriv, char **matrix_kcod, int lines, unsigned long long privkey){

    char* arrKpriv = key_long_2_digits_char(privkey);
    int sizeKey = number_digits_iterative(privkey);
    int count_kpriv = 0;
    int sizeKeycod = 0;

    if(exists_key_char(matrix_kpriv, lines, privkey) == 1){
        for(int i = 0; i < lines; i++){

            for (int j = 0; *(arrKpriv + j) != '\0'; j++){

                if(*(*(matrix_kpriv + i) + j) == *(arrKpriv + j)){
                    count_kpriv++;
                    if(count_kpriv == sizeKey){

                        return key_digits_2_long_char(*(matrix_kcod + i));
                    }
                }
            }
        }
    }
    else{
        return -1;
    }
}

/**
* @param matrix - matrix with keys
* @param lines - matrix number of lines
* @param key - key to check if it exists
* @return i (index of the line where is the key) or -1 if it doesn´t exist
*/
int index_key_chars(char **matrix, int lines, unsigned long long key){
    char* arrKey = key_long_2_digits_char(key);
    int sizeKey = number_digits_iterative(key);
    int count = 0;

    for (int i = 0; i < lines; i++) {

        for (int j = 0; *(arrKey + j) != '\0'; j++){
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

/**
 * Delete a given public key (and corresponding priv and runlength keys) from all matrices.
 * @param matrix_kpub - public keys matrix
 * @param matrix_kpriv - private keys matrix
 * @param matrix_kcod - run-lengths matrix
 * @param lines - matrix number of lines
 * @param pubkey - public key to delete
 * @return pubkey that was deleted
 */
unsigned long long delete_key_char(char **matrix_kpub, char **matrix_kpriv, char **matrix_kcod, int lines, char pubkey){

    int index = index_key_chars(matrix_kpub, lines, pubkey);
    if(index != -1){
        free(*(matrix_kpub + index));
        free(*(matrix_kpriv + index));
        free(*(matrix_kcod + index));
    }

    for(int i = index; i < (lines - 1); i++){
        *(matrix_kpub + i) = *(matrix_kpub + (i + 1));
        *(matrix_kpriv + i) = *(matrix_kpriv + (i + 1));
        *(matrix_kcod + i) = *(matrix_kcod + (i + 1));
    }

    //Aloca espaço para a última linha que será nova
    *(matrix_kpub + (lines - 1)) = calloc(20, sizeof(short));
    *(matrix_kpriv + (lines - 1)) = calloc(20, sizeof(short));
    *(matrix_kcod + (lines - 1)) = calloc(20, sizeof(short));

    //Limpar nova linha com -1
    for (int j = 0; j < 20; j++) {
        *(*(matrix_kpub + (lines - 1)) + j) = -1;
        *(*(matrix_kpriv + (lines - 1)) + j) = -1;
        *(*(matrix_kcod + (lines - 1)) + j) = -1;
    }
    return pubkey;
}

/**
 * Automatically generate and save a given amount (<lines>) of public keys.
 * @param matrix_kpub - public keys matrix
 * @param lines - matrix number of lines
 */
void bulk_populate_public_keys_char(char **matrix_kpub, int lines){

    int pubKey = 0;

    for(int i = 0; i < lines; i++) {
        if(*(*(matrix_kpub + i) + 0) == '\0'){

            do {
                pubKey = new_public_key_int();
                calc_private_key_char(pubKey);
            } while (calc_private_key_char(pubKey) == -1);
            store_key_char(matrix_kpub, lines, pubKey);
        }
    }
}

/**
 * Automatically calculate, generate and store all private keys for the existing public keys.
 * @param matrix_kpub - public keys matrix
 * @param matrix_kpriv - private keys matrix
 * @param lines - matrix number of lines
 */
void bulk_compute_private_keys_char(char **matrix_kpub, char **matrix_kpriv, int lines){

    int pubKey = 0, privKey = 0;

    for (int i = 0; i < lines; i++) {
        if(*(*(matrix_kpub + i) + 0) != '\0'){

            pubKey = key_digits_2_long_char(*(matrix_kpub + i));
            privKey = calc_private_key_char(pubKey);
            store_key_char(matrix_kpriv, lines, privKey);
        }
    }
}

/**
 * Automatically calculate and store all run-lengths for the existing private keys.
 * @param matrix_kpriv - private keys matrix
 * @param matrix_kcod - run-lengths matrix
 * @param lines - matrix number of lines
 */
void bulk_compute_runlengths_char(char **matrix_kpriv, char **matrix_kcod, int lines){
    int privKey = 0, kcod = 0;

    for (int i = 0; i < lines; i++) {
        if(*(*(matrix_kpriv + i) + 0) != '\0'){

            privKey = key_digits_2_long_char(*(matrix_kpriv + i));
            kcod = calc_runlength_char(privKey);
            store_key_char(matrix_kcod, lines, kcod);
        }
    }
}

/**
 * Return a list of all private keys matching a given partial public key.
 * @param matrix_kpub - public keys matrix
 * @param matrix_kpriv - private keys matrix
 * @param lines - matrix number of lines
 * @param partialpubkey - part of public key to filter the private keys
 * @return array of private keys matching the partialpubkey
 */
char** search_private_keys_char(char **matrix_kpub, char **matrix_kpriv, int lines, unsigned long long partialpubkey){

    int size_partialpubkey = number_digits_iterative(partialpubkey);
    char* arr_partialpubkey = key_long_2_digits_char(partialpubkey);
    int size_kpub = 0;
    int priv_key = 0;

    char** all_priv_keys = alloc_matrix_char(lines, 20);

    for(int i = 0; i < lines; i++) {//percorrer a matriz linha a linha

        for(size_kpub = 0; *(*(matrix_kpub + i) + size_kpub) != '\0'; size_kpub++){//calcular o tamanho da key publica
        }

        if(existsPartialChars(*(matrix_kpub + i), size_kpub, arr_partialpubkey, size_partialpubkey) == 1){

            priv_key = key_digits_2_long_char(*(matrix_kpriv + i));
            store_key_char(all_priv_keys, lines, priv_key);
        }
        size_kpub = 0;
    }
    return all_priv_keys;
}

/**
 * Sort a matrix keys in ascending or descending order
 * @param matrix - matrix to be sorted
 * @param lines - matrix number of lines
 * @param order - order == 1 ? ascending : descending
 */
void sort_matrix_char(char **matrix, int lines, int order){

    int key = 0;
    int* arr_all_keys = calloc(lines, sizeof(int));

    for(int i = 0; i < lines; i++){

        key = key_digits_2_long_char(*(matrix + i));
        arr_all_keys[i] = key;
    }

    if(order == 1){
        sort_array_ascending(lines, arr_all_keys);

        for(int i = 0; i < lines; i++){
            for(int j = 0; *(*(matrix + i) + j) != '\0'; j++){
                *(*(matrix + i) + j) = '\0';
            }
            store_key_char(matrix, lines, arr_all_keys[i]);
        }
    }
    if(order == 0){
        sort_array_descending(lines, arr_all_keys);

        for(int i = 0; i < lines; i++){
            for(int j = 0; *(*(matrix + i) + j) != '\0'; j++){
                *(*(matrix + i) + j) = '\0';
            }
            store_key_char(matrix, lines, arr_all_keys[i]);
        }
    }
}

/**
 * Sort all matrices keys in ascending or descending order
 * @param matrix_kpub - public keys matrix
 * @param matrix_kpriv - private keys matrix
 * @param matrix_kcod - run-lengths matrix
 * @param lines - matrix number of lines
 * @param order - order == 1 ? ascending : descending
 */
void sort_all_matrices_char(char **matrix_kpub, char **matrix_kpriv, char **matrix_kcod, int lines, int order){
    sort_matrix_char(matrix_kpub, lines, order);
    sort_matrix_char(matrix_kpriv, lines, order);
    sort_matrix_char(matrix_kcod, lines, order);
}

/**
 * Print all keys on the console, sorted by pubkeys sizes (i.e. number of digits).
 * @param matrix_kpub - public keys matrix
 * @param matrix_kpriv - private keys matrix
 * @param matrix_kcod - run-lengths matrix
 * @param lines - matrix number of lines
 * @param order - order == 0 ? current order : order == 1 ? ascending : descending
 */
void list_keys_char(char **matrix_kpub, char **matrix_kpriv, char **matrix_kcod, int lines, int order){

    /*
    if(order != 0){
        sort_matrix_int(matrix_kpub, lines, order);
    }
    */

    printf("Matriz chars keys publicas:\n");
    for(int i = 0; i < lines; i++){
        for(int j = 0; *(*(matrix_kpub + i) + j) != '\0'; j++){
            printf("%c", *(*(matrix_kpub + i) + j));
        }
        printf("\n");
    }
    printf("\n");

    printf("Matriz chars keys privadas:\n");
    for(int i = 0; i < lines; i++){
        for(int j = 0; *(*(matrix_kpriv + i) + j) != '\0'; j++){
            printf("%c", *(*(matrix_kpriv + i) + j));
        }
        printf("\n");
    }
    printf("\n");

    printf("Matriz chars keys run-lengths:\n");
    for(int i = 0; i < lines; i++){
        for(int j = 0; *(*(matrix_kcod + i) + j) != '\0'; j++){
            printf("%c", *(*(matrix_kcod + i) + j));
        }
        printf("\n");
    }
    printf("\n");
}

/**
 * Save all matrix data to a text file
 * @param matrix_kpub - public keys matrix
 * @param matrix_kpriv - private keys matrix
 * @param matrix_kcod - run-lengths matrix
 * @param lines - matrix number of lines
 * @param filename - name of the text file where to store the data
 */
void save_txt_keys_char(char **matrix_kpub, char **matrix_kpriv, char **matrix_kcod, int lines, char filename[]){

    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        fprintf(stderr, "Erro abrir ficheiro: %s\n", filename);
        return;
    }

    for(int i = 0; i < lines; i++){

        fprintf(fp, "Key publica: ");
        for(int j = 0; *(*(matrix_kpub + i) + j) != '\0'; j++){
            fprintf(fp,"%c", *(*(matrix_kpub + i) + j));
        }
        fprintf(fp, "\n");

        fprintf(fp, "Key privada: ");
        for(int j = 0; *(*(matrix_kpriv + i) + j) != '\0'; j++){
            fprintf(fp,"%c", *(*(matrix_kpriv + i) + j));
        }
        fprintf(fp, "\n");

        fprintf(fp, "Key run length: ");
        for(int j = 0; *(*(matrix_kcod + i) + j) != '\0'; j++){
            fprintf(fp,"%c", *(*(matrix_kcod + i) + j));
        }
        fprintf(fp, "\n\n");
    }
    fclose(fp);
}

/**
 * Loads data into the matrices from a text file.
 * @param matrix_kpub - public keys matrix
 * @param matrix_kpriv - private keys matrix
 * @param matrix_kcod - run-lengths matrix
 * @param lines - matrix number of lines
 * @param filename - name of the text file to load data from
 */
void load_txt_keys_char(char **matrix_kpub, char **matrix_kpriv, char **matrix_kcod, int lines, char filename[]){

    int pubKey = 0;
    int privKey = 0;
    int kcodKey = 0;


    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        fprintf(stderr, "Erro abrir ficheiro: %s\n", filename);
        return;
    }

    for (int i = 0; i < lines; i++) {

        fscanf(fp, "Key publica: %d\n", &pubKey);
        store_key_char(matrix_kpub, lines, pubKey);

        fscanf(fp, "Key privada: %d\n", &privKey);
        store_key_char(matrix_kpriv, lines, privKey);

        fscanf(fp, "Key run length: %d\n\n", &kcodKey);
        store_key_char(matrix_kcod, lines, kcodKey);
    }
    fclose(fp);
}

/**
 * Save all matrix data to a binary file
 * @param matrix_kpub - public keys matrix
 * @param matrix_kpriv - private keys matrix
 * @param matrix_kcod - run-lengths matrix
 * @param lines - matrix number of lines
 * @param filename - name of the binary file where to store the data
 */
void save_bin_keys_char(char **matrix_kpub, char **matrix_kpriv, char **matrix_kcod, int lines, char filename[]){

    FILE *fp = fopen(filename, "wb");
    if (fp == NULL) {
        fprintf(stderr, "Erro abrir ficheiro: %s\n", filename);
        return;
    }


    for(int i = 0; i < lines; i++){

        for(int j = 0; *(*(matrix_kpub + i) + j) != '\0'; j++){
            fwrite(((matrix_kpub + i) + j), sizeof(char), 1, fp);
        }

        for(int j = 0; *(*(matrix_kpriv + i) + j) != '\0'; j++){
            fwrite(((matrix_kpriv + i) + j), sizeof(char), 1, fp);
        }

        for(int j = 0; *(*(matrix_kcod + i) + j) != '\0'; j++){
            fwrite(((matrix_kcod + i) + j), sizeof(char), 1, fp);
        }

    }

    fclose(fp);
}

/**
 * Loads data into the matrices from a binary file.
 * @param matrix_kpub - public keys matrix
 * @param matrix_kpriv - private keys matrix
 * @param matrix_kcod - run-lengths matrix
 * @param lines - matrix number of lines
 * @param filename -name of the binary file to load data from
 */
void load_bin_keys_char(char **matrix_kpub, char **matrix_kpriv, char **matrix_kcod, int lines, char filename[]){
    int pubKey = 0;
    int privKey = 0;
    int kcodKey = 0;

    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        fprintf(stderr, "Error opening file: %s\n", filename);
        return;
    }

    for(int i = 0; i < lines; i++){

        for(int j = 0; *(*(matrix_kpub + i) + j) != '\0'; j++){
            fread(&pubKey, sizeof(char), 1, fp);
        }
        store_key_char(matrix_kpub, lines, pubKey);

        for(int j = 0; *(*(matrix_kpriv + i) + j) != '\0'; j++){
            fread(&privKey, sizeof(char), 1, fp);
        }
        store_key_char(matrix_kpriv, lines, privKey);

        for(int j = 0; *(*(matrix_kcod + i) + j) != '\0'; j++){
            fread(&kcodKey, sizeof(char), 1, fp);
        }
        store_key_char(matrix_kcod, lines, kcodKey);

    }
    fclose(fp);
}