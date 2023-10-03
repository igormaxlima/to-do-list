#ifndef GERENCIAR_TAREFAS_H
#define GERENCIAR_TAREFAS_H
#include "tarefas.h"

void criarNovaTarefa();
void exibeTarefas(ListaTarefa *lista);
void editarTarefa(ListaTarefa *lista);
void deletarTarefa(ListaTarefa *lista);

void menuGerenciarTarefas();

#endif