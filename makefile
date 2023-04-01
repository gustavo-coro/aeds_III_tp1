all: main

main: main.o calcula_intersecao.o ler_arquivo.o lista.o ordenacao.o ponto.o
	gcc -o main main.o calcula_intersecao.o ler_arquivo.o lista.o ordenacao.o ponto.o

main.o: main.c calcula_intersecao.c ler_arquivo.c lista.c ordenacao.c ponto.c
	gcc -o main.o main.c -c -W -Wall -ansi -pedantic -std=c99

calcula_intersecao.o: calcula_intersecao.c calcula_intersecao.h
	gcc -o calcula_intersecao.o calcula_intersecao.c -c -W -Wall -ansi -pedantic -std=c99

ler_arquivo.o: ler_arquivo.c ler_arquivo.h
	gcc -o ler_arquivo.o ler_arquivo.c -c -W -Wall -ansi -pedantic -std=c99

lista.o: lista.c lista.h
	gcc -o lista.o lista.c -c -W -Wall -ansi -pedantic -std=c99

ordenacao.o: ordenacao.c ordenacao.h
	gcc -o ordenacao.o ordenacao.c -c -W -Wall -ansi -pedantic -std=c99

ponto.o: ponto.c ponto.h
	gcc -o ponto.o ponto.c -c -W -Wall -ansi -pedantic -std=c99

clean:
	rm -rf *.o *~ main