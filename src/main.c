#include <stdio.h>
#include "term.h"
#include "gerenciarTarefas.h"

void exibir_creditos()
{
  printf("%s%s", TC_BG_GRN, TC_RED);
  term_cls();
  term_move_xy(1, 1);
  printf("CRÉDITOS\n");
  printf("Professor Daniel - IDP\n");
  getchar();
}

void exibirGerenciarTarefas()
{
  gerenciarTarefas();
  getchar();
}

void menu_tarefas()
{
}

void menu_principal()
{
  // term_move_xy(5,8);
  char ch;
  while (1)
  {
    printf("%s%s", TC_BG_WHT, TC_BLK);
    term_cls();
    term_move_xy(1, 1);
    printf("1 - Gerenciar Tarefas\n");
    printf("2 - Creditos\n");
    printf("Q - Sair\n");
    printf("Opção: ");
    ch = getchar();
    if (ch == 'q' || ch == 'Q')
      break;

    switch (ch)
    {
    case '1':
      exibirGerenciarTarefas();
      break;
    case '2':
      // entrar nos créditos
      exibir_creditos();
      break;
      // default: opção ínválida
    }
  }
}

int main()
{

  tc_canon_off();
  menu_principal();

  return 0;

} // main*/
