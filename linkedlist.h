//
// Created by dinho on 18/04/24.
//

#ifndef DATASTRUCTC_LINKEDLIST_H
#define DATASTRUCTC_LINKEDLIST_H

#include <stdbool.h>

typedef struct {
    char* text;
    unsigned long length;
}String;//Estrutura de texto

typedef struct Node Node;

typedef struct Node{

    int index;

    String element;

    Node* next;
    Node* prev;

}Node;//Elemento da Lista

typedef struct{

    Node* header;//Sentinela head

    Node* tail;//Sentinela tail

    int size;
}LinkedList;

LinkedList* builder();//Retorna uma LinkedList

Node* buildNode(const char* string);//Recebe um array de char e retorna um Node

void removeNode(LinkedList* linkedList, Node* node);//Só precisa saber o Node que será apagado, ja que ele irá saber sua propria posição
void addNodeAfter(LinkedList* linkedList, Node* fromlist, Node* newNode);//Adicionar em uma posição especifica da lista

void addNodeAtFirst(LinkedList* linkedlist,Node* node);//Necessita saber a lista onde vai ser adicionado o dado por primeiro
void addNodeAtLast(LinkedList* linkedlist,Node* node);//Necessita saber a lista onde vai ser adicionado o dado por ultimo
void removeAtFirst(LinkedList* linkedList);//Remove o primeito elemento de uma lista
void RemoveAtLast(LinkedList* linkedList);//remove o ultimo elemento da lista

Node* searchByData(const LinkedList* linkedlist, String string);//Procurar um node pelo conteúdo
Node* searchByIndex(const LinkedList* linkedlist, int index);//Procura um node com base no seu index
Node* getFirst(const LinkedList* linkedlist);//Pega o primeiro elemento
Node* getLast(const LinkedList* linkedlist);//Pega o ultimo elemento

void clearLinkedList(LinkedList* linkedList);//Deleta uma lista

//Funções para testar:
void forEachNode(const LinkedList* linkedList, void (*func)(Node*));//Executa uma função para cada Elemento da lista
LinkedList* findNodesWithCondition(const LinkedList* linkedList, bool (*condition)(const Node*));//Retorna uma Lista de elementos com determinadas caracterisiticas
void sortLinkedList(LinkedList* linkedList, int (*comparator)(const Node*, const Node*));//Organiza a lista com determinado parametro
void sortAscending(LinkedList* linkedList);//organiza de forma Crescente
void sortDescending(LinkedList* linkedList);//organiza de forma decrescente

#endif //DATASTRUCTC_LINKEDLIST_H
