#include "main.h"
#include <math.h>

void merge (lista* list, int inicio, int meio, int fim) {
    lista* temp;
    int p1, p2, tamanho, i, j, k;
    int fim1 = 0, fim2 = 0;
    tamanho = fim-inicio+1;
    p1 = inicio;
    p2 = meio+1;

    temp = (lista *) malloc(sizeof(lista));
    temp->listaPontos = (ponto*) malloc(tamanho*sizeof(ponto));
    
    if(temp != NULL){
        for(i=0; i<tamanho; i++){
            if(!fim1 && !fim2){
                if(list->listaPontos[p1].y < list->listaPontos[p2].y){
                    temp->listaPontos[i]=list->listaPontos[p1++];
                } else{
                       temp->listaPontos[i]=list->listaPontos[p2++];
                }
                if(p1>meio){ 
                    fim1=1;
                }
                if(p2>fim){ 
                    fim2=1;
                }         
            } else{
                    if(!fim1){
                    temp->listaPontos[i]=list->listaPontos[p1++];
                }
                else{
                    temp->listaPontos[i]=list->listaPontos[p2++];
                }
            }
        }
        for(j=0, k=inicio; j<tamanho; j++, k++){
            list->listaPontos[k]=temp->listaPontos[j];
        }
    }
    free(temp);
}

void mergeSort (lista* list, int inicio, int fim) {
    int meio;
    if(inicio < fim){
        meio = floor((inicio+fim)/2);
        mergeSort(list,inicio,meio);
        mergeSort(list,meio+1,fim);
        merge(list,inicio,meio,fim);
    }
}