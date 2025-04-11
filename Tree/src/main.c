#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

// Função comparadora para inteiros
int compareInts(void* a, void* b) {
    int* n1 = (int*)a;
    int* n2 = (int*)b;
    
    if (*n1 > *n2) return 1;
    if (*n1 < *n2) return -1;
    return 0;
}

// Função para liberar nós
void freeNodeInt(Node* node) {
    if (node) {
        free(node->element);
        free(node);
    }
}

// Função auxiliar para criar um novo nó
Node* createNode(void* value) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->element = value;
    node->left = NULL;
    node->right = NULL;
    
    return node;
}

// Função para imprimir a árvore em ordem
void print(Node* node) {
    if (node != NULL) {
        printf("%d ", *(int*)node->element);
    }
}

int main() {
    // Criar árvore
    Tree* tree = buildTree(compareInts, createNode, freeNodeInt);
    
    printf("Inserindo elementos: 5, 3, 7, 2, 4, 6, 8\n");
    
    // Inserir elementos
    int valores[] = {5, 3, 7, 2, 4, 6, 8};
    for(int i = 0; i < 7; i++) {
        int* valor = (int*)malloc(sizeof(int));
        *valor = valores[i];
        insertElement(tree, valor);
    }
    
    printf("Arvore em ordem: ");
    traversalTreePreOrder(tree, print);
    printf("\nTamanho da arvore: %d\n\n", tree->size);
    
    // Testar remoção de nó folha
    printf("Removendo no folha (4)...\n");
    int valorRemover = 4;
    printf("Resultado: %d\n", removeElement(tree, &valorRemover));
    
    printf("Arvore em ordem: ");
    traversalTreePreOrder(tree, print);
    printf("\nTamanho da arvore: %d\n\n", tree->size);
    
    // Testar remoção de nó com um filho
    printf("Removendo no com dois filhos (7)...\n");
    valorRemover = 7;
    printf("Resultado: %d\n", removeElement(tree, &valorRemover));

    printf("Arvore em ordem: ");
    traversalTreePreOrder(tree, print);
    printf("\nTamanho da arvore: %d\n\n", tree->size);
    
    // Testar remoção da raiz
    printf("Removendo a raiz (5)...\n");
    valorRemover = 5;
    printf("Resultado: %d\n", removeElement(tree, &valorRemover));
    
    printf("Arvore em ordem: ");
    traversalTreePreOrder(tree, print);
    printf("\nTamanho da arvore: %d\n\n", tree->size);
    
    // Limpar a árvore (você precisará implementar uma função para isso)
    // TODO: implementar freeTree(tree);
    
    free(tree);
    return 0;
}