# Implementação de Deque em C

Este repositório contém a implementação de um deque (Deque) em linguagem C. O deque é uma estrutura de dados que permite a inserção e remoção eficientes de elementos nas duas extremidades da estrutura.

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
    String element;
    Node* next;
    Node* prev;
} Node;
```
Estrutura para representar um nó do deque.

### Deque

```c
typedef struct {
    Node* header; // Sentinela head
    Node* tail;   // Sentinela tail
    int size;
} Deque;
```
Estrutura para representar o deque.

Funções Disponíveis
-------------------

- `Deque* builder();`
    - Retorna uma nova instância de `Deque`.
- `Node* buildNode(const char* string);`
    - Recebe um array de caracteres e retorna um novo nó.
- `void Delete(Node* node);`
    - Apaga um nó da memória.
- `void addFirst(Deque* deque, Node* node);`
    - Adiciona um elemento na primeira posição do deque.
- `void addLast(Deque* deque, Node* node);`
    - Adiciona um elemento na última posição do deque.
- `Node* removeFirst(Deque* deque);`
    - Remove e retorna o primeiro elemento do deque.
- `Node* removeLast(Deque* deque);`
    - Remove e retorna o último elemento do deque.
- `Node* getFirst(const Deque* deque);`
    - Retorna o primeiro elemento do deque.
- `Node* getLast(const Deque* deque);`
    - Retorna o último elemento do deque.
- `int size(const Deque* deque);`
    - Retorna o tamanho do deque.
- `bool isEmpty(const Deque* deque);`
    - Retorna verdadeiro se o deque estiver vazio, falso caso contrário.
- `void deleteDeque(Deque* deque);`
    - Limpa o deque da memória.
