# Implementação de Stack em C

Este repositório contém a implementação de uma pilha (Stack) em linguagem C. A pilha é uma estrutura de dados que segue o princípio LIFO (Last In, First Out), onde os elementos são adicionados e removidos do topo da pilha.

## Estruturas de Dados

### String
```c
typedef struct {
    char* text;
    unsigned long length;
} String
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

### Stack

```c
typedef struct {
    Node* first; // Primeiro elemento da pilha
    int size;
} Stack;
```

Estrutura para representar a pilha.

Funções Disponíveis
-------------------

- `Stack* builder();`
    - Cria uma nova instância de `Stack`.
- `Node* buildNode(const char* string);`
    - Cria um novo nó a partir de um array de caracteres.
- `void Delete(Node* node);`
    - Apaga um nó da memória.
- `int size(const Stack* stack);`
    - Retorna o tamanho da pilha.
- `bool isEmpty(const Stack* stack);`
    - Verifica se a pilha está vazia.
- `Node* top(const Stack* stack);`
    - Retorna o primeiro elemento da pilha.
- `void reverseArray(String* array, int size);`
    - Inverte um array de `String`.
- `void push(Stack* stack, Node* node);`
    - Insere um novo elemento no topo da pilha.
- `Node pop(Stack* stack);`
    - Remove e retorna o primeiro item da pilha.
- `void deleteStack(Stack* stack);`
    - Libera a memória ocupada pela pilha.
