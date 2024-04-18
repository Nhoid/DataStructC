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

    Node* pointer;

    int size;
}LinkedList;

LinkedList* builder();//Retorna uma LinkedList

bool advance(Node* pointer);//Faz o ponteiro avançar, retorna true se ele avançou, retorna false se ja estiver no ultimo elemento, anterior ao sentinela
bool goBack(Node* pointer);//Faz o ponteiro voltar, retorna true se ele retornou, retorna false se ja estiver no primeiro elemento, depois do sentinela
void targetByData(LinkedList* linkedList, String string);//Mira o pointer no elemento com determinado dado
void targetByIndex(LinkedList* linkedList, int index);//Mira o Pointer no elemento com determinado index

void removeNode(LinkedList* linkedList, Node* node);//Só precisa saber o Node que será apagado, ja que ele irá saber sua propria posição
void addNodeAfter(LinkedList* linkedList, Node* fromlist, Node* newNode);//Adicionar em uma posição especifica da lista

void addNodeAtFirst(LinkedList* linkedlist,Node* node);//Necessita saber a lista onde vai ser adicionado o dado por primeiro
void addNodeAtLast(LinkedList* linkedlist,Node* node);//Necessita saber a lista onde vai ser adicionado o dado por ultimo
void removeAtFirst(LinkedList* linkedList);//Remove o primeito elemento de uma lista
void RemoveAtLast(LinkedList* linkedList);//remove o ultimo elemento da lista

Node* buildNode(char* string);//Recebe um Array de Char e retorna um node que armazena
Node* searchByData(LinkedList* linkedlist, String string);//Procurar um node pelo conteúdo
Node* searchByIndex(LinkedList* linkedlist, int index);//Procura um node com base no seu index
Node* getFirst(LinkedList* linkedlist);//Pega o primeiro elemento
Node* getLast(LinkedList* linkedlist);//Pega o ultimo elemento

void clearLinkedList(LinkedList* linkedList);//Deleta uma lista

//Tentar implementar depois:
void forEachNode(const LinkedList* linkedList, void (*func)(Node*));//Executa uma função para cada Elemento da lista
LinkedList* findNodesWithCondition(const LinkedList* linkedList, bool (*condition)(const Node*));//Retorna uma Lista de elementos com determinadas caracterisiticas
void sortLinkedList(LinkedList* linkedList, int (*comparator)(const Node*, const Node*));//Organiza a lista com determinado parametro
void sortAscending(LinkedList* linkedList);//organiza de forma Crescente
void sortDescending(LinkedList* linkedList);//organiza de forma decrescente

#endif //DATASTRUCTC_LINKEDLIST_H
