#ifndef DEQUE_H
#define DEQUE_H

#include <stdbool.h>

typedef struct {

    char* text;

    unsigned long length;
    
}String;//Estrutura de texto

typedef struct Node Node;

typedef struct Node{

    String element;

    Node* next;
    Node* prev;

}Node;//Elemento da Lista

typedef struct{

    Node* header;//Sentinela head

    Node* tail;//Sentinela tail

    int size;
}Deque;

Deque* builder();//Retorna um Deque

Node* buildNode(const char* string);//Recebe um array de char e retorna um Node
void Delete(Node* node);//Apaga um Node da memoria

void addFirst(Deque* deque ,Node* node);//Adiciona elemento na primeira posição
void addLast(Deque* deque, Node* node);//Adiciona elemento na ultima posição

Node* removeFirst(Deque* deque);//Remove e retorna o primeiro elemento
Node* removeLast(Deque* deque);//Remove e retorna o ultimo elemento

Node* getFirst(const Deque* deque);//Retorna o primeiro elemento
Node* getLast(const Deque* deque);//Retorna o ultimo elemento

int size(const Deque* deque);//Retorna o tamanho
bool isEmpty(const Deque* deque);//Retoan se o Deque está vazio ou não

void deleteDeque(Deque* deque);//Limpa o deque da memoria

#endif //DEQUE_H