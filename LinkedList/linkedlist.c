//
// Created by dinho on 18/04/24.
//

#include "linkedlist.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
//PRINTA UM NODE NA TELA
void printNode(Node* node) {
    printf("Node index: %d, Data: %s\n", node->index, node->element.text);
}
//CONSTROI UM NODE
Node* buildNode(const char* string){
    //COMEÇA ALOCANDO NOVA MEMORIA
    Node* node = (Node*) malloc(sizeof(Node));

    //COPIA OS DADOS DA STRING PASSADA
    node->element.text = strdup(string);
    node->element.length = strlen(string);

    //DEFINE OS SEGUINTES E OS ANTERIORES COMO NULL
    node->next = NULL;
    node->prev = NULL;

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
    node->prev = NULL;

    //APAGA A STRING
    DeleteString(&node->element);

    //APAGA O NODE
    free(node);
}

//ATUALIZA TODOS OS INDEX DOS NODES SEGUINTES AO DEFINIDO, CASO OPERADOR SEJA 1 ELE SOMA, CASO SEJA -1 ELE SUBTRAI
void refreshIndex(Node* node, int operator){
    while(node->next != NULL){
        //MODIFICA O INDEX
        node->index += operator;
        //PASSA PARA O NODE SEGUINTE
        node = node->next;
    }
}
//CONSTRUTOR DE LINKEDLIST
LinkedList* builder(){
    //COMEÇA ALOCANDO O ESPAÇO DE UMA LINKEDLIST
    LinkedList* linkedList =(LinkedList*) malloc(sizeof(LinkedList));

    //CONSTROI HEADER(SENTINELA)
    linkedList->header = buildNode("__HEADER__");
    //CONSTROI A TAIL(SENTINELA)
    linkedList->tail = buildNode("__TAIL__");


    //DEFINE O ANTERIOR AO TAIL COMO SENDO O HEADER, JA QUE ESTÁ VAZIA
    linkedList->tail->prev = linkedList->header;
    //DEFINE O ANTERIOR AO HEADER COMO SENDO A TAIL, JA QUE ESTÁ VAZIA
    linkedList->header->next = linkedList->tail;

    //DEFINE O TAMANHO COMO 0
    linkedList->size = 0;

    //RETORNA A LINKEDLIST
    return linkedList;
}


void addNodeAfter(LinkedList* linkedList, Node* fromList, Node* newNode){

    //DEBUG
//    printf("fromList == linkedList->tail: %s\n", fromList == linkedList->tail ? "true" : "false");
//    printf("newNode == linkedList->tail: %s\n", newNode == linkedList->tail ? "true" : "false");
//    printf("newNode == linkedList->header: %s\n", newNode == linkedList->header ? "true" : "false");

    //VERIFICAÇÕES PARA EVITAR ERRO
    if(fromList == linkedList->tail || newNode == linkedList->tail || newNode == linkedList->header) return;


    //PEGA O SEGUINTE DA LISTA
    Node* nodeNext = fromList->next;

    //DEFINE O PROXIMO DO NOVO NODE COMO SENDO O SEGUINTE DO NODE ANTERIOR
    newNode->next = nodeNext;
    //DEFINE O ANTERIOR COMO SENDO O NODE PASSADO
    newNode->prev = fromList;

    //FAZ OS NODES DA LISTA APONTAR PARA O NOVO NODE
    fromList->next = newNode;
    nodeNext->prev = newNode;
    //CASO O fromList SEJA O HEADER, OU SEJA, QUEREM ADICIONAR O NOVO NODE COMO O PRIMEIRO DA LISTA, DEFINE O INDEX DELE COMO 0
    if(fromList == linkedList->header) newNode->index = 0;
    //CASO CONTRARIO ELE PEGA O INDEX DO NODE DA LISTA PASSADO E SOMA 1
    else newNode->index = fromList->index + 1;

    //CASO A LISTA CONTENHA OUTROS ELEMENTOS, ELE ATUALIZA OS INDEX DOS ELEMENTOS SEGUINTES
    if(linkedList->size != 0) refreshIndex(newNode->next, 1);

    //AUMENTA O TAMANHO DA LISTA
    linkedList->size++;
}
//REMOVE UM NODE
void removeNode(LinkedList* linkedList, Node* node){
    //VERIFICAÇÕES PARA EVITAR ERRO
    if( node == linkedList->header || linkedList->tail == node || node == NULL
        || linkedList->size == 0 ) return;

    //PEGA O NODE SEGUINTE E ANTERIOR DO QUE ESTÁ PARA SER REMOVIDO
    Node* prev = node->prev;
    Node* next = node->next;

    //FAZ OS NODES SEGUINTE E ANTERIOR APONTAREM UM PARA O OUTRO
    prev->next = next;
    next->prev = prev;

    //ATUALIZA TODOS OS INDICES SEGUINTES
    refreshIndex(node, -1);

    //APAGA O NODE
    Delete(node);

    //DIMINUI O TAMANHO DA LISTA
    linkedList->size--;
}
//REMOVER UM ELEMENTO SEM APAGAR ELE DA MEMORIA
void removeNodeWithOutDelete(LinkedList* linkedList, Node* node){
    //VERIFICAÇÕES PARA EVITAR ERRO
    if( node == linkedList->header || linkedList->tail == node || node == NULL
        || linkedList->size == 0 ) return;

    //PEGA O NODE SEGUINTE E ANTERIOR DO QUE ESTÁ PARA SER REMOVIDO
    Node* prev = node->prev;
    Node* next = node->next;

    //FAZ OS NODES SEGUINTE E ANTERIOR APONTAREM UM PARA O OUTRO
    prev->next = next;
    next->prev = prev;

    node->prev = NULL;
    node->next = NULL;

    //ATUALIZA TODOS OS INDICES SEGUINTES
    refreshIndex(node, -1);

    //DIMINUI O TAMANHO DA LISTA
    linkedList->size--;
}

//ADICIONA UM NODE NA PRIMEIRA POSIÇÃO DA LISTA USANDO O HEADER COMO REFERÊNCIA
void addNodeAtFirst(LinkedList* linkedlist, Node* node){
    addNodeAfter(linkedlist, linkedList->header, node);
}
//ADICIONA O ELEMENTO NA ULTIMA POSIÇÃO DA LISTA USANDO O ANTERIOR A TAIL COMO REFERÊNCIA
void addNodeAtLast(LinkedList* linkedlist,Node* node){
    addNodeAfter(linkedlist, getLast(linkedlist), node);
}
//REMOVE UM NODE NA PRIMEIRA POSIÇÃO DA LISTA USANDO O HEADER COMO REFERÊNCIA
void removeAtFirst(LinkedList* linkedList){
    removeNode(linkedList, linkedList->header->next);
}
//REMOVE O ELEMENTO NA ULTIMA POSIÇÃO DA LISTA USANDO O ANTERIOR A TAIL COMO REFERÊNCIA
void RemoveAtLast(LinkedList* linkedList){
    removeNode(linkedList, linkedList->tail->prev);
}
//PROCURA UM ELEMENTO COM BASE NO TEXTO FORNECIDO
Node* searchByData(const LinkedList* linkedlist, const char* string){
    //COMEÇA DO PRIMEIRO ELEMENTO
    Node* pointer = linkedlist->header->next;
    //ENQUANTO O TEXTO DO ELEMENTO NÃO FOR IGUAL AO PASSADO E AINDA HOUVER ELEMENTOS VALIDOS NA LISTA
    while(strcmp(pointer->element.text, string) != 0
            && pointer != linkedlist->tail){
        //PULA PARA O PROXIMO ELEMENTO
        pointer = pointer->next;
    }
    //SE O ELEMENTO FOR IGUAL AO TEXTO PASSADO PARA PESQUISA ELE RETORNA, SE NÃO ELE RETORNA NULL
    return strcmp(pointer->element.text, string) == 0 ? pointer : NULL;
}
//PROCURA POR INDICE
Node* searchByIndex(const LinkedList* linkedlist, const int index){
    //VERIFICA SE O INDEX É VALIDO
    if (index < 0 || index >= linkedlist->size) return NULL;

    //FAZ UMA VERIFICAÇÃO RAPIDA PARA VER SE O INDEX PROCURADO NÃO SE REFERE DIRETAMENTE AO PRIMEIRO OU AO ULTIMO
    if (index == 0) return linkedlist->header->next;
    else if (index == linkedlist->size - 1) return linkedlist->tail->prev;


    Node* pointer = NULL;
    //COMEÇA VERIFICANDO SE O INDEX SE ENCONTRA NA PRIMEIRA METADE OU NA SEGUNDA METADE DA LISTA, E MENOR DO QUE O TAMANHO TOTAL DA LISTA
    if(index >= linkedlist->size/2){
        //PEGA O ULTIMO ELEMENTO
        pointer = linkedlist->tail->prev;
        //ENQUANTO O INDEX DO ELEMENTO FOR DIFERENTE DO INDEX PASSADO E AINDA ESTIVER ACIMA DA METADE DA LISTA
        while(pointer->index != index && pointer->prev->index > linkedlist->size/2){
            //ELE PEGA O ANTERIOR
            pointer = pointer->prev;
        }
    //ENQUANTO O ELEMENTO FOR MAIOR QUE 0 E MENOR QUE A METADE DA LISTA
    }else {
        //PEGA O PRIMEIRO ELEMENTO
        pointer = linkedlist->header->next;
        //ENQUANTO O INDEX FOR DIFERENTE DO FORNECIDO E NÃO ESTIVER CHEGADO NA METADE DA LISTA AINDA
        while (pointer->index != index && pointer->next->index < linkedlist->size/2) {
            //PEGA O PROXIMO
            pointer = pointer->next;
        }
    }

    return pointer->index == index ? pointer : NULL;
}
//PEGA O PRIMEIRO ELEMENTO, CASO A LISTA ESTEJA VAZIA ELE RETORNA O HEADER
Node* getFirst(const LinkedList* linkedList){
    return linkedList->size != 0 ? linkedList->header->next : linkedList->header;
}
//PEGA O ULTIMO ELEMENTO, CASO A LISTA ESTEJA VAZIA ELE RETORNA A TAIL
Node* getLast(const LinkedList* linkedList){
    return linkedList->size != 0 ? linkedList->tail->prev : linkedList->tail;
}
//LIMPA UMA LISTA DA MEMORIA
void clearLinkedList(LinkedList* linkedList){
    while(linkedList->size > 0) removeAtLast(linkedList);//VAI REMOVENDO NODE POR NODE
    Delete(linkedList->header);//REMOVE O HEADER
    Delete(linkedList->tail);//REMOVE A TAIL
    free(linkedList);//REMOVE A LISTA
}

//APLICA DETERMINADA FUNÇÃO EM CADA MEMBRO DA LISTA
void forEachNode(const LinkedList* linkedList, void (*func)(Node*)){
    if(linkedList == NULL) return;//VERIFICA SE A LISTA ESTÁ VAZIA
    Node* pointer = getFirst(linkedList);//PEGA O PRIMEIRO ELEMENTO DA LISTA
    while(pointer != linkedList->tail){//ENQUANTO NÃO CHEGAR NO ULTIMO
        func(pointer);//APLICA A FUNÇÃO
        pointer = pointer->next;//PASSA PARA O PROXIMO
    }
}
//RETORNA UMA SUBLISTA DE UMA LISTA MAIOR COM UM FILTRO APLICADO
LinkedList* findNodesWithCondition(const LinkedList* linkedList, bool (*condition)(const Node*)){
    Node* pointer = getFirst(linkedList);//PEGA O PRIMEIRO ELEMENTO

    LinkedList* newOne = builder();//CRIA UMA LISTA

    while(pointer != linkedList->tail){//PERCORRE TODA A LISTA
        if(condition(pointer)){//VERIFICA SE O ELEMENTO SE ENCAIXA
            //ADICIONA ELE NA NOVA LISTA
           addNodeAfter(newOne, getFirst(newOne), buildNode(pointer->element.text));
        }
        //VAI PARA O PROXIMO ELEMENTO
        pointer = pointer->next;
    }

    return newOne;
}
//ORGANIZA A LISTA DE ACORDO COM UM COMPARADOR
void sortLinkedList(LinkedList* linkedList, int (*comparator)(const Node*, const Node*)){
    Node* pivot;
    Node* ins;
    Node* pointer = getFirst(linkedList);//DEFINE VARIAVEIS DE SUPORTE
    while(pointer != getLast(linkedList)){
        pivot = pointer->next;//DEFINE O ELEMENTO A SER ORDENADO
        removeNodeWithOutDelete(linkedList, pivot);//REMOVE DA LISTA SEM APAGAR DA MEMORIA
        ins = pointer;//DEFINE O ELEMENTO A SER COMPARADO
        // ENQUANTO NÃO CHEGAR NO FINAL
        while(ins != linkedList->tail && comparator(ins, pivot) > 0){//comparator: se ins > pivot retorna int > 0, se ins == pivot retorna 0, se ins menor que pivot retorna < 0
            ins = ins->prev;//VAI PASSANDO ELEMENTO POR ELEMENTO ATÉ ACHAR A POSIÇÃO CERTA
        }
        addNodeAfter(linkedList, ins, pivot);//ADICIONA DE VOLTA A LISTA NA POSIÇÃO CERTA
        if(ins == pointer) pointer = pointer->next;//SE NÃO TIVER TROCADO DE POSIÇÃO ENTÃO PASSA PARA O PROXIMO ELEMENTO
    }
}
//VERIFICAÇÃO CRESCENTE
int ascending(const Node* node1, const Node* node2){
    return strcmp(node1->element.text,node2->element.text);
}
//VERIFICAÇÃO DECRESCENTE
int descending(const Node* node1, const Node* node2){
    return (-1) * ascending(node1, node2);
}
//ORGANIZA DE FORMA CRESCENTE
void sortAscending(LinkedList* linkedList){
    sortLinkedList(linkedList, ascending);
}
//ORGANIZA DE FORMA DECRESCENTE
void sortDescending(LinkedList* linkedList){
    sortLinkedList(linkedList, descending);
}

