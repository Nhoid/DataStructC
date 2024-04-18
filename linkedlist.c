//
// Created by dinho on 18/04/24.
//

#include "linkedlist.h"
#include <stdlib.h>
#include <string.h>

Node* buildNode(char* string){
    Node* node = (Node*) malloc(sizeof(Node));
    if(!node){return NULL;}

    node->element.text = strdup(string);
    node->element.length = strlen(string);

    node->next = NULL;
    node->prev = NULL;

    return node;
}

void DeleteString(String* string){
    if(string->text != NULL) free(string-> text);
}

void Delete(Node* node){
    node->next = NULL;
    node->prev = NULL;

    free(node->next);
    free(node->prev);

    DeleteString(&node->element);

    free(node);
}

void refreshIndex(Node* node, int operator){
    while(node->next->next != NULL){
        node->index += operator;
        node = node->next;
    }
}

LinkedList* builder(){
    LinkedList* linkedList =(LinkedList*) malloc(sizeof(LinkedList));

    linkedList->header = buildNode("__HEADER__");
    linkedList->tail = buildNode("__TAIL__");

    linkedList->pointer = buildNode("__POINTER__");

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

    newNode->index = nodeNext->index;

    refreshIndex(nodeNext, 1);

    linkedList->size++;

    Delete(nodeNext);
}

void removeNode(LinkedList* linkedList, Node* node){
    if( node == linkedList->header || linkedList->tail == node) return;

    Node* prev = node->prev;
    Node* next = node->next;

    prev->next = next;
    next->prev = prev;

    if(linkedList->pointer == node) linkedList->pointer = NULL;

    refreshIndex(node, -1);

    Delete(node);
    Delete(next);
    Delete(prev);

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
    linkedlist->pointer = linkedlist->header->next;
    while(strcmp(linkedlist->pointer->element.text, string.text) != 0){
        if(!advance(linkedlist->pointer)) break;
    }
    return linkedlist->pointer;
}

Node* searchByIndex(LinkedList* linkedlist, int index){
    linkedlist->pointer = linkedlist->header->next;
    while(linkedlist->pointer->index != index) if(!advance(linkedlist->pointer)) break;
    return linkedlist->pointer;
}

Node* getFirst(LinkedList* linkedList){
    return linkedList->header->next;
}

Node* getLast(LinkedList* linkedList){
    return linkedList->tail->prev;
}

bool advance(Node* pointer){
    if(pointer->next->next == NULL) return false;
    else *pointer = *pointer->next; return true;
}

bool goBack(Node* pointer){
    if(pointer->prev->prev == NULL) return false;
    else *pointer = *pointer->prev; return true;
}

void targetByData(LinkedList* linkedList, String string){
    linkedList->pointer = searchByData(linkedList, string);
}

void targetByIndex(LinkedList* linkedList, int index){
    linkedList->pointer = searchByIndex(linkedList, index);
}

void clearLinkedList(LinkedList* linkedList){
    while(linkedList->size > 0) removeAtFirst(linkedList);
    Delete(linkedList->header);
    Delete(linkedList->tail);
    Delete(linkedList->pointer);
    free(linkedList);
}

