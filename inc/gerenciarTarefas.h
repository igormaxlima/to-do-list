#ifndef GERENCIAR_TAREFAS_H
#define GERENCIAR_TAREFAS_H
#include "tarefas.h"

void criarNovaTarefa();
void exibeTarefas(ListaTarefa *lista);
void editarTarefa(ListaTarefa *lista);
void deletarTarefa(ListaTarefa *lista);
void salvarTarefas(char *nomeArquivo);
void carregarTarefas(ListaTarefa *lista, char *nomeArquivo);
void menuGerenciarTarefas();

#endif