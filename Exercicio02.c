#include <stdlib.h>
#include <stdio.h>
#define MAX 128

struct Node{
	int info;
	struct Node *prox;
};
typedef struct Node node;

int tam;

int menu(void);
void inicia(node *stack);
int opcao(node* stack, int prod);
void exibe(node *stack);
void libera(node *stack);
void push(node* stack);
node *pop(node *stack);
void *not_pol_soma(node *stack);

int main(){
	node *PILHA = (node *) malloc(sizeof(node));
	if(!PILHA){
		printf("Sem memoria disponivel!\n");
		exit(1);
	}else{
		inicia(PILHA);
		int opt;

		do{
			opt=menu();
			opcao(PILHA,opt);
		}while(opt);

	free(PILHA);
	return 0;
	}
}

int menu(void)
{
	int opt;
	
	printf("Escolha a opcao \n");
	printf("0. Sair \n");
	printf("1. Zerar PILHA \n");
	printf("2. Exibir PILHA \n");
	printf("3. PUSH \n");
	printf("4. POP \n");
	printf("5. Notacao Polonesa Soma \n");
	printf("Opcao: "); scanf("%d", &opt);
	
	return opt;
}


int opcao(node* stack, int prod){
	node* tmp;
	switch(prod){
		case(0):
			return 0;
			break;
			
		case(1):
			libera(stack);
			inicia(stack);
			break;

		case(2):
			exibe(stack);
			break;
		
		case(3):
			push(stack);
			break;
		
		case(4):
			tmp = pop(stack);
			if(tmp != NULL)
			printf("Retirado: %3d\n\n", tmp->info);
			break;
			
		case(5):
			not_pol_soma(stack);
			break;
		
		default:
			printf("Errou burrao \n");
			break;
		
	}
}

void inicia(node *pilha){
	pilha->prox = NULL;
	tam = 0;
}

int vazia(node *stack){
	if(stack->prox == NULL)
		return 1;
	else
		return 0;
}


node* aloca(){
	node *novo;
	novo = (node*) malloc(sizeof(node));
	
	if(!novo){
		printf("Sem Memoria. \n");
		exit(1);
	}else{
		printf("Novo elemento: ");
		scanf("%d", &novo->info);
		return novo;
	}
}

void exibe(node *stack){
	if(vazia(stack)){
		printf("Pilha esta vazia!\n\n");
		return;
	}
	node *tmp;
	tmp = stack->prox;
	printf("Pilha:");
	while( tmp != NULL){
		printf("%5d", tmp->info);
		tmp = tmp->prox;
	}
	printf("\n        ");
	int count;
	for(count=0 ; count < tam ; count++)
		printf("  ^  ");
	printf("\nOrdem:");
	for(count=0 ; count < tam ; count++)
		printf("%5d", count+1);
	
	printf("\n\n");
}

void libera(node *stack){
	if(!vazia(stack)){
		node *proxNode;
		node *atual;
	
		atual = stack->prox;
		
		while(atual != NULL){
			proxNode = atual->prox;
			free(atual);
			atual = proxNode;
		}
		
	}
}

void push(node* stack){
	
	node* novo;
	novo = aloca();
	
	novo->prox = NULL;
	
	if(vazia(stack)){
		stack->prox = novo;
	}else{
		node* tmp;
		tmp = stack->prox;
		
		while(tmp->prox != NULL){
			tmp = tmp->prox;
		}
		
		tmp->prox = novo;
	}
	tam++;	
}

node *pop(node *stack){
	if(vazia(stack)){
		printf("Pilha esta vazia!\n\n");
		return;
	}else{
		node *ultimo;
		ultimo = stack->prox;
		node* penultimo;
		penultimo = stack;
		
		while(ultimo->prox != NULL){
			penultimo = ultimo;
			ultimo = ultimo->prox;
		}
		
		penultimo->prox = NULL;
		tam--;
		return ultimo;
	}
}

void *not_pol_soma(node *stack){	
	node* ultimo = pop(stack);
	node* penultimo = pop(stack);
	
	node* soma;
	soma = (node*)malloc(sizeof(node));
	
	soma->info = ultimo->info + penultimo->info;
		
	if(vazia(soma)){
		stack->prox = soma;
	}else{
		node* tmp;
		tmp = stack->prox;
		
		while(tmp->prox != NULL){
			tmp = tmp->prox;
		}
		
		tmp->prox = soma;
	}
	
}














