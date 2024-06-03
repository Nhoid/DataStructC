//
// Created by Dinho on 5/31/2024.
//

#include "queue.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

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

//Retorna uma Fila
Queue* builder(){
    //Aloca espaço inicial
    Queue* queue = (Queue*) malloc(sizeof(Queue));

    queue->first = NULL;
    queue->last = NULL;

    //Define o tamanho como 0
    queue->size = 0;

    return queue;
}

//retorna o tamanho da fila
int size(const Queue* queue){

    return queue->size;
}

//Verifica se tem algum elemento na fila
bool isEmpty(const Queue* queue){

    return size(queue) == 0;
}

//Adiciona elemento na fila
void enqueue(Queue* queue, Node* node){
    //Verifica se tem algum elemento
    if(isEmpty(queue)){
        //Se não tiver ele atribui o primeiro e ultimo
        queue->first = queue->last = node;
    }else{
        //se tiver, ele o elemento para o fim de fila
        queue->last->next = node;
        queue->last = node;
    }
    //aumenta o tamanho da fila
    queue->size++;
}

//Retorna, mas não apaga, o primeiro elemento 
Node* front(const Queue* queue){
    return queue->first;;
}

//Remove e retorna o primeiro elemento
Node* dequeue(Queue* queue){

    if(isEmpty(queue)) return NULL;

    //Pega referencia do primeiro
    Node* toDelete = queue->first;
   
   //Pega uma copia dos dados do primeiro
    Node* node = buildNode(toDelete->element.text);

    //Pega a referencia do segundo
    queue->first = queue->first->next;

    //Apaga da memoria
    Delete(toDelete);

    //diminui o tamanho da fila
    queue->size--;

    return node;
}

//Apaga uma queue da memoria
void deleteQueue(Queue* queue){
    //Delete todos os elementos, caso tenha
    while(!isEmpty(queue)){
        dequeue(queue);
    }

    free(queue);
}



