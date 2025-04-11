
#include  <stdio.h>
#include "queue.h"



int main() {
    // Cria uma nova fila
    Queue* queue = builder();

    // Testa se a fila está vazia
    printf("A fila está vazia? %s\n", isEmpty(queue) ? "Sim" : "Não");

    // Adiciona elementos na fila
    enqueue(queue, buildNode("Primeiro"));
    printf("Elemento adicionado: Primeiro\n");
    enqueue(queue, buildNode("Segundo"));
    printf("Elemento adicionado: Segundo\n");
    enqueue(queue, buildNode("Terceiro"));
    printf("Elemento adicionado: Terceiro\n");

    // Verifica o tamanho da fila
    printf("Tamanho da fila: %d\n", size(queue));

    // Testa se a fila está vazia novamente
    printf("A fila está vazia? %s\n", isEmpty(queue) ? "Sim" : "Não");

    // Verifica o elemento na frente da fila sem removê-lo
    Node* frontNode = front(queue);
    printf("Elemento na frente da fila: %s\n", frontNode->element.text);

    while(queue->size > 0){
    	// Remove e retorna elementos da fila
	    Node* dequeuedNode = dequeue(queue);
	    printf("Elemento removido: %s\n", dequeuedNode->element.text);
    }

    // Verifica o tamanho da fila após remover elementos
    printf("Tamanho da fila: %d\n", size(queue));

    // Libera a memória da fila
    deleteQueue(queue);

    return 0;
}