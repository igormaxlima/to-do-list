#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "tarefas.h"

ListaTarefa lista;

ListaTarefa inicializarLista()
{
  lista.primeiro = NULL;
  lista.ultimo = NULL;
  lista.size = 0;
  return lista;
}

Tarefa inicializarTarefa(int id, ETarefa status, char *titulo)
{
  Tarefa tarefa;
  tarefa.id = id;
  tarefa.status = status;
  strcpy(tarefa.titulo, titulo);
  return tarefa;
}

NoTarefa *criarNo(Tarefa tarefa)
{
  NoTarefa *novo_no = malloc(sizeof(NoTarefa));
  if (novo_no)
  {
    novo_no->anterior = NULL;
    novo_no->proximo = NULL;
    novo_no->tarefa = tarefa;
  }
  return novo_no;
}

void inserirFim(ListaTarefa *lista, NoTarefa *no)
{
  if (!lista->primeiro)
  {
    lista->primeiro = no;
    lista->ultimo = no;
  }
  else
  {
    no->anterior = lista->ultimo;
    lista->ultimo->proximo = no;
    lista->ultimo = no;
  }
}