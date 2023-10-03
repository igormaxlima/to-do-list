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

Tarefa inicializarTarefa(int id, char *titulo)
{
  Tarefa tarefa;
  tarefa.id = id;
  tarefa.status = A_FAZER;
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
void carregarTarefas(ListaTarefa *lista, char *arquivo){
  FILE *fp = fopen(arquivo, "r");
  if (!arquivo)
  {
    fprintf(stderr, "Erro ao abrir arquivo!\n");
    return;
  }
  char linha[500];
  while (fgets(linha, 500, fp))
  {
    char *token = strtok(linha, ";");
    int id = atoi(token);
    token = strtok(NULL, ";");
    char *titulo = token;
    token = strtok(NULL, ";");
    char *status = token;
    Tarefa tarefa = inicializarTarefa(id, titulo);
    if (strcmp(status, "A_FAZER") == 0)
    {
      tarefa.status = A_FAZER;
    }
    else if (strcmp(status, "ANDAMENTO") == 0)
    {
      tarefa.status = ANDAMENTO;
    }
    else if (strcmp(status, "FINALIZADO") == 0)
    {
      tarefa.status = FINALIZADO;
    }
    NoTarefa *novo_no = criarNo(tarefa);
    if (!novo_no)
    {
      fprintf(stderr, "Error ao Criar Tarefa!\n");
      return;
    }
    if (!lista->primeiro)
    {
      lista->primeiro = novo_no;
      lista->ultimo = novo_no;
    }
    else
    {
      novo_no->anterior = lista->ultimo;
      lista->ultimo->proximo = novo_no;
      lista->ultimo = novo_no;
    }
  }
}
void salvarProjeto(ListaTarefa *lista, char *arquivo){

  FILE *fp = fopen(arquivo, "w");
  if (!arquivo)
  {
    fprintf(stderr, "Erro ao abrir arquivo!\n");
    return;
  }
  NoTarefa *no = lista->primeiro;
  while (no)
  {
    fprintf(fp, "%d;%s;%d;\n", no->tarefa.id, no->tarefa.titulo, no->tarefa.status);
    no = no->proximo;
  }
  fclose(fp);
}