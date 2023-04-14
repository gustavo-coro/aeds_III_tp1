#include "main.h"
#include <sys/time.h>
#include <sys/resource.h>

void timeval_subtract (struct timeval *result, struct timeval *x, struct timeval *y) {
  /* Perform the carry for the later subtraction by updating y. */
  if (x->tv_usec < y->tv_usec) {
    int nsec = (y->tv_usec - x->tv_usec) / 1000000 + 1;
    y->tv_usec -= 1000000 * nsec;
    y->tv_sec += nsec;
  }
  if (x->tv_usec - y->tv_usec > 1000000) {
    int nsec = (x->tv_usec - y->tv_usec) / 1000000;
    y->tv_usec += 1000000 * nsec;
    y->tv_sec -= nsec;
  }

  /* Compute the time remaining to wait.
     tv_usec is certainly positive. */
  result->tv_sec = x->tv_sec - y->tv_sec;
  result->tv_usec = x->tv_usec - y->tv_usec;
}

int main (int argc, char **argv) {

    struct timeval tempoInicio, tempoFim, tempoDiferenca;
    struct rusage usage;

    gettimeofday(&tempoInicio, NULL);

    FILE (*inFile);
    FILE (*outFile);
    if (openFile(argc, argv, &inFile, &outFile) != 1) {
        perror("ERRO!");
        exit(0);
    }

    lista* list = readFile(&inFile);
    mergeSort(list, 0, list->tamanho-1);
    maxLinkedPoints(list);

    getrusage(RUSAGE_SELF, &usage);
    gettimeofday(&tempoFim, NULL);

    timeval_subtract(&tempoDiferenca, &tempoFim, &tempoInicio);

    double tempoUsuario = (double) usage.ru_utime.tv_sec * 1000000 + usage.ru_utime.tv_usec;
    double tempoSistema = (double) usage.ru_stime.tv_sec * 1000000 + usage.ru_stime.tv_usec;
    double tempoEntradaSaida = (double) ((tempoDiferenca.tv_sec * 1000000) + tempoDiferenca.tv_usec);
    double tempoTotal = tempoUsuario + tempoSistema;

    /*printf("Computing time: %f seconds\n", user_time + sys_time);
    printf("in and out time: %f seconds\n", in_out_time);
    printf("User time: %f seconds\n", user_time);
    printf("System time: %f seconds\n", sys_time);*/

    //printf("max points: %d and entry number: %d\n", list->ligacoesMaximas, list->tamanho);
    //substituir as linhas do arquivo (usar com o w+)
    //fprintf(outFile, "%d", list->ligacoesMaximas);
    //adicionar ao final do arquivo (usar com a)
    fprintf(outFile, "%d;%d;%.2f;%.2f;%.2f;%.2f\n", list->ligacoesMaximas, list->tamanho, 
        tempoTotal, tempoEntradaSaida, tempoUsuario, tempoSistema);

    free(list->listaPontos);
    free(list->ancoras);
    free(list);
    fclose(inFile);
    fclose(outFile);

    return 0;
}