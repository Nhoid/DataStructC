//
// Created by dinho on 19/04/24.
//

#ifndef DATASTRUCTC_STACK_H
#define DATASTRUCTC_STACK_H

#include <stdbool.h>

typedef struct {
    char* text;
    unsigned long length;
}String;//Estrutura de texto

typedef struct Node Node;

typedef struct Node{

    String element;

    Node* next;

}Node;//Elemento da pilha

typedef struct{

    Node* first;//pilha

    int size;
}Stack;

Stack* builder();//Cria uma Stack nova

Node* buildNode(const char* string);//Cria um novo node a partir de um array de char

int size(const Stack* stack);// Retorna o tamanho da Stack

bool isEmpty(const Stack* stack);//Verifica se a Stack está vazia

Node* top(const Stack* stack);//Retorna o primeiro elemento da stack

void push(Stack* stack, Node* node);//Insere um novo elemento no topo da stack

Node pop(Stack* stack);//Remove e retorna o primeiro item da stack

void deleteStack(Stack* stack);//Libera a memoria da stack

#endif //DATASTRUCTC_STACK_H
