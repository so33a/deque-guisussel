#ifndef FILA_H
#define FILA_H

typedef struct node * link;
struct node {
  int item;
  link next;
  link prev;
};

typedef struct {
  link maisAntigo;
  link maisNovo;
} * FILA;

link novoNo(int item, link next, link prev);
FILA novaFila();
void inserirInicio(FILA f, int e);
void inserirFim(FILA f, int e);
int removerFim(FILA f);
int removerInicio(FILA f);
void imprimirFilaDireitaParaEsquerda(FILA f);
void imprimirFilaEsquerdaParaDireita(FILA f);
void destroiFila(FILA f);
int filaVazia(FILA f);
int removerInicio(FILA f);

#endif
