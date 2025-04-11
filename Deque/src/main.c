#include <stdio.h>
#include "deque.h"


int main(){
	// Cria o deque
    Deque* deque = builder();
    printf("Deque criado\n");

    // Adiciona elementos ao deque
    addFirst(deque, buildNode("Primeiro"));
    printf("Adicionado na primeira posição: Primeiro\n");

    addLast(deque, buildNode("Último"));
    printf("Adicionado na última posição: Último\n");

    addFirst(deque, buildNode("Novo Primeiro"));
    printf("Adicionado na primeira posição: Novo Primeiro\n");

    // Verifica o tamanho do deque
    printf("Tamanho do deque: %d\n", size(deque));

    // Verifica se o deque está vazio
    printf("Deque está vazio? %s\n", isEmpty(deque) ? "Sim" : "Não");

    // Obtém e imprime o primeiro e o último elementos
    Node* first = getFirst(deque);
    printf("Primeiro elemento: %s\n", first->element.text);

    Node* last = getLast(deque);
    printf("Último elemento: %s\n", last->element.text);

    // Remove e imprime o primeiro e o último elementos
    Node* removedFirst = removeFirst(deque);
    printf("Removido o primeiro elemento: %s\n", removedFirst->element.text);
    Delete(removedFirst);

    Node* removedLast = removeLast(deque);
    printf("Removido o último elemento: %s\n", removedLast->element.text);
    Delete(removedLast);

    // Verifica o tamanho do deque novamente
    printf("Tamanho do deque após remoções: %d\n", size(deque));

    deleteDeque(deque);


    return 0;
}