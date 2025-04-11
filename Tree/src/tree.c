#include "tree.h"
#include <stdlib.h>
#include <stdbool.h>

// builder
Tree* buildTree(int (*comparator)(void* element1, void* element2), Node* (*buildNode)(void* data), void (*freeNode)(Node* node)) {

	// verifica se as funcoes sao validas
	if (comparator == NULL || buildNode == NULL || freeNode == NULL) {
		return NULL;
	}

	// aloca memoria para um ponteiro de arvore
	// utilizei calloc para alocar memoria e inicializar com 0
	// caso queira mais desempenho, pode usar malloc
	Tree* tree = (Tree*) calloc(1, sizeof(Tree)); 

	// atribui as funcoes
	tree->comparator = comparator;
	tree->buildNode = buildNode;
	tree->freeNode = freeNode;

	tree->root = NULL;
	tree->size = 0;

	return tree;
}


// search
Node* searchElement(Tree* tree, void* element) {

    if (tree == NULL || element == NULL || tree->size == 0) {
        return NULL;
    }

    int walking = 2; // valor aleatorio diferente de -1, 0, 1

    Node* pointer = tree->root;

    while( walking != 0 && pointer != NULL ) {
    	switch (tree->comparator(pointer->element, element)) {
	        case 1:  // Elemento buscado é menor, busca no lado esquerdo
	            pointer = pointer->left;
	            break;
	        case -1: // Elemento buscado é maior, busca no lado direito
	            pointer = pointer->right;
	            break;
	        case 0: // Elemento encontrado
	        	walking = 0;
	        default: // Valor inválido retornado pelo comparador
	            break;
    	}
    }

    return pointer;
}

Node* searchNode(Tree* tree, Node* node) {
	return searchElement(tree, node->element);
}

Node* searchParent(Tree* tree, Node* node) {
    // Validação dos parâmetros
    if (tree == NULL || node == NULL || tree->size == 0) {
        return NULL;
    }

    // se o no procurado é a raiz
    if (tree->comparator(node->element, tree->root->element) == 0) {
    	return NULL;
    }

    Node* pointer = tree->root;    // Ponteiro para percorrer a árvore
    Node* reference = NULL;        // Ponteiro para manter referência ao pai

    while (pointer != NULL) {
        int comparison = tree->comparator(pointer->element, node->element);
        
        switch (comparison) {
            case 1:  // pointer > node, vai para esquerda
                reference = pointer;
                pointer = pointer->left;
                break;
            case -1: // pointer < node, vai para direita
                reference = pointer;
                pointer = pointer->right;
                break;
            case 0:  // Elemento encontrado
                return reference;
            default: // Comparador retornou valor inválido
				return NULL;
                break;
        }
    }

    return NULL; // Elemento não encontrado
}


Node* searchMinor(Tree* tree) {
	return searchMinorSubTree(tree->root);
}


Node* searchMajor(Tree* tree) {
	return searchMajorSubTree(tree->root);
}

Node* searchMinorSubTree(Node* node) {
	if (node == NULL) {
		return NULL;
	}

	Node* pointer = node;

	while (pointer->left != NULL) {
		pointer = pointer->left;
	}

	return pointer;
}

Node* searchMajorSubTree(Node* node) {
	if (node == NULL) {
		return NULL;
	}

	Node* pointer = node;

	while (pointer->right != NULL) {
		pointer = pointer->right;
	}

	return pointer;
}


// insert

int insertNode(Tree* tree, Node* node) {

	if (tree == NULL || node == NULL){ // verifica se os parametros sao validos
		return -1;
	}

	if (tree->size == 0){
		tree->root = node;
		tree->size++;
		return 0;
	}

	Node* pointer = searchParent(tree, node);

	// verifica se o no foi encontrado
	if ( pointer == NULL ) {
		pointer = tree->root;
	}

	// insere o no na arvore
	switch ( tree->comparator( pointer->element, node->element ) ) {
		case 1:
			pointer->left = node;
			break;
		case -1:
			pointer->right = node;
			break;
		case 0:
			return -2; // o elemento ja existe na arvore
		default:
			return -3; // o comparador retornou um valor invalido
	}

	tree->size++;

	return 0;
}

int insertElement(Tree* tree, void* element){
	return insertNode(tree, tree->buildNode(element));
}


// remove

int removeParent(Tree* tree, Node* node) { 
	if (tree == NULL || node == NULL || tree->size == 0 || (node->left == NULL && node->right == NULL)) {
		return -1; // parametro invalido
	}

	Node* pointer = searchMinorSubTree(node->right);

	if (pointer == NULL) {
		pointer = searchMajorSubTree(node->left);
	}

	node->element = pointer->element;

	return removeNode(tree, pointer);
}

int removeNode(Tree* tree, Node* node) {

	if (tree == NULL || node == NULL || tree->size == 0) {
		return -1; // parametro invalido
	}

	// tentando remover um no com filhos
	if (node->left != NULL || node->right != NULL 
		|| tree->comparator(node->element, tree->root->element) == 0) { 
		return removeParent(tree, node);
	}

	Node* parent = searchParent(tree, node);

	if ( parent == NULL ) {
		parent = tree->root;
	}

    // Remove o nó folha
    if (parent->left && tree->comparator(parent->left->element, node->element) == 0) {
        Node* toRemove = parent->left;
        parent->left = NULL;
        tree->freeNode(toRemove);
    } else if (parent->right && tree->comparator(parent->right->element, node->element) == 0) {
        Node* toRemove = parent->right;
        parent->right = NULL;
        tree->freeNode(toRemove);
    } else {
        return -3; // o no nao foi encontrado
    }

	tree->size--;
	return 0;
}

int removeElement(Tree* tree, void* element) {
	return removeNode(tree, tree->buildNode(element));
}

// balance
int balanceTree(Tree* tree);

// traversal
void traversalTreeInOrder(Tree* tree, void (*func)(Node* node)) {
	if (tree == NULL || func == NULL) {
		return;
		}

	traversalNodeInOrder(tree->root, func);
}

void traversalNodeInOrder(Node* node, void (*func)(Node* node)) {
	if (node == NULL) {
		return;
	}

}

void traversalTreePreOrder(Tree* tree, void (*func)(Node* node)) {
	if (tree == NULL || func == NULL) {
		return;
	}

}

void traversalNodePreOrder(Node* node, void (*func)(Node* node)) {
	if (node == NULL) {
		return;
	}

}

void traversalTreePostOrder(Tree* tree, void (*func)(Node* node)) {
	if (tree == NULL || func == NULL) {
		return;
	}

}


// free
void freeTree(Tree* tree);