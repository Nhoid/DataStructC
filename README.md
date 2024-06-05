# Estruturas de Dados Básicas

Este repositório foi criado para fins de aprendizado, com base no livro *Estruturas de Dados & Algoritmos em Java* de Michael T. Goodrich e Roberto Tamassia. As implementações são feitas em C para reforçar os conceitos estudados.

Cada estrutura de dados está organizada em pastas individuais com seu respectivo nome e contém arquivos `.h`, `.c` e um `main.c` com testes básicos das funcionalidades implementadas. Além disso, cada pasta possui um `Makefile` para facilitar a compilação.

## Estruturas Implementadas

- [x] LinkedList (Lista Ligada)
- [x] Queue (Fila)
- [x] Deque (Deque)
- [x] Stack (Pilha)

## Estrutura do Repositório

O repositório está organizado da seguinte forma:

- **LinkedList/**
  - `LinkedList.h`
  - `LinkedList.c`
  - `main.c`
  - `Makefile`
- **Queue/**
  - `Queue.h`
  - `Queue.c`
  - `main.c`
  - `Makefile`
- **Deque/**
  - `Deque.h`
  - `Deque.c`
  - `main.c`
  - `Makefile`
- **Stack/**
  - `Stack.h`
  - `Stack.c`
  - `main.c`
  - `Makefile`

## Como Executar

Para compilar e executar os testes básicos de cada estrutura de dados, siga as instruções abaixo. Cada estrutura possui seu próprio `Makefile` que facilita a compilação.

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

4. Execute o arquivo gerado:
    ```bash
    ./main
    ```
