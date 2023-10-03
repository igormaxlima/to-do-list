#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "gerenciarTarefas.h"
#include "term.h"
#include "tarefas.h"

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


    Tarefa tarefa = inicializarTarefa(lista->size, titulo);

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

void editarTarefa(ListaTarefa *lista)
{
  if (!lista->primeiro)
  {
    term_cls();
    term_move_xy(1, 1);
    printf("Não tem como editar nenhuma tarefa, sua lista está vazia.\n");
    sleep(2);
    return;
  }
  else
  {
    char ch;
    while (1)
    {
      printf("%s%s", TC_BG_WHT, TC_BLK);
      term_cls();
      term_move_xy(1, 1);
      printf("\nQual destas tarefas você deseja editar:\n");
      exibirLista(lista);
      printf("Q - Sair\n");
      printf("->");
      tc_canon_on();
      
      // Recebe como parâmetro a lista e edita pelo id, resgatado internamente.

      int idEditar;
      scanf("%d", &idEditar);
      tc_canon_off();
      printf("Opção: ");
      ch = getchar();
      if (ch == 'q' || ch == 'Q')
        break;
      NoTarefa *aux = lista->primeiro;
      while (aux && idEditar != aux->tarefa.id)
      {
        aux = aux->proximo;
      }

      if (!aux)
      {
        term_cls();
        term_move_xy(1, 1);
        printf("Essa Tarefa nao Existe!\n");
        sleep(2);
      }
      else
      {
        printf("%s%s", TC_BG_WHT, TC_BLK);
        term_cls();
        term_move_xy(1, 1);
        printf("O que você deseja editar nessa tarefa:\n");
        printf("1. Titulo\n");
        printf("2. Status\n");
        printf("-> ");
        ch = getchar();
        switch (ch)
        {
        case '1':
          printf("%s%s", TC_BG_WHT, TC_BLK);
          term_cls();
          term_move_xy(1, 1);
          printf("Insira o novo titulo:\n");
          printf("-> ");
          tc_canon_on();
          char titulo[500];
          scanf(" %[^\n]%*c", titulo);
          tc_canon_off();
          strcpy(aux->tarefa.titulo, titulo);
          break;
        case '2':
          printf("%s%s", TC_BG_WHT, TC_BLK);
          term_cls();
          term_move_xy(1, 1);
          printf("Deseja modificar para qual status:\n");
          if (aux->tarefa.status == A_FAZER)
          {
            printf("1. Em andamento\n");
            printf("2. Finalizada\n");
            printf("-> ");
            char ch;
            ch = getchar();
            switch (ch)
            {
            case '1':
              aux->tarefa.status = ANDAMENTO;
              break;
            case '2':
              aux->tarefa.status = FINALIZADO;
              break;
            default:
              printf("\nStatus nao existente\n");
              sleep(1);
              return;
            }
          }
          else if (aux->tarefa.status == ANDAMENTO)
          {
            printf("1. A Fazer\n");
            printf("2. Finalizada\n");
            printf("-> ");
            char ch;
            ch = getchar();
            switch (ch)
            {
            case '1':
              aux->tarefa.status = A_FAZER;
              break;
            case '2':
              aux->tarefa.status = FINALIZADO;
              break;
            default:
              printf("\nStatus nao existente\n");
              sleep(1);
              return;
            }
          }
          else if (aux->tarefa.status == FINALIZADO)
          {
            printf("1. A Fazer\n");
            printf("2. Em Andamento\n");
            printf("-> ");
            char ch;
            ch = getchar();
            switch (ch)
            {
            case '1':
              aux->tarefa.status = A_FAZER;
              break;
            case '2':
              aux->tarefa.status = ANDAMENTO;
              break;
            default:
              printf("\nStatus nao existente\n");
              sleep(1);
              return;
            }
          } else {
            printf("1. A Fazer\n");
            printf("2. Em Andamento\n");
            printf("3. Finalizada\n");
            printf("-> ");
            char ch;
            ch = getchar();
            switch (ch)
            {
            case '1':
              aux->tarefa.status = A_FAZER;
              break;
            case '2':
              aux->tarefa.status = ANDAMENTO;
              break;
            case '3': 
              aux->tarefa.status = FINALIZADO;
              break;  
            default:
              printf("\nStatus nao existente\n");
              sleep(1);
              return;
            }
           }
          break;
        default:
          printf("\nOpção não existente!\n");
          sleep(1);
          return;
        }
        if (aux)
        {
          term_cls();
          term_move_xy(1, 1);
          printf("Edição Realizada com Sucesso!\n");
          sleep(1);
          return;
        }
      }
    }
  }
}

void deletarTarefa(ListaTarefa *lista)
{
  if (!lista->primeiro)
  {
    term_cls();
    term_move_xy(1, 1);
    printf("Não tem como deletar uma tarefa, sua lista está vazia.\n");
    sleep(2);
    return;
  }
  else
  {
    char ch;
    while (1)
    {
      printf("%s%s", TC_BG_WHT, TC_BLK);
      term_cls();
      term_move_xy(1, 1);
      printf("Qual destas tarefas você deseja deletar:\n");
      exibirLista(lista);
      printf("Q - Sair\n");
      printf("->");
      tc_canon_on();
      int idDeletar;
      scanf("%d", &idDeletar);
      tc_canon_off();
      printf("Opção: ");
      ch = getchar();
      if (ch == 'q' || ch == 'Q')
        break;
      NoTarefa *aux = lista->primeiro;
      while (aux && idDeletar != aux->tarefa.id)
      {
        aux = aux->proximo;
      }

      if (!aux)
      {
        term_cls();
        term_move_xy(1, 1);
        printf("Essa Tarefa nao Existe!\n");
        sleep(2);
      }
      else if (aux == lista->primeiro)
      {
        lista->primeiro = aux->proximo;
        free(aux);
        lista->size--;
        NoTarefa *atual = lista->primeiro;
        while (atual)
        {
          atual->tarefa.id--;
          atual = atual->proximo;
        }
      }
      else if (aux == lista->ultimo)
      {
        aux->anterior->proximo = NULL;
        lista->ultimo = aux->anterior;
        free(aux);
        lista->size--;
      }
      else
      {
        NoTarefa *atual = aux->proximo;
        aux->anterior->proximo = aux->proximo;
        aux->proximo->anterior = aux->anterior;
        free(aux);
        lista->size--;
        while (atual)
        {
          atual->tarefa.id--;
          atual = atual->proximo;
        }
      }

      if (aux)
      {
        term_cls();
        term_move_xy(1, 1);
        printf("Tarefa Deletada com Sucesso!\n");
        sleep(1);
        return;
      }
    }
  }
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
/*       salvarProjeto(&lista, "tarefas.txt"); */
      break;

    switch (ch)
    {
    case '1':
      criarNovaTarefa(&lista);
      break;
    case '2':
      editarTarefa(&lista);
      break;
    case '3':
      deletarTarefa(&lista);
      break;
      // default: opção ínválida
    }
    
  }
  salvarProjeto(&lista, "tarefas.txt");
}

