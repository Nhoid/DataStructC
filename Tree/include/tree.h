#ifndef TREE_H
#define TREE_H

/**
 * Este arquivo define uma estrutura genérica de árvore binária, que pode armazenar 
 * qualquer tipo de dado. O desenvolvedor deve fornecer funções para operações específicas:
 * 
 * - `comparator`: Função para comparar dois elementos. Retorna:
 *      -1 se element1 < element2,
 *       0 se element1 == element2,
 *       1 se element1 > element2.
 * - `buildNode`: Função para criar um nó a partir de um dado.
 * - `freeNode`: Função para liberar a memória associada ao elemento do nó.
 */

typedef struct Node Node;

/**
 * Estrutura que representa um nó da árvore.
 */
struct Node {
    void* element;  // Ponteiro genérico para o elemento armazenado no nó.
    Node* left;     // Ponteiro para o nó filho à esquerda.
    Node* right;    // Ponteiro para o nó filho à direita.
};

/**
 * Estrutura que representa a árvore genérica.
 */
typedef struct {
    Node* root;  // Ponteiro para a raiz da árvore.
    int size;    // Número de nós na árvore.

    // Função para comparar dois elementos.
    int (*comparator)(void* element1, void* element2);

    // Função para criar um nó a partir de um dado.
    Node* (*buildNode)(void* data);

    // Função para liberar a memória associada ao nó.
    void (*freeNode)(Node* node);
} Tree;

/**
 * Cria uma nova árvore genérica.
 * 
 * @param comparator Função para comparar dois elementos.
 * @param buildNode Função para criar um nó a partir de um dado.
 * @param freeNode Função para liberar a memória associada ao nó.
 * @return Ponteiro para a estrutura `Tree` criada.
 */
Tree* buildTree(int (*comparator)(void* element1, void* element2), Node* (*buildNode)(void* data), void (*freeNode)(Node* node));

/**
 * Procura um nó na árvore com base em um elemento.
 * 
 * @param tree Ponteiro para a árvore.
 * @param element Ponteiro para o elemento a ser procurado.
 * @return Ponteiro para o nó encontrado, ou NULL se não encontrado.
 */
Node* searchElement(Tree* tree, void* element);

/**
 * Procura um nó na árvore com base em um nó.
 * 
 * @param tree Ponteiro para a árvore.
 * @param node Ponteiro para o nó a ser procurado.
 * @return Ponteiro para o nó encontrado, ou NULL se não encontrado.
 */
Node* searchNode(Tree* tree, Node* node);

/**
 * Busca e retorna o nó pai de um elemento na árvore
 * 
 * @param tree  Ponteiro para a árvore onde será feita a busca
 * @param node  Ponteiro para o nó que contém o elemento a ser procurado
 * @return      Ponteiro para o nó pai do elemento procurado, ou NULL se não encontrado
 */
Node* searchParent(Tree* tree, Node* node);

/**
 * Procura o menor elemento da árvore.
 * 
 * @param tree Ponteiro para a árvore.
 * @return Ponteiro para o menor elemento da árvore.
 */
Node* searchMinor(Tree* tree);

/**
 * Procura o maior elemento da árvore.
 * 
 * @param tree Ponteiro para a árvore.
 * @return Ponteiro para o maior elemento da árvore.
 */
Node* searchMajor(Tree* tree);

/**
 * Procura o menor elemento de um subárvore.
 * 
 * @param node Ponteiro para o nó raiz da subárvore.
 * @return Ponteiro para o menor elemento da subárvore.
 */
Node* searchMinorSubTree(Node* node);

/**
 * Procura o maior elemento de um subárvore.
 * 
 * @param node Ponteiro para o nó raiz da subárvore.
 * @return Ponteiro para o maior elemento da subárvore.
 */
Node* searchMajorSubTree(Node* node);

/**
 * Insere um nó na árvore.
 * 
 * @param tree  Ponteiro para a árvore
 * @param node  Ponteiro para o nó a ser inserido
 * @return      0 em caso de sucesso
 *             -1 se tree ou node forem NULL
 *             -2 se elemento já existe na árvore
 */
int insertNode(Tree* tree, Node* node);

/**
 * Insere um elemento na árvore.
 * 
 * @param tree     Ponteiro para a árvore
 * @param element  Ponteiro para o elemento a ser inserido
 * @return         0 em caso de sucesso
 *                -1 se tree ou element forem NULL
 *                -2 se elemento já existe na árvore
 */
int insertElement(Tree* tree, void* element);

/**
 * Remove um nó da árvore.
 * 
 * @param tree  Ponteiro para a árvore
 * @param node  Ponteiro para o nó a ser removido
 * @return      0 em caso de sucesso
 *             -1 se tree ou node forem NULL
 *             -2 se o nó não foi encontrado na árvore
 *             -3 se houve erro na remoção do nó
 */
int removeNode(Tree* tree, Node* node);

/**
 * Remove um elemento da árvore.
 * 
 * @param tree     Ponteiro para a árvore
 * @param element  Ponteiro para o elemento a ser removido
 * @return         0 em caso de sucesso
 *                -1 se tree ou element forem NULL
 *                -2 se o elemento não foi encontrado na árvore
 *                -3 se houve erro na remoção do elemento
 */
int removeElement(Tree* tree, void* element);

/**
 * Remove um nó que possui filhos, substituindo-o pelo seu sucessor.
 * 
 * @param tree  Ponteiro para a árvore
 * @param node  Ponteiro para o nó a ser removido
 * @return      0 em caso de sucesso
 *             -1 se tree ou node forem NULL
 *             -2 se o nó não possui filhos
 *             -3 se não foi possível encontrar um sucessor
 *             -4 se houve erro na remoção do sucessor
 */
int removeParent(Tree* tree, Node* node);

/**
 * Balanceia a árvore.
 * 
 * @param tree Ponteiro para a árvore.
 * @return 0 se a balanceamento foi bem-sucedido, -1 caso contrário.
 */
int balanceTree(Tree* tree);

/**
 * Executa uma função em todos os nós da árvore na ordem "in-order".
 * 
 * @param tree Ponteiro para a árvore.
 * @param func Função a ser executada em cada nó.
 */
void traversalTreeInOrder(Tree* tree, void (*func)(Node* node));

/**
 * Executa uma função em todos os nós da árvore na ordem "pré-order".
 * 
 * @param tree Ponteiro para a árvore.
 * @param func Função a ser executada em cada nó.
 */
void traversalTreePreOrder(Tree* tree, void (*func)(Node* node));

/**
 * Executa uma função em todos os nós da árvore na ordem "pós-order".
 * 
 * @param tree Ponteiro para a árvore.
 * @param func Função a ser executada em cada nó.
 */
void traversalTreePostOrder(Tree* tree, void (*func)(Node* node));

/**
 * Libera toda a memória associada à árvore.
 * 
 * @param tree Ponteiro para a árvore.
 */
void freeTree(Tree* tree);

#endif /* TREE_H */