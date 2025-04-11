#include "deque.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>

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

//CONSTRUTOR DE DEQUE
Deque* builder(){
    //COMEÇA ALOCANDO O ESPAÇO DE UM DEQUE
    Deque* deque =(Deque*) malloc(sizeof(Deque));

    //CONSTROI HEADER(SENTINELA)
    deque->header = buildNode("__HEADER__");
    //CONSTROI A TAIL(SENTINELA)
    deque->tail = buildNode("__TAIL__");


    //DEFINE O ANTERIOR AO TAIL COMO SENDO O HEADER, JA QUE ESTÁ VAZIA
    deque->tail->prev = deque->header;
    //DEFINE O ANTERIOR AO HEADER COMO SENDO A TAIL, JA QUE ESTÁ VAZIA
    deque->header->next = deque->tail;

    //DEFINE O TAMANHO COMO 0
    deque->size = 0;

    //RETORNA O DEQUE
    return deque;
}

void addNodeAfter(Deque* deque, Node* fromList, Node* newNode){

    //VERIFICAÇÕES PARA EVITAR ERRO
    if(fromList == deque->tail || newNode == deque->tail || newNode == deque->header) return;

    //PEGA O SEGUINTE DA DEQUE
    Node* nodeNext = fromList->next;

    //DEFINE O PROXIMO DO NOVO NODE COMO SENDO O SEGUINTE DO NODE ANTERIOR
    newNode->next = nodeNext;
    //DEFINE O ANTERIOR COMO SENDO O NODE PASSADO
    newNode->prev = fromList;

    //FAZ OS NODES DA DEQUE APONTAR PARA O NOVO NODE
    fromList->next = newNode;
    nodeNext->prev = newNode;


    //AUMENTA O TAMANHO DO DeQUE
    deque->size++;
}

//REMOVE UM NODE
void removeNode(Deque* deque, Node* node){
    //VERIFICAÇÕES PARA EVITAR ERRO
    if( node == deque->header || deque->tail == node || node == NULL
        || deque->size == 0 ) return;

    //PEGA O NODE SEGUINTE E ANTERIOR DO QUE ESTÁ PARA SER REMOVIDO
    Node* prev = node->prev;
    Node* next = node->next;

    //FAZ OS NODES SEGUINTE E ANTERIOR APONTAREM UM PARA O OUTRO
    prev->next = next;
    next->prev = prev;

    //APAGA O NODE
    Delete(node);

    //DIMINUI O TAMANHO DO DEQUE
    deque->size--;
}


//Retorna o tamanho
int size(const Deque* deque){
	return deque->size;
}
//Retoan se o Deque está vazio ou não
bool isEmpty(const Deque* deque){
	return size(deque) == 0;
}


//Retorna o primeiro elemento
Node* getFirst(const Deque* deque){
	//Retorna o primeiro elemento. Caso esteja vazia retorna o header
	return isEmpty(deque) ? deque->header : deque->header->next;
}
//Retorna o ultimo elemento
Node* getLast(const Deque* deque){
	//Retorna o ultimo elemento. Caso esteja vazia retorna o tail
	return isEmpty(deque) ? deque->tail : deque->tail->prev;
}


//Adiciona elemento na primeira posição
void addFirst(Deque* deque ,Node* node){
	addNodeAfter(deque, deque->header, node);//Chama função addNodeAfter
}

//Adiciona elemento na ultima posição
void addLast(Deque* deque, Node* node){
	addNodeAfter(deque, getLast(deque), node);//Chama função addNodeAfter
}

//Remove e retorna o primeiro elemento
Node* removeFirst(Deque* deque){

	// Cria uma copia do primeiro
	Node* node = buildNode(getFirst(deque)->element.text);

	//Apaga o elemento
	removeNode(deque, getFirst(deque));

	return node;
}

//Remove e retorna o ultimo elemento
Node* removeLast(Deque* deque){
	// Cria uma copia do primeiro
	Node* node = buildNode(getLast(deque)->element.text);

	//Apaga o elemento
	removeNode(deque, getLast(deque));

	return node;
}

//Limpa o deque da memoria
void deleteDeque(Deque* deque){
	while(!isEmpty(deque)){
		removeFirst(deque);
	}

	Delete(deque->header);
	Delete(deque->tail);

	free(deque);
}