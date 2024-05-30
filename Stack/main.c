//
// Created by dinho on 19/04/24.
//

#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int main() {
    // Construindo uma pilha
    Stack* stack = builder();

    // Inserindo elementos na pilha
    printf("Adicionando elementos na pilha:\n");
    push(stack, buildNode("primeiro"));
    printf("Adicionado: primeiro\n");
    push(stack, buildNode("segundo"));
    printf("Adicionado: segundo\n");
    push(stack, buildNode("terceiro"));
    printf("Adicionado: terceiro\n");

    // Verificando o tamanho da pilha e se está vazia
    printf("\nTamanho da pilha: %d\n", size(stack));
    printf("A pilha está vazia? %s\n", isEmpty(stack) ? "Sim" : "Não");

    // Acessando o elemento do topo da pilha e imprimindo
    Node* topElement = top(stack);
    if (topElement != NULL) {
        printf("Elemento do topo: %s\n", topElement->element.text);
    } else {
        printf("A pilha está vazia.\n");
    }

    // Removendo elementos da pilha e imprimindo
    printf("\nRemovendo elementos da pilha:\n");
    while (!isEmpty(stack)) {
        Node popped = pop(stack);
        printf("Elemento removido: %s\n", popped.element.text);
    }

    // Verificando novamente se a pilha está vazia
    printf("\nA pilha está vazia? %s\n", isEmpty(stack) ? "Sim" : "Não");

    // Liberando a memória alocada para a pilha
    deleteStack(stack);

    return 0;
}