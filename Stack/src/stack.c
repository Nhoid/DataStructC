//
// Created by dinho on 19/04/24.
//

#include <stdlib.h>
#include <string.h>
#include "stack.h"

//CONSTROI UM NODE
Node* buildNode(const char* string){
    //COMEÇA ALOCANDO NOVA MEMORIA
    Node* node = (Node*) malloc(sizeof(Node));

    //COPIA OS DADOS DA STRING PASSADA
    node->element.text = strdup(string);
    node->element.length = strlen(string);

    //DEFINE OS SEGUINTES E OS ANTERIORES COMO NULL
    node->next = NULL;

    //RETORNA O NODE CRIADO
    return node;
}

//Cria uma Stack nova
Stack* builder(){
    //Aloca memoria para uma Stack
    Stack* stack = (Stack*) malloc(sizeof(Stack));

    //Define o tamanho em 0
    stack->size = 0;

    //Retorna a stack
    return stack;
}

//Retorna o tamanho da stack
int size(const Stack* stack){
    return stack->size;
}

//Verifica se a stack está vazia
bool isEmpty(const Stack* stack){
    return size(stack) == 0;
}

//Retorna o primeiro item da stack
Node* top(const Stack* stack){
    return stack->first;
}

//Insere um novo elemento na stack
void push(Stack* stack, Node* node){

    //Faz o node apontar para o primeiro da stack
    node->next = top(stack);

    //faz a stack apontar para o node
    stack->first = node;

    //aumenta o tamanho da stack
    stack->size++;

}

//DELETA UMA STRING
void DeleteString(String* string){
    //VERIFICA SE A STRING CONTÉM ALGO, CASO CONTENHA ELE APAGA
    if(string->text != NULL) free(string-> text);
    //DEFINE A STRING COMO NULL
    string->text = NULL;
}

//APAGA UM NODE
void Delete(Node* node){
    //COMEÇA APAGANDO SUAS REFERENCIAS DE PROXIMO E ANTERIOR
    node->next = NULL;

    //APAGA A STRING
    DeleteString(&node->element);

    //APAGA O NODE
    free(node);
}

//Remove e retorna o primeiro elemento da stack
Node pop(Stack* stack){

    Node node;

    if(isEmpty(stack)) return node;

    //Faz uma copia do primeiro elemento da stack

    node.element.text = strdup( top(stack)->element.text );
    node.element.length = top(stack)->element.length;

    //Faz o primeiro elemento ser o segundo
    stack->first = stack->first->next;

    stack->size--;

    //retorna a copia
    return node;
}

//Deleta uma Stack
void deleteStack(Stack* stack){
    //Apaga todos elementos da stack, caso tenha
    while(!isEmpty(stack)){
        pop(stack);
    }

    free(stack);
}

//Inverte um Array de String
void reverseArray(String* array, int size){
    Stack* stack = builder();

    for (int i = 0; i < size; i++) {
        Node* node = buildNode(array[i].text);
        push(stack, node);
    }

    for (int i = 0; i < size; i++) {
        array[i] = pop(stack).element;
    }

    deleteStack(stack);
}

