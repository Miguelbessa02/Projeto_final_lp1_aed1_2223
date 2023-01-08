//
// Created by Miguel on 07/12/2022.
//

#include "projeto_lp1_aed1_ints.h"
#include "projeto_lp1_aed1_chars.h"

int main_ints(int argc, const char * argv[]) {
    srand(time(NULL));
    printf("Main Ints\n\n");

    short **s;
    short **ss;
    short **sss;
    int linesS = 4;
    s = alloc_matrix_int(linesS, 20);
    ss = alloc_matrix_int(linesS, 20);
    sss = alloc_matrix_int(linesS, 20);

    //store_key_int(s, linesS, 8);
    //store_key_int(s, linesS, 18);
    //store_key_int(s, linesS, 251);
    //store_key_int(s, linesS, 2013);

    //store_key_int(ss, linesS, 16);
    //store_key_int(ss, linesS, 36);
    //store_key_int(ss, linesS, 5522);
    //store_key_int(ss, linesS, 555588);

    //store_key_int(sss, linesS, 1116);
    //store_key_int(sss, linesS, 1316);
    //store_key_int(sss, linesS, 2522);
    //store_key_int(sss, linesS, 4528);

    //Teste funcao random:
    //printf("%d\n", new_public_key_int());


    //Teste calcular run-length
    //int bipolar_number = 66000;
    //calc_runlength_int(bipolar_number);
    //printf("%d\n", calc_runlength_int(bipolar_number));


    //Teste calcular bipolar a partir da run-length
    //int run_length = 3433;
    //private_key_from_runlength_int(run_length);
    //printf("%d\n", private_key_from_runlength_int(run_length));


    //Teste calcular bipolar a partir da pubkey
    //int pubkey = 8;
    //calc_private_key_int(pubkey);
    //printf("%d\n", calc_private_key_int(pubkey));


    //Teste Get:
    //printf("Private key -> %d\n", get_private_key_int(s, ss, linesS, 18));
    //printf("Run length key -> %d\n", get_runlength_int(ss, sss, linesS, 36));


    //Teste Delete:
    //delete_key_int(s, ss, sss, linesS, 251);
    //list_keys_int(s, ss, sss, linesS, 0);


    //Teste Bulks:
    //bulk_populate_public_keys_int(s, linesS);
    //bulk_compute_private_keys_int(s, ss, linesS);
    //bulk_compute_runlengths_int(ss, sss, linesS);
    //list_keys_int(s, ss, sss, linesS, 0);


    //Teste Partial:
    short a[] = {1, 2, 3, 4};
    short b[] = {1, 2, 3, 4};
    int sizeA = 4;
    int sizeB = 4;
    //printf("%d\n",existsPartial(a, sizeA, b, sizeB));
    //short** ssss = search_private_keys_int(s, ss, linesS, 8);
    //printMatrixInts(ssss, linesS);


    //Teste Sort:
    //list_keys_int(s, ss, sss, linesS, 0);
    //sort_matrix_int(s, linesS, 0);
    //sort_all_matrices_int(s, ss, sss, linesS, 0);
    //list_keys_int(s, ss, sss, linesS, 0);


    //Teste Files:
    //save_txt_keys_int(s, ss, sss, linesS, "C:\\Users\\Miguel\\OneDrive\\Ambiente de Trabalho\\LP1 22_23\\projeto_final_lp1_22_23\\data\\textints.txt");
    //load_txt_keys_int(s, ss, sss, linesS, "C:\\Users\\Miguel\\OneDrive\\Ambiente de Trabalho\\LP1 22_23\\projeto_final_lp1_22_23\\data\\textints.txt");
    //list_keys_int(s, ss, sss, linesS, 0);

    //save_bin_keys_int(s, ss, sss, linesS, "C:\\Users\\Miguel\\OneDrive\\Ambiente de Trabalho\\LP1 22_23\\projeto_final_lp1_22_23\\data\\textints.bin");
    load_bin_keys_int(s, ss, sss, linesS, "C:\\Users\\Miguel\\OneDrive\\Ambiente de Trabalho\\LP1 22_23\\projeto_final_lp1_22_23\\data\\textints.bin");
    list_keys_int(s, ss, sss, linesS, 0);
}

/**
 * Generate a random integer to be used as the public key.
 * @return random number representing a public key
 */
unsigned long long new_public_key_int(void){
    return rand() % 9999 + 1; //tem um range para conseguir calcular o bipolar correspondente facilmente
}

/**
 * Create an array of digits for a given key.
* @param key - long key
 * @return address of array of digits for a given key
 */
short* key_long_2_digits_int(unsigned long long key){
    int sizearr = number_digits_iterative(key); // numero de digitos da key
    short *psh = calloc(sizearr, sizeof(short));
    *(psh + sizearr) = -1; //colocar -1 no final da key

    for(int i = --sizearr; i >= 0; i--){ //da store dos digitos da key no array
        *(psh + i) = key % 10;
        key /= 10;
    }
    return psh;
}

/**
 * Receives an array of digits and returns the long key.
 * @param keydigits - array of digits of key
 * @return address of array of digits for a given key
 */
unsigned long long key_digits_2_long_int(short* keydigits){
    int sizeArr = 0, i = 0, num = 0;
    while(keydigits[i] != -1){ //calcular o size do array
        sizeArr++;
        i++;
    }
    for(int j = 0; j < sizeArr; j++){ //da store ao numero que esta nos indices do array na variavel num
        num *= 10;
        num += keydigits[j];
    }
    return num;
}

/**
 * Calculate the bipolar private key from a given public key (returns the bipolar private key).
 * @param pubkey - public key for which to calculate the private key
 * @return bipolar number representing the private key
 */
unsigned long long calc_private_key_int(unsigned long long pubkey){
    for(unsigned long long i = (pubkey + 1); i < 99999999 ; i++){
        if(verificar_se_e_multiplo(pubkey, i) && verificar_se_e_bipolar(i)){
            return i;
        }
    }
    return -1;
}

/**
 * Calculate the run-length from a given private key.
 * @param privkey - private key for which to calculate the run-length
 * @return run-length number representing the private key
 */
unsigned long long calc_runlength_int(unsigned long long privkey){
    int count = 0;
    int last_digit = privkey % 10;
    int res = 0, size = 4;

    int arr[size];

    while(privkey > 0){
        res = privkey % 10;
        if(res == last_digit){
            count++;
        }
        else{
            arr[3] = last_digit;
            arr[2] = count;
            count = 1;
            last_digit = res;
        }
        privkey /= 10;
    }
    arr[1] = res;
    arr[0] = count;

    return array_para_numero(arr, size);
}

/**
 * Calculate the private key from a run-length.
 * @param runlengthkey - run-length for which to calculate the private key
 * @return private key that corresponds to the runlengthkey arg
 */
unsigned long long private_key_from_runlength_int(unsigned long long runlengthkey){
    int privkey = 0;
    int arr[4];

    for(int i = 3; i >= 0; i--){
        arr[i] = runlengthkey % 10;
        runlengthkey /= 10;
    }

    int first_size = arr[0];
    int second_size = arr[2];

    int size = first_size + second_size;
    int arr_bipolar_number[size];

    for(int j = 0; j < first_size; j++){
        if(arr[0] > 0){
            arr_bipolar_number[j] = arr[1];
            arr[0]--;
        }
    }

    for(int w = first_size; w < size; w++){
        if(arr[2] > 0){
            arr_bipolar_number[w] = arr[3];
            arr[2]--;
        }
    }

    return array_para_numero(arr_bipolar_number, size);
}

/**
 * Memory allocation for a int matrix with nlines and ncolumns
 * @param nlines - number of lines
 * @param ncolumns - number of columns
 * @return pointer to the allocated memory of the matrix
 */
short** alloc_matrix_int(int nlines, int ncolumns){
    short **p = NULL; //apontador para a matriz icializado em NULL

    p = (short**)malloc(sizeof(short*) * nlines); //alocar memoria para as linhas
    if(p != NULL){ //se nao houve erros na alocaçao

        for(int i = 0; i < nlines; i++){
            *(p + i) = (short *) malloc(sizeof(short) * ncolumns); // alocar memoria para as colunas
            if(*(p + i) == NULL){
                printf("Nao conseguiu alocar a linha %d\n", i);
            }
        }

        for(int lin = 0; lin < nlines; lin++){
            for(int col = 0; col < ncolumns; col++){
                *(*(p + lin) + col) = -1;
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
void store_key_int(short **matrix, int lines, unsigned long long key){
    for (int i = 0; i < lines; i++) {

        if (*(*(matrix + i) + 0) == -1) { //se a primeira posiçao do array (linha) for -1
            short* arrKey = key_long_2_digits_int(key); //colocar a key num array

            for (int j = 0; *(arrKey + j) != -1; j++){
                *(*(matrix + i) + j) = *(arrKey + j); //guardar na matriz a key
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
int exists_key_int(short **matrix, int lines, unsigned long long key){

    short* arrKey = key_long_2_digits_int(key); //colocar a key no array
    int sizeKey = number_digits_iterative(key); //tamanho da key
    int count = 0;

    for (int i = 0; i < lines; i++) {

        for (int j = 0; *(arrKey + j) != -1; j++){
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
unsigned long long get_private_key_int(short **matrix_kpub, short **matrix_kpriv, int lines, unsigned long long pubkey){

    short* arrKpub = key_long_2_digits_int(pubkey);
    int sizeKey = number_digits_iterative(pubkey);
    int count_kpub = 0;

    if(exists_key_int(matrix_kpub, lines, pubkey) == 1){
        for(int i = 0; i < lines; i++){

            for (int j = 0; *(arrKpub + j) != -1; j++){

                if(*(*(matrix_kpub + i) + j) == *(arrKpub + j)){
                    count_kpub++;
                    if(count_kpub == sizeKey){

                        return key_digits_2_long_int(*(matrix_kpriv + i));
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
unsigned long long get_runlength_int(short **matrix_kpriv, short **matrix_kcod, int lines, unsigned long long privkey){

    short* arrKpriv = key_long_2_digits_int(privkey);
    int sizeKey = number_digits_iterative(privkey);
    int count_kpriv = 0;

    if(exists_key_int(matrix_kpriv, lines, privkey) == 1){
        for(int i = 0; i < lines; i++){

            for (int j = 0; *(arrKpriv + j) != -1; j++){

                if(*(*(matrix_kpriv + i) + j) == *(arrKpriv + j)){
                    count_kpriv++;
                    if(count_kpriv == sizeKey){

                        return key_digits_2_long_int(*(matrix_kcod + i));
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
* Delete a given public key (and corresponding priv and runlength keys) from all matrices.
* @param matrix_kpub - public keys matrix
* @param matrix_kpriv - private keys matrix
* @param matrix_kcod - run-lengths matrix
* @param lines - matrix number of lines
* @param pubkey - public key to delete
* @return pubkey that was deleted
*/
unsigned long long delete_key_int(short **matrix_kpub, short **matrix_kpriv, short **matrix_kcod, int lines, short pubkey){

    int index = index_key_int(matrix_kpub, lines, pubkey);
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
void bulk_populate_public_keys_int(short **matrix_kpub, int lines){

    int pubKey = 0;
    long long bipolar = 0;

    for(int i = 0; i < lines; i++) {
        if(*(*(matrix_kpub + i) + 0) == -1){

            do {
                pubKey = new_public_key_int();
                bipolar = calc_private_key_int(pubKey);
            } while (bipolar == -1);
            store_key_int(matrix_kpub, lines, pubKey);
        }
    }
}

/**
 * Automatically calculate, generate and store all private keys for the existing public keys.
 * @param matrix_kpub - public keys matrix
 * @param matrix_kpriv - private keys matrix
 * @param lines - matrix number of lines
 */
void bulk_compute_private_keys_int(short **matrix_kpub, short **matrix_kpriv, int lines){

    int pubKey = 0, privKey = 0;

    for (int i = 0; i < lines; i++) {
        if(*(*(matrix_kpub + i) + 0) != -1){

            pubKey = key_digits_2_long_int(*(matrix_kpub + i));
            privKey = calc_private_key_int(pubKey);
            store_key_int(matrix_kpriv, lines, privKey);
        }
    }
}

/**
 * Automatically calculate and store all run-lengths for the existing private keys.
 * @param matrix_kpriv - private keys matrix
 * @param matrix_kcod - run-lengths matrix
 * @param lines - matrix number of lines
 */
void bulk_compute_runlengths_int(short **matrix_kpriv, short **matrix_kcod, int lines){

    int privKey = 0, kcod = 0;

    for (int i = 0; i < lines; i++) {
        if(*(*(matrix_kpriv + i) + 0) != -1){

            privKey = key_digits_2_long_int(*(matrix_kpriv + i));
            kcod = calc_runlength_int(privKey);
            store_key_int(matrix_kcod, lines, kcod);
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
short** search_private_keys_int(short **matrix_kpub, short **matrix_kpriv, int lines, unsigned long long partialpubkey){

    int size_partialpubkey = number_digits_iterative(partialpubkey);
    short* arr_partialpubkey = key_long_2_digits_int(partialpubkey);
    int size_kpub = 0;
    int priv_key = 0;

    short** all_priv_keys = alloc_matrix_int(lines, 20);

    for(int i = 0; i < lines; i++) {//percorrer a matriz linha a linha

        for(size_kpub = 0; *(*(matrix_kpub + i) + size_kpub) != -1; size_kpub++){//calcular o tamanho da key publica
        }

        if(existsPartial(*(matrix_kpub + i), size_kpub, arr_partialpubkey, size_partialpubkey) == 1){

            priv_key = key_digits_2_long_int(*(matrix_kpriv + i));
            store_key_int(all_priv_keys, lines, priv_key);
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
void sort_matrix_int(short **matrix, int lines, int order){

    int key = 0;
    int* arr_all_keys = calloc(lines, sizeof(int));

    for(int i = 0; i < lines; i++){

        key = key_digits_2_long_int(*(matrix + i));
        arr_all_keys[i] = key;
    }

    if(order == 1){
        sort_array_ascending(lines, arr_all_keys);

        for(int i = 0; i < lines; i++){
            for(int j = 0; *(*(matrix + i) + j) != -1; j++){
                *(*(matrix + i) + j) = -1;
            }
            store_key_int(matrix, lines, arr_all_keys[i]);
        }
    }
    if(order == 0){
        sort_array_descending(lines, arr_all_keys);

        for(int i = 0; i < lines; i++){
            for(int j = 0; *(*(matrix + i) + j) != -1; j++){
                *(*(matrix + i) + j) = -1;
            }
            store_key_int(matrix, lines, arr_all_keys[i]);
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
void sort_all_matrices_int(short **matrix_kpub, short **matrix_kpriv, short **matrix_kcod, int lines, int order){
    sort_matrix_int(matrix_kpub, lines, order);
    sort_matrix_int(matrix_kpriv, lines, order);
    sort_matrix_int(matrix_kcod, lines, order);
}

/**
 * Print all keys on the console, sorted by pubkeys sizes (i.e. number of digits).
 * @param matrix_kpub - public keys matrix
 * @param matrix_kpriv - private keys matrix
 * @param matrix_kcod - run-lengths matrix
 * @param lines - matrix number of lines
 * @param order - order == 0 ? current order : order == 1 ? ascending : descending
 */
void list_keys_int(short **matrix_kpub, short **matrix_kpriv, short **matrix_kcod, int lines, int order){


    if(order != 0){
        sort_matrix_int(matrix_kpub, lines, order);
    }


    printf("Matriz ints keys publicas:\n");
    for(int i = 0; i < lines; i++){
        for(int j = 0; *(*(matrix_kpub + i) + j) != -1; j++){
            printf("%d", *(*(matrix_kpub + i) + j));
        }
        printf("\n");
    }
    printf("\n");

    printf("Matriz ints keys privadas:\n");
    for(int i = 0; i < lines; i++){
        for(int j = 0; *(*(matrix_kpriv + i) + j) != -1; j++){
            printf("%d", *(*(matrix_kpriv + i) + j));
        }
        printf("\n");
    }
    printf("\n");

    printf("Matriz ints keys run-lengths:\n");
    for(int i = 0; i < lines; i++){
        for(int j = 0; *(*(matrix_kcod + i) + j) != -1; j++){
            printf("%d", *(*(matrix_kcod + i) + j));
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
void save_txt_keys_int(short **matrix_kpub, short **matrix_kpriv, short **matrix_kcod, int lines, char filename[]){

    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        fprintf(stderr, "Erro abrir ficheiro: %s\n", filename);
        return;
    }

    for(int i = 0; i < lines; i++){

        fprintf(fp, "Key publica: ");
        for(int j = 0; *(*(matrix_kpub + i) + j) != -1; j++){
            fprintf(fp,"%d", *(*(matrix_kpub + i) + j));
        }
        fprintf(fp, "\n");

        fprintf(fp, "Key privada: ");
        for(int j = 0; *(*(matrix_kpriv + i) + j) != -1; j++){
            fprintf(fp,"%d", *(*(matrix_kpriv + i) + j));
        }
        fprintf(fp, "\n");

        fprintf(fp, "Key run length: ");
        for(int j = 0; *(*(matrix_kcod + i) + j) != -1; j++){
            fprintf(fp,"%d", *(*(matrix_kcod + i) + j));
        }
        fprintf(fp, "\n");
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
void load_txt_keys_int(short **matrix_kpub, short **matrix_kpriv, short **matrix_kcod, int lines, char filename[]) {

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
        store_key_int(matrix_kpub, lines, pubKey);

        fscanf(fp, "Key privada: %d\n", &privKey);
        store_key_int(matrix_kpriv, lines, privKey);

        fscanf(fp, "Key run length: %d\n", &kcodKey);
        store_key_int(matrix_kcod, lines, kcodKey);
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
void save_bin_keys_int(short **matrix_kpub, short **matrix_kpriv, short **matrix_kcod, int lines, char filename[]) {

    FILE *fp = fopen(filename, "wb");
    if (fp == NULL) {
        fprintf(stderr, "Erro abrir ficheiro: %s\n", filename);
        return;
    }

    for(int i = 0; i < lines; i++){

        for(int j = 0; *(*(matrix_kpub + i) + j) != -1; j++){
            fwrite(((matrix_kpub + i) + j), sizeof(short), 1, fp);
        }

        for(int j = 0; *(*(matrix_kpriv + i) + j) != -1; j++){
            fwrite(((matrix_kpriv + i) + j), sizeof(short), 1, fp);
        }

        for(int j = 0; *(*(matrix_kcod + i) + j) != -1; j++){
            fwrite(((matrix_kcod + i) + j), sizeof(short), 1, fp);
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
void load_bin_keys_int(short **matrix_kpub, short **matrix_kpriv, short **matrix_kcod, int lines, char filename[]) {

    int pubKey = 0;
    int privKey = 0;
    int kcodKey = 0;

    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        fprintf(stderr, "Error opening file: %s\n", filename);
        return;
    }

    for(int i = 0; i < lines; i++){

        for(int j = 0; *(*(matrix_kpub + i) + j) != -1; j++){
            fread(&pubKey, sizeof(short), 1, fp);
        }
        store_key_int(matrix_kpub, lines, pubKey);

        for(int j = 0; *(*(matrix_kpriv + i) + j) != -1; j++){
            fread(&privKey, sizeof(short), 1, fp);
        }
        store_key_int(matrix_kpriv, lines, privKey);

        for(int j = 0; *(*(matrix_kcod + i) + j) != -1; j++){
            fread(&kcodKey, sizeof(short), 1, fp);
        }
        store_key_int(matrix_kcod, lines, kcodKey);

    }
    fclose(fp);
}





