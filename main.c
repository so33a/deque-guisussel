#include <stdio.h>
#include "fila.h"

int main () {
  FILA alunos = novaFila();
  inserirFim(alunos, 9);
  inserirFim(alunos, 8);
  inserirInicio(alunos, 3);
  inserirInicio(alunos, 10);
  inserirInicio(alunos, 5);
  inserirFim(alunos, 20);

  imprimirFilaEsquerdaParaDireita(alunos);

  printf("\n");

  //imprimirFilaDireitaParaEsquerda(alunos);

  //while(!filaVazia(alunos))
    //printf ("removido: %d \n", removerFim(alunos));

    removerInicio(alunos);
    removerInicio(alunos);

    //removerInicio(alunos);

    //imprimirFilaEsquerdaParaDireita(alunos);



  imprimirFilaEsquerdaParaDireita(alunos);

    inserirInicio(alunos, 99);
    inserirFim(alunos, 100);
    removerFim(alunos);
    imprimirFilaEsquerdaParaDireita(alunos);

  destroiFila(alunos);
  return 0;
}
