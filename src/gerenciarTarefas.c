#include <stdio.h>
#include <stdlib.h>
#include "gerenciarTarefas.h"
#include "term.h"

ListaTarefa lista;

void menuGerenciarTarefas()
{
  char ch;
  while (1)
  {
    printf("%s%s", TC_BG_WHT, TC_BLK);
    term_cls();
    term_move_xy(1, 1);
    printf("TAREFAS:\n");
    printf("1 - Criar nova tarefa\n");
    printf("2 - Editar tarefa\n");
    printf("3 - Deletar tarefa\n");
    printf("Q - Sair\n");
    printf("Opção: ");
    ch = getchar();
    if (ch == 'q' || ch == 'Q')
      break;

    switch (ch)
    {
    case '1':
      // Criar nova tarefa
      break;
    case '2':
      // Editar tarefa
    case '3':
      // Deletar tarefa

      break;
      // default: opção ínválida
    }
  }
  return;
}

void inserirFim(ListaTarefa lista, Tarefa tarefa)
{
  return;
}
