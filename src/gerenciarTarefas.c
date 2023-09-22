#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "gerenciarTarefas.h"
#include "term.h"

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

void criarNovaTarefa(ListaTarefa *lista)
{
  lista->size++;
  printf("%s%s", TC_BG_WHT, TC_BLK);
  term_cls();
  term_move_xy(1, 1);
  printf("Digite o titulo: \n");
  tc_canon_on();
  char titulo[500];
  scanf(" %[^\n]%*c", titulo);
  tc_canon_off();

  char ch;
  while (1)
  {

    printf("Qual status da sua tarefa?\n");
    printf("0 - A fazer\n");
    printf("1 - Em andamento\n");
    printf("2 - Finalizada\n");
    printf("q = Sair.\n");
    ch = getchar();

    if (ch == 'q' || ch == 'Q')
      return;
    ETarefa status = -1;
    switch (ch)
    {
    case '0':
      status = A_FAZER;
      break;
    case '1':
      status = ANDAMENTO;
      break;
    case '2':
      status = FINALIZADO;
      break;
      // default: opção ínválida
    }
    Tarefa tarefa = inicializarTarefa(lista->size, status, titulo);

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
    break;
  }
}

void exibirLista(ListaTarefa *lista)
{
  if (!lista)
  {
    fprintf(stderr, "Lista Inválida!\n");
    return;
  }

  if (!lista->primeiro)
  {
    printf("Nenhuma Tarefa Anexada!\n");
  }
  else
  {
    NoTarefa *aux = lista->primeiro;
    while (aux)
    {
      printf("%d. %s - ", aux->tarefa.id, aux->tarefa.titulo);
      char status;
      switch (aux->tarefa.status)
      {
      case A_FAZER:
        printf("A Fazer\n");
        break;
      case ANDAMENTO:
        printf("Em andamento\n");
        break;
      case FINALIZADO:
        printf("Finalizada\n");
        break;
      default:
        printf("Desconhecido\n");
        break;
      }
      aux = aux->proximo;
    }
  }
  printf("\n");
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

void menuGerenciarTarefas()
{
  char ch;
  while (1)
  {
    printf("%s%s", TC_BG_WHT, TC_BLK);
    term_cls();
    term_move_xy(1, 1);
    printf("TAREFAS:\n");
    exibirLista(&lista);
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
      criarNovaTarefa(&lista);
      break;
    case '2':
      // Editar tarefa
      break;
    case '3':
      // Deletar tarefa
      break;
      // default: opção ínválida
    }
  }
}

void inserirFim(ListaTarefa lista, Tarefa tarefa)
{
  return;
}
