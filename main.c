//
// Created by dinho on 18/04/24.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedlist.h"

int main(){
    // Criação da lista
    LinkedList* list = builder();
    if (list == NULL) {
        printf("Erro ao criar a lista.\n");
        return 1;
    }

    // Adicionando nós à lista
    addNodeAtFirst(list, buildNode("Inicio"));
    addNodeAtLast(list, buildNode("Fim"));
    addNodeAfter(list, getFirst(list), buildNode("Meio"));

    // Exibindo os elementos da lista
    Node* current = getFirst(list);
    while (current != list->tail) { // Percorre até a sentinela de cauda
        printf("Nó: %d, %s\n", current->index ,current->element.text);
        current = current->next;
    }

    // Buscando um nó por dados
    String searchString = {"Meio", 4}; // A estrutura String deve ser definida de acordo
    Node* found = searchByData(list, searchString);
    if (found != NULL) {
        printf("Nó encontrado com dados: %s\n", found->element.text);
    } else {
        printf("Nó com dados '%s' não encontrado.\n", searchString.text);
    }

    // Buscando um nó por índice
    int searchIndex = 1; // Assume que o índice é atualizado corretamente ao adicionar nós
    found = searchByIndex(list, searchIndex);
    if (found != NULL) {
        printf("Nó encontrado com índice %d: %s\n", searchIndex, found->element.text);
    } else {
        printf("Nó com índice %d não encontrado.\n", searchIndex);
    }

    // Removendo elementos
    removeAtFirst(list);
    removeAtFirst(list); // Deve remover "Meio" agora que "Inicio" já foi removido
    printf("Após remoções, primeiro elemento: %s\n", getFirst(list)->element.text);

    // Limpando a lista
    clearLinkedList(list);

    return 0;
}