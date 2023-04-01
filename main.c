#include "main.h"

int main (int argc, char **argv) {

    FILE (*inFile);
    FILE (*outFile);

    if (openFile(argc, argv, &inFile, &outFile) != 1) {
        perror("ERRO!");
        exit(0);
    }
    
    lista* list = readFile(&inFile);
    printList(list);
    mergeSort(list, 0, list->tamanho-1);
    printList(list);
}