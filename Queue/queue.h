//
// Created by Dinho on 5/31/2024.
//

#ifndef GIT_QUEUE_H
#define GIT_QUEUE_H

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

    Node* last;//pilha

    Node* first;

    int size;
}Queue;

Queue* builder(); //retorna uma nova queue

Node* buildNode(const char* string);//retorna um novo node

void enqueue(Queue* queue ,Node* node);// adiciona o elemento no fim da queue

Node* dequeue(Queue* queue);//remove e retorna o primeiro elemento da fila

int size(const Queue* queue);//retorna o tamanho da fila

bool isEmpty(const Queue* queue);//retorna se a fila está vazia ou não

Node* front(const Queue* queue);//retorna, mas não remove, o primeiro elemento

void deleteQueue(Queue* queue);//libera a memoria da queue por completo

#endif //GIT_QUEUE_H
