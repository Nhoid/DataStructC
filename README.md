# Estruturas de Dados Básicas

Este repositório foi criado para fins de aprendizado, com base no livro *Estruturas de Dados & Algoritmos em Java* de Michael T. Goodrich e Roberto Tamassia. As implementações são feitas em C para reforçar os conceitos estudados.

Cada estrutura de dados está organizada em pastas individuais com seu respectivo nome. Cada uma contém os seguintes diretórios e arquivos:

- `include/` com os arquivos `.h` (headers)
- `src/` com os arquivos `.c`, incluindo o `main.c`
- `bin/` (inicialmente vazia), onde o executável será gerado
- `Makefile` para facilitar a compilação

> ⚠️ As primeiras estruturas (LinkedList, Queue, Deque, Stack) foram feitas na época em que eu estava começando a estudar o assunto. Pretendo refazê-las futuramente de forma genérica, como fiz com a árvore.

## Estruturas Implementadas

- [x] LinkedList (Lista Ligada)
- [x] Queue (Fila)
- [x] Deque (Deque)
- [x] Stack (Pilha)
- [x] BinaryTree (Árvore Binária Genérica)

## Estrutura do Repositório

O repositório está organizado da seguinte forma:

- **LinkedList/**
  - `include/linkedList.h`
  - `src/linkedList.c`
  - `src/main.c`
  - `bin/` (pasta onde o executável será gerado)
  - `Makefile`
- **Queue/**
  - `include/queue.h`
  - `src/queue.c`
  - `src/main.c`
  - `bin/`
  - `Makefile`
- **Deque/**
  - `include/deque.h`
  - `src/deque.c`
  - `src/main.c`
  - `bin/`
  - `Makefile`
- **Stack/**
  - `include/stack.h`
  - `src/stack.c`
  - `src/main.c`
  - `bin/`
  - `Makefile`
- **Tree/**
  - `include/tree.h`
  - `src/tree.c`
  - `src/main.c`
  - `bin/`
  - `Makefile`

## Como Executar

Para compilar e executar os testes básicos de cada estrutura de dados, siga os passos:

1. Clone este repositório:
    ```bash
    git clone https://github.com/Nhoid/DataStructC
    ```

2. Navegue até a pasta da estrutura de dados desejada:
    ```bash
    cd DataStructC/LinkedList
    ```

3. Compile o programa utilizando o `Makefile`:
    ```bash
    make
    ```

4. Execute o arquivo gerado na pasta `bin`:
    ```bash
    ./bin/main
    ```

> Repita os passos acima para qualquer outra estrutura (como Queue, Deque, Stack, BinaryTree, etc).
