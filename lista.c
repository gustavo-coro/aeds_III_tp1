#include "main.h"

lista* createList (int size, int xA, int xB) {
    lista* list = (lista*) malloc(sizeof(lista));
    list->ancoras = (ponto*) malloc(sizeof(ponto)*2);
    list->ancoras[0].x = xA;
    list->ancoras[0].y = 0;
    list->ancoras[1].x = xB;
    list->ancoras[1].y = 0;
    list->tamanho = size;
    list->listaPontos = (ponto*) malloc(sizeof(ponto)*size);
    return list;
}

void printList (lista* list) {
    for (int i = 0; i < list->tamanho; i++) {
        printf("%d %d\n", list->listaPontos[i].x, list->listaPontos[i].y);
    }
}