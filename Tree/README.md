# Implementação de Árvore Binária Genérica em C

Este repositório contém a implementação de uma Árvore Binária de Busca (BST) genérica em linguagem C. Ao contrário das outras estruturas implementadas anteriormente com `char*`, esta árvore armazena qualquer tipo de dado utilizando ponteiros `void*`. O usuário é responsável por fornecer funções personalizadas para criação, comparação e liberação de nós.

## Estrutura de Dados

### Node

```c
typedef struct Node {
    void* element;
    Node* left;
    Node* right;
} Node;
```
Representa um nó da árvore, contendo um ponteiro genérico para o dado armazenado, e ponteiros para os nós filhos à esquerda e à direita.

### Tree

```c
typedef struct {
    Node* root;
    int size;

    int (*comparator)(void* element1, void* element2);
    Node* (*buildNode)(void* data);
    void (*freeNode)(Node* node);
} Tree;
```
Representa a árvore binária, contendo a raiz, o número de elementos, e funções para comparar, construir e liberar nós.

## Funcionalidades Disponíveis

- `Tree* buildTree(...)`: Cria uma nova árvore binária genérica.
- `Node* searchElement(...)`: Busca um elemento na árvore.
- `Node* searchNode(...)`: Busca um nó específico na árvore.
- `Node* searchParent(...)`: Busca o pai de um determinado nó.
- `Node* searchMinor(...)`: Retorna o menor elemento da árvore.
- `Node* searchMajor(...)`: Retorna o maior elemento da árvore.
- `Node* searchMinorSubTree(...)`: Retorna o menor elemento de uma subárvore.
- `Node* searchMajorSubTree(...)`: Retorna o maior elemento de uma subárvore.
- `int insertNode(...)`: Insere um nó diretamente na árvore.
- `int insertElement(...)`: Insere um elemento genérico na árvore.
- `int removeNode(...)`: Remove um nó específico da árvore.
- `int removeElement(...)`: Remove um elemento da árvore.
- `int removeParent(...)`: Remove um nó com filhos, substituindo-o pelo seu sucessor.
- `int balanceTree(...)`: Balanceia a árvore binária.
- `void traversalTreeInOrder(...)`: Percorre a árvore em ordem (in-order).
- `void traversalTreePreOrder(...)`: Percorre a árvore em pré-ordem (pre-order).
- `void traversalTreePostOrder(...)`: Percorre a árvore em pós-ordem (post-order).
- `void freeTree(...)`: Libera toda a memória da árvore.

## Observações

- O desenvolvedor deve fornecer três funções obrigatórias:
    - `comparator`: para comparar elementos.
    - `buildNode`: para criar novos nós com o tipo de dado desejado.
    - `freeNode`: para liberar corretamente os nós da árvore.
- Os retornos das funções ainda podem ser revisados para um tratamento de erro mais robusto.

