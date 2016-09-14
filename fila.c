#include <stdio.h>
#include <stdlib.h>
#include "fila.h"


link novoNo(int item, link next, link prev) {
  link t = malloc(sizeof *t);
  if (t == NULL) {
    printf ("Erro no malloc \n");
    exit(-1);
  }
  t->item = item;
  t->next = next;
  t->prev = prev;
  return t;
}

FILA novaFila() {
  FILA f = malloc(sizeof *f);
  f->maisNovo = f->maisAntigo = NULL;
  return f;
}

void inserirFim(FILA f, int e) {
  if(f->maisAntigo == NULL && f->maisNovo == NULL) {
    f->maisAntigo = f->maisNovo = novoNo(e, NULL, NULL);
  } else {
    f->maisNovo->next = novoNo(e, NULL, f->maisNovo);
    f->maisNovo = f->maisNovo->next;
  }
}

void inserirInicio(FILA f, int e){
    if(f->maisAntigo == NULL && f->maisNovo == NULL){
        //1o elemento
        f->maisAntigo = f->maisNovo = novoNo(e, NULL, NULL);
    }
    else{
        f->maisAntigo->prev = novoNo(e, f->maisAntigo, NULL);
        f->maisAntigo = f->maisAntigo->prev;
    }
}

int removerInicio(FILA f){
  int x;
  link t;
  if(filaVazia(f)){
    printf ("Erro, a fila esta vazia\n");
    return 0;
  }

  x = f->maisAntigo->item;
  t = f->maisAntigo;
  f->maisAntigo = f->maisAntigo->next;

  if(f->maisAntigo == NULL)
    f->maisNovo = NULL;

  free(t);
  return x;
}

int removerFim(FILA f){
  int x;
  link t;
  if(filaVazia(f)){
    printf("Erro, a fila esta vazia\n");
    return 0;
  }

  x = f->maisNovo->item;
  t = f->maisNovo;
  f->maisNovo = f->maisNovo->prev;

  if(f->maisNovo == NULL){
    f->maisAntigo = NULL;

    free(t);
    return x;
  }
}

int filaVazia(FILA f) {
  return ((f->maisNovo == NULL) || (f->maisAntigo == NULL));
}


void imprimirFilaEsquerdaParaDireita(FILA f) {
  link t;
  printf("---------->\n");
  for(t = f->maisAntigo; t != NULL; t = t->next)
    printf ("%d ", t->item);
  printf ("\n");
}

void imprimirFilaDireitaParaEsquerda(FILA f) {
  link t;
  printf("<----------\n");
  for(t = f->maisNovo; t != NULL; t = t->prev)
    printf ("%d ", t->item);
  printf ("\n");
}


void destroiFila(FILA f) {
  while (!filaVazia(f))
    removerFim(f);
  free(f);
}

