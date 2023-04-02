#include "main.h"

void maxLinkedPoints (lista* list) {
    //list->listaPontos[0].pontosDentro = 1;
    for (int i = 1; i < list->tamanho; i++) {
        for (int j = (i-1); j >= 0; j--) {
            //verificando se os pontos "abaixo" de [i] estao dentro dele
            if (isInside(list->ancoras[0].x, list->ancoras[1].x,
             list->listaPontos[i].x, list->listaPontos[i].y, 
             list->listaPontos[j].x, list->listaPontos[j].y) == 1) {
                //verificando quantos pontos existem dentro de [j]
                if (list->listaPontos[i].pontosDentro <= list->listaPontos[j].pontosDentro) {
                    list->listaPontos[i].pontosDentro = list->listaPontos[j].pontosDentro + 1;
                }
             }
        }
        if (list->listaPontos[i].pontosDentro > list->ligacoesMaximas) {
            list->ligacoesMaximas = list->listaPontos[i].pontosDentro;
        }
    }
    /*o numero de ligacoes maximas e o numero do maior conjunto de pontos
     dentro de outros pontos mais o proprio ponto*/
    list->ligacoesMaximas++;
}