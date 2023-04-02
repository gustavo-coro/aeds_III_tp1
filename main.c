#include "main.h"

int main (int argc, char **argv) {

    FILE (*inFile);
    FILE (*outFile);

    if (openFile(argc, argv, &inFile, &outFile) != 1) {
        perror("ERRO!");
        exit(0);
    }
    
    lista* list = readFile(&inFile);
    mergeSort(list, 0, list->tamanho-1);
    maxLinkedPoints(list);
    printf("\n\nmax points: %d\n\n", list->ligacoesMaximas);
    //substituir as linhas do arquivo (usar com o w+)
    fprintf(outFile, "%d", list->ligacoesMaximas);
    //adicionar ao final do arquivo (usar com a)
    //fprintf(outFile, "%d", list->ligacoesMaximas);

    free(list->listaPontos);
    free(list->ancoras);
    free(list);
    fclose(inFile);
    fclose(outFile);

    return 0;
}