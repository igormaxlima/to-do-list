#ifndef TAREFAS_H
#define TAREFAS_H

typedef enum
{
  A_FAZER,
  ANDAMENTO,
  FINALIZADO
} ETarefa;

typedef struct
{
  int id;
  ETarefa status;
  char titulo[500];
} Tarefa;

typedef struct No
{
  Tarefa tarefa;
  struct No *proximo;
  struct No *anterior;
} NoTarefa;

typedef struct
{
  NoTarefa *primeiro;
  NoTarefa *ultimo;
  unsigned int size;
} ListaTarefa;

ListaTarefa lista;

ListaTarefa inicializarLista();
Tarefa inicializarTarefa(int id, ETarefa status, char *titulo);
NoTarefa *criarNo(Tarefa tarefa);

#endif