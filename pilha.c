#include <stdio.h>
#include <stdlib.h>
 
// Pilha -> LIFO (Last In First Out)
// O último a entrar é o primeiro a sair. (LIFO)
 
// Definição da estrutura de um nó da pilha
struct No {
    int valor;             // Valor armazenado no nó
    struct No *proximo;    // Ponteiro para o próximo nó
};
 
// Função para empilhar um valor na pilha
void empilhar(struct No **topo, int valor) {
    struct No *novoNo = (struct No *)malloc(sizeof(struct No)); // Aloca memória para o novo nó
    novoNo->valor = valor;                                      // Atribui o valor ao novo nó
    novoNo->proximo = *topo;                                    // Define o próximo nó como o nó atual do topo
    *topo = novoNo;                                             // Atualiza o topo para o novo nó
}
 
// Função para imprimir todos os elementos da pilha
void imprimirPilha(struct No *topo) {
    struct No *atual = topo;                                    // Inicia a partir do topo da pilha
    printf("\nElementos da pilha:\n");
    while (atual != NULL) {                                     // Itera através da pilha
        printf("%d ", atual->valor);                            // Imprime o valor do nó atual
        atual = atual->proximo;                                 // Avança para o próximo nó
    }
    printf("\n");
}
 
// Função para liberar a memória alocada pela pilha
void liberarPilha(struct No *topo) {
    struct No *atual = topo;                                    // Inicia a partir do topo da pilha
    struct No *prox;                                            // Ponteiro para armazenar o próximo nó
    while (atual != NULL) {                                     // Itera através da pilha
        prox = atual->proximo;                                  // Armazena o próximo nó
        free(atual);                                            // Libera a memória do nó atual
        atual = prox;                                           // Avança para o próximo nó
    }
}
 
// Função para desempilhar um valor da pilha
int desempilhar(struct No **topo) {
    if (*topo == NULL) {                                        // Verifica se a pilha está vazia
        printf("Pilha vazia\n");                                // Mensagem de erro se a pilha estiver vazia
        return -1;                                              // Retorna -1 para indicar erro
    } else {
        struct No *temp = *topo;                                // Armazena o nó do topo temporariamente
        int remover = temp->valor;                              // Armazena o valor a ser removido
        *topo = (*topo)->proximo;                               // Atualiza o topo para o próximo nó
        free(temp);                                             // Libera a memória do nó removido
        return remover;                                         // Retorna o valor removido
    }
}
 
int main() {
    struct No *topo = NULL;                                     // Inicializa a pilha como vazia (topo NULL)
 
    // Empilha alguns valores
    empilhar(&topo, 1);
    empilhar(&topo, 2);
    empilhar(&topo, 3);
 
    // Imprime a pilha
    imprimirPilha(topo);
 
    // Desempilha um valor e imprime o valor removido
    int removido = desempilhar(&topo);
    printf("Removido: %d\n", removido);
 
    // Imprime a pilha após desempilhar
    imprimirPilha(topo);
 
    // Libera a memória alocada pela pilha
    liberarPilha(topo);
 
    return 0;
};