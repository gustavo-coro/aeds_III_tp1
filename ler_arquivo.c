#include <getopt.h>

#include "main.h"

int openFile (int argc, char **argv, FILE **in, FILE **out) {

    int opt;
    while ((opt = getopt(argc, argv, "i:o:")) != -1) {
        switch (opt) {
            case 'i':
                *in = fopen(optarg, "r");
                if (*in == NULL) {
                    perror("Erro ao abrir o arquivo de entrada!");
                    return -1; //erro ao abrir o arquivo;
                }
            break;
            case 'o':
                *out = fopen(optarg, "w+");
                if (*out == NULL) {
                    perror("Erro ao abrir o arquivo de saida!");
                    return -1; //erro ao abrir o arquivo;
                }
            break;
            default:
                perror("Erro nas opcoes de entrada!");
                return -1; //retorna caso a entrada estiver errada
            break;
        }
    }


    return 1; //retorna em caso de sucesso
}

lista *readFile (FILE **inFile) {
    lista *listaPontos;
    char *line = malloc(20);
    //ler a primeira linha com o numero de pontos, e as ancoras
    if (fgets(line, 20, *inFile) != NULL) {
        int size, xA, xB;
        sscanf(line, "%d %d %d", &size, &xA, &xB);
        if (xA > xB) {
            //garantir que a posicao 0 seja sempre maior
            int aux = xA;
            xA = xB;
            xB = aux;
        }
        listaPontos = createList(size, xA, xB);
    }
    //ler as demais linhas com o x e o y de cada ponto
    int cont = 0;
    while (fgets(line, 20, *inFile) != NULL) {
        sscanf(line, "%d %d", &listaPontos->listaPontos[cont].x, 
        &listaPontos->listaPontos[cont].y); 
        cont++;
    }

    free(line);
    return listaPontos;
}