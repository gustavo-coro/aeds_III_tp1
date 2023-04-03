#include "main.h"
#include <sys/time.h>
#include <sys/resource.h>

void timeval_subtract(struct timeval *result, struct timeval *x, struct timeval *y) {
    if (x->tv_usec < y->tv_usec) {
        int borrow = (y->tv_usec - x->tv_usec) / 1000000 + 1;
        y->tv_usec -= 1000000 * borrow;
        y->tv_sec += borrow;
    }
    if (x->tv_usec - y->tv_usec > 1000000) {
        int carry = (x->tv_usec - y->tv_usec) / 1000000;
        y->tv_usec += 1000000 * carry;
        y->tv_sec -= carry;
    }
    result->tv_sec = x->tv_sec - y->tv_sec;
    result->tv_usec = x->tv_usec - y->tv_usec;
}

int main (int argc, char **argv) {

    struct rusage usage_start, usage_end;
    struct timeval time_start, time_end, time_diff;

    getrusage(RUSAGE_SELF, &usage_start);
    gettimeofday(&time_start, NULL);

    FILE (*inFile);
    FILE (*outFile);
    if (openFile(argc, argv, &inFile, &outFile) != 1) {
        perror("ERRO!");
        exit(0);
    }

    lista* list = readFile(&inFile);
    mergeSort(list, 0, list->tamanho-1);
    maxLinkedPoints(list);

    getrusage(RUSAGE_SELF, &usage_end);
    gettimeofday(&time_end, NULL);

    timeval_subtract(&time_end, &time_start, &time_diff);
    double user_time = (double) (usage_end.ru_utime.tv_sec - usage_start.ru_utime.tv_sec) +
    (double) (usage_end.ru_utime.tv_usec - usage_start.ru_utime.tv_usec) / 1000000.0;
    double sys_time = (double) (usage_end.ru_stime.tv_sec - usage_start.ru_stime.tv_sec) +
    (double) (usage_end.ru_stime.tv_usec - usage_start.ru_stime.tv_usec) / 1000000.0;
    double in_out_time = (double) (time_diff.tv_sec) + (double) (time_diff.tv_usec) / 1000000.0;

    /*printf("Computing time: %f seconds\n", user_time + sys_time);
    printf("in and out time: %f seconds\n", in_out_time);
    printf("User time: %f seconds\n", user_time);
    printf("System time: %f seconds\n", sys_time);*/

    //printf("max points: %d and entry number: %d\n", list->ligacoesMaximas, list->tamanho);
    //substituir as linhas do arquivo (usar com o w+)
    //fprintf(outFile, "%d", list->ligacoesMaximas);
    //adicionar ao final do arquivo (usar com a)
    fprintf(outFile, "%d;%d;%f;%f;%f;%f\n", list->ligacoesMaximas, list->tamanho, 
        user_time + sys_time, in_out_time, user_time, sys_time);

    free(list->listaPontos);
    free(list->ancoras);
    free(list);
    fclose(inFile);
    fclose(outFile);

    return 0;
}