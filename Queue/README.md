# Implementação de Queue em C

Este repositório contém a implementação de uma fila (Queue) em linguagem C. A fila é uma estrutura de dados que segue o princípio FIFO (First In, First Out), onde os elementos são adicionados no final da fila e removidos do início.

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
} Node;
```

Estrutura para representar um nó da fila.

### Queue

```c
typedef struct {
    Node* last;  // Último elemento da fila
    Node* first; // Primeiro elemento da fila
    int size;
} Queue;
```

Estrutura para representar a fila.

Funções Disponíveis
-------------------

- `Queue* builder();`
    - Retorna uma nova instância de `Queue`.
- `Node* buildNode(const char* string);`
    - Recebe um array de caracteres e retorna um novo nó.
- `void Delete(Node* node);`
    - Apaga um nó da memória.
- `void enqueue(Queue* queue, Node* node);`
    - Adiciona um elemento no final da fila.
- `Node* dequeue(Queue* queue);`
    - Remove e retorna o primeiro elemento da fila.
- `int size(const Queue* queue);`
    - Retorna o tamanho da fila.
- `bool isEmpty(const Queue* queue);`
    - Retorna verdadeiro se a fila estiver vazia, falso caso contrário.
- `Node* front(const Queue* queue);`
    - Retorna, mas não remove, o primeiro elemento da fila.
- `void deleteQueue(Queue* queue);`
    - Libera a memória ocupada pela fila.








