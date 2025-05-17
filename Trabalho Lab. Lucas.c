#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char Clientes[10][50];
char Produtos[10][50];
char Vendas[10][50];

void insere_cliente(){
    for(int i = 0; i < 10; i++){
        if(strlen(Clientes[i]) == 0){
            printf("Informe o nome do cliente: \n");
            scanf("%s", Clientes[i]);
            break;
        }
    }
}

void listar_clientes(){
    for(int i = 0; i < 10; i++){
        if(strlen(Clientes[i]) > 0){
            printf("%s\n", Clientes[i]);
        }
    }
}

void excluir_cliente(){
    char nome[50];
    int i;
    printf("Qual cliente deseja excluir?\n");
    scanf("%s", nome);

    for(i = 0; i < 10; i++){
        if(strcmp(Clientes[i], nome) == 0){
            strcpy(Clientes[i], "");
            printf("Cliente excluído com sucesso.\n");
            return;
        }
    }

    printf("Cliente não encontrado.\n");
}

void insere_produtos(){
    for(int i = 0; i < 10; i++){
        if(strlen(Produtos[i]) == 0){
            printf("Informe o nome do produto: \n");
            scanf("%s", Produtos[i]);
            break;
        }
    }
}

void listar_produtos(){
    for(int i = 0; i < 10; i++){
        if(strlen(Produtos[i]) > 0){
            printf("%s\n", Produtos[i]);
        }
    }
}

void excluir_produto(){
    char nome_do_produto[50];
    int i;
    printf("Qual produto deseja excluir?\n");
    scanf("%s", nome_do_produto);

    for(i = 0; i < 10; i++){
        if(strcmp(Produtos[i], nome_do_produto) == 0){
            strcpy(Produtos[i], "");
            printf("Produto excluído com sucesso.\n");
            return;
        }
    }

    printf("Produto não encontrado.\n");
}
void inserir_venda(){
     for(int i = 0; i < 10; i++){
        if(strlen(Vendas[i]) == 0){
            printf("Informe a venda: \n");
            scanf("%s", Vendas[i]);
            break;
        }
    }
}
void listar_vendas(){
    for(int i = 0; i < 10; i++){
        if(strlen(Vendas[i]) > 0){
        scanf("%s\n", Vendas[i]);
        break;
        }
    }
}

int main(){
   int opc;

   do{
     printf("\nMENU\n\n");
     printf("1. Inserir Clientes\n");
     printf("2. Listar Clientes\n");
     printf("3. Excluir Cliente\n");
     printf("4. Inserir Produto\n");
     printf("5. Listar Produto\n");
     printf("6. Excluir Produto\n");
     printf("7. Inserir Vendas\n");
     printf("8. Listar Vendas\n");
     printf("9. Sair\n");
     scanf("%d", &opc);

     switch(opc){
        case 1:
            insere_cliente();
            break;
        case 2:
            listar_clientes();
            break;
        case 3:
            excluir_cliente();
            break;
        case 4:
            insere_produtos();
            break;
        case 5:
            listar_produtos();
            break;
        case 6:
            excluir_produto();
            break;
        case 7:
            inserir_venda();
            break;
        case 8:
            listar_vendas();
            break;
        case 9:
            printf("Até logo!\n");
            break;
        default:
            printf("Valor incorreto! Por favor, informe outro\n");
     }

   }while(opc != 7);

   return 0;
}
