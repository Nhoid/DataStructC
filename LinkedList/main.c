//
// Created by dinho on 18/04/24.
//
#include <stdio.h>
#include <string.h>
#include "linkedlist.h"

bool containsText(const Node* node) {
    return strstr(node->element.text, "") != NULL;  // Exemplo: procura por "data" no texto.
}

int main() {
    // Criação da lista
    LinkedList* list = builder();

    addNodeAtFirst(list, buildNode("Gabriela"));
    addNodeAtFirst(list, buildNode("Geraldo"));
    addNodeAtLast(list, buildNode("Marcos"));
    addNodeAtLast(list, buildNode("Maria"));

    LinkedList* newOne = findNodesWithCondition(list, containsText);
    printf("Original: \n");
    forEachNode(newOne, printNode);

    sortAscending(newOne);
    printf("Order: \n");
    forEachNode(newOne, printNode);

    sortDescending(newOne);
    printf("Reverse: \n");
    forEachNode(newOne, printNode);

    // Limpando recursos
    clearLinkedList(list);
    clearLinkedList(newOne);

    return 0;
}