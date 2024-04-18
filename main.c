//
// Created by dinho on 18/04/24.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedlist.h"

// Função callback para exibir os dados de cada nó.
void printNode(Node* node) {
    printf("Node index: %d, Data: %s\n", node->index, node->element.text);
}

bool containsText(const Node* node){
    return strstr(node->element.text, "data") != NULL;
}

int main() {
    // Criação da lista
    LinkedList* list = builder();
    addNodeAtFirst(list, buildNode("data 3"));
    addNodeAtLast(list, buildNode("data 1"));
    addNodeAtLast(list, buildNode("data 2"));
    addNodeAtLast(list, buildNode("extra data 4"));

    // Testando forEachNode
    printf("Original List:\n");
    forEachNode(list, printNode);

    // Testando findNodesWithCondition
    LinkedList* filteredList = findNodesWithCondition(list, containsText);
    if (filteredList != NULL) {
        printf("\nFiltered List (contains 'data'):\n");
        forEachNode(filteredList, printNode);
    }

    // Testando sortAscending e sortDescending
    printf("\nList Sorted Ascending:\n");
    sortAscending(list);
    forEachNode(list, printNode);

    printf("\nList Sorted Descending:\n");
    sortDescending(list);
    forEachNode(list, printNode);

    // Limpando recursos
    clearLinkedList(list);
    clearLinkedList(filteredList);
    free(list);
    free(filteredList);

    return 0;
}