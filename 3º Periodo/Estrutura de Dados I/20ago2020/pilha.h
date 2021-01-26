typedef struct pilha Pilha;


Pilha* criar_pilha();
void remover_todos(Pilha* pilha);
int empilhar(Pilha* pilha, int valor);
int desempilhar(Pilha* pilha);
int topo(Pilha* pilha);
int pilha_vazia(Pilha* pilha);

//Função de debug - evitar usar
void mostrar_pilha(Pilha* pilha);