# Implementação de LinkedList em C

Este repositório contém a implementação de uma lista ligada (LinkedList) em linguagem C. A lista ligada é uma estrutura de dados dinâmica que permite a inserção, remoção e manipulação de elementos de forma eficiente.

## Estruturas de Dados

### String
```c
typedef struct {
    char* text;
    unsigned long length;
} String;
```
Estrutura para representar um texto.

### Node 

```c
typedef struct Node {
    int index;
    String element;
    Node* next;
    Node* prev;
} Node;
```
Estrutura para representar um nó da lista ligada.

### LinkedList

```c
typedef struct {
    Node* header; // Sentinela head
    Node* tail;   // Sentinela tail
    int size;
} LinkedList;
```
Estrutura para representar a lista ligada.

Funções Disponíveis
-------------------

- `LinkedList* builder();`
    - Retorna uma nova instância de `LinkedList`.
    
- `Node* buildNode(const char* string);`
    - Recebe um array de caracteres e retorna um novo nó.
    
- `void Delete(Node* node);`
    - Apaga um nó da memória.
    
- `void removeNode(LinkedList* linkedList, Node* node);`
    - Remove um nó específico da lista.
    
- `void addNodeAfter(LinkedList* linkedList, Node* fromlist, Node* newNode);`
    - Adiciona um novo nó em uma posição específica da lista.
    
- `void addNodeAtFirst(LinkedList* linkedlist, Node* node);`
    - Adiciona um novo nó no início da lista.
    
- `void addNodeAtLast(LinkedList* linkedlist, Node* node);`
    - Adiciona um novo nó no final da lista.
    
- `void removeAtFirst(LinkedList* linkedList);`
    - Remove o primeiro nó da lista.
    
- `void RemoveAtLast(LinkedList* linkedList);`
    - Remove o último nó da lista.
    
- `Node* searchByData(const LinkedList* linkedlist, const char* string);`
    - Procura um nó com base no conteúdo.
    
- `Node* searchByIndex(const LinkedList* linkedlist, const int index);`
    - Procura um nó com base no seu índice.
    
- `Node* getFirst(const LinkedList* linkedlist);`
    - Retorna o primeiro nó da lista.
    
- `Node* getLast(const LinkedList* linkedlist);`
    - Retorna o último nó da lista.
    
- `void clearLinkedList(LinkedList* linkedList);`
    - Deleta todos os nós da lista.
    
- `void forEachNode(const LinkedList* linkedList, void (*func)(Node*));`
    - Executa uma função para cada nó da lista.
    
- `LinkedList* findNodesWithCondition(const LinkedList* linkedList, bool (*condition)(const Node*));`
    - Retorna uma lista de nós que atendem a uma condição específica.
    
- `void sortLinkedList(LinkedList* linkedList, int (*comparator)(const Node*, const Node*));`
    - Ordena a lista com base em um comparador.
    
- `void sortAscending(LinkedList* linkedList);`
    - Ordena a lista em ordem crescente.
    
- `void sortDescending(LinkedList* linkedList);`
    - Ordena a lista em ordem decrescente.
