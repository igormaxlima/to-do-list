#ifndef GERENCIAR_TAREFAS_H
#define GERENCIAR_TAREFAS_H

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

ListaTarefa inicializarLista();
void criarNovaTarefa();
NoTarefa *criarNo(Tarefa tarefa);
Tarefa inicializarTarefa(int id, ETarefa status, char *titulo);
void exibeTarefas(ListaTarefa lista);
void menuGerenciarTarefas();
void inserirFim(ListaTarefa lista, Tarefa tarefa);

#endif