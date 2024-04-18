//
// Created by dinho on 18/04/24.
//

#include "linkedlist.h"
#include <stdlib.h>
#include <string.h>

Node* buildNode(char* string){
    Node* node = (Node*) malloc(sizeof(Node));

    node->element.text = strdup(string);
    node->element.length = strlen(string);

    node->next = NULL;
    node->prev = NULL;

    return node;
}

void DeleteString(String* string){
    if(string->text != NULL) free(string-> text);
    string->text = NULL;
}

void Delete(Node* node){
    node->next = NULL;
    node->prev = NULL;

    DeleteString(&node->element);

    free(node);
}

void refreshIndex(Node* node, int operator){
    while(node->next != NULL){
        node->index += operator;
        node = node->next;
    }
}

LinkedList* builder(){
    LinkedList* linkedList =(LinkedList*) malloc(sizeof(LinkedList));

    linkedList->header = buildNode("__HEADER__");


    linkedList->tail = buildNode("__TAIL__");



    linkedList->tail->prev = linkedList->header;
    linkedList->header->next = linkedList->tail;

    linkedList->size = 0;

    return linkedList;
}


void addNodeAfter(LinkedList* linkedList, Node* fromList, Node* newNode){

    if(fromList == linkedList->tail || newNode == linkedList->tail || newNode == linkedList->header) return;

    Node* nodeNext = fromList->next;

    newNode->next = nodeNext;
    newNode->prev = fromList;

    fromList->next = newNode;
    nodeNext->prev = newNode;

    if(fromList == linkedList->header) newNode->index = 0;
    else newNode->index = fromList->index + 1;

    if(linkedList->size != 0) refreshIndex(newNode->next, 1);

    linkedList->size++;
}

void removeNode(LinkedList* linkedList, Node* node){
    if( node == linkedList->header || linkedList->tail == node || node == NULL
        || linkedList->size == 0 ) return;

    Node* prev = node->prev;
    Node* next = node->next;

    prev->next = next;
    next->prev = prev;

    refreshIndex(node, -1);

    Delete(node);

    linkedList->size--;
}
void addNodeAtFirst(LinkedList* linkedlist, Node* node){
    addNodeAfter(linkedlist, linkedlist->header, node);
}
void addNodeAtLast(LinkedList* linkedlist,Node* node){
    addNodeAfter(linkedlist, linkedlist->tail->prev, node);
}
void removeAtFirst(LinkedList* linkedList){
    removeNode(linkedList, linkedList->header->next);
}
void RemoveAtLast(LinkedList* linkedList){
    removeNode(linkedList, linkedList->tail->prev);
}

Node* searchByData(LinkedList* linkedlist, String string){
    Node* pointer = linkedlist->header->next;
    while(strcmp(pointer->element.text, string.text) != 0
            && pointer->next->next != NULL){
        pointer = pointer->next;
    }
    return strcmp(pointer->element.text, string.text) == 0 ? pointer : NULL;
}

Node* searchByIndex(LinkedList* linkedlist, int index){
    Node* pointer = linkedlist->header->next;
    while(pointer->index != index
            &&pointer->next->next != NULL){
        pointer = pointer->next;
    }
    return pointer->index == index ? pointer : NULL;
}

Node* getFirst(LinkedList* linkedList){
    return linkedList->header->next;
}

Node* getLast(LinkedList* linkedList){
    return linkedList->tail->prev;
}

void clearLinkedList(LinkedList* linkedList){
    while(linkedList->size > 0) removeAtFirst(linkedList);
    Delete(linkedList->header);
    Delete(linkedList->tail);
    free(linkedList);
}

