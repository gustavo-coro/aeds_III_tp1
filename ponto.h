#ifndef PONTO_H
#define PONTO_H

typedef struct ponto {
    int x;
    int y;
    int pontosDentro;
} ponto;

double findSlope (int, int, int, int);
int isInside (int, int, int, int, int, int);

#endif