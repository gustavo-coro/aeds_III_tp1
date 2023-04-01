#ifndef LER_ARQUIVO_H
#define LER_ARQUIVO_H

#include "lista.h"

int openFile (int, char**, FILE**, FILE**);
lista* readFile (FILE**);

#endif