#ifndef LISTA_H
#define LISTA_H

typedef struct lista {
    ponto* listaPontos;
    int tamanho;
    ponto* ancoras;
    int ligacoesMaximas;
} lista;

lista* createList (int, int, int);
void printList (lista*);

#endif