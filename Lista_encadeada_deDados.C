#include <stdio.h>
#include <stdlib.h> 

struct Node {
    int data;             
    struct Node* next;    
};

//FunÃ§Ã£o para criar um nó!! 
struct Node* criarNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); 
    newNode->data = value;    
    newNode->next = NULL;     
    return newNode;
}           

//Inserir um novo nó no ini­cio da lista!!
void inserirNoInicio(struct Node** head, int value) {
    struct Node* newNode = criarNode(value); 
    newNode->next = *head;
    *head = newNode;      
}

//Imprimir todos os valores da lista!!
void imprimirLista(struct Node* head) {
    struct Node* temp = head; 
    while (temp != NULL) {    
        printf("%d -> ", temp->data); 
        temp = temp->next; 
    }
    printf("NULL\n"); 
}

//Buscar um nó na lista!!
struct Node* buscar(struct Node* head, int value) {
    struct Node* temp = head;
    while (temp != NULL) {    
        if (temp->data == value) { 
            return temp;
        }
        temp = temp->next; 
    }
    return NULL; 
}

// Função para remover um nó da lista!!
void remover(struct Node** head, int value) {
    struct Node* temp = *head;      
    struct Node* anterior = NULL;  

    if (temp != NULL && temp->data == value) {
        *head = temp->next;  
        free(temp);        
        return;
    }
    
    while (temp != NULL && temp->data != value) {
        anterior = temp;   
        temp = temp->next; 
    }

    if (temp == NULL) return;
    anterior->next = temp->next; 
    free(temp);                  
}

// Função para teste da lista!!
int main() {
    struct Node* head = NULL;
    int escolha, valor;

    do {
        printf("\n--- Menu ---\n");
        printf("1. Inserir valor no inicio\n");
        printf("2. Remover valor\n");
        printf("3. Imprimir lista\n");
        printf("4. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &escolha);

        switch (escolha) {
            case 1:
                printf("Digite um valor para inserir: ");
                scanf("%d", &valor);
                inserirNoInicio(&head, valor);
                break;

            case 2:
                printf("Digite um valor para remover: ");
                scanf("%d", &valor);
                remover(&head, valor);
                break;

            case 3:
                printf("Lista atual: ");
                imprimirLista(head);
                break;

            case 4:
                printf("Saindo...\n");
                break;

            default:
                printf("Opcao invalida! Tente novamente.\n");
        }
    } while (escolha != 4);

    return 0;
}