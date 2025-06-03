#include <stdio.h>
#include <string.h>

#define MAX 10

typedef struct {
    char nome[50];
    char cpf[15];
} Cliente;

typedef struct {
    char nome[50];
    int codigo;
} Produto;

typedef struct {
    char cpf_cliente[15];
    int cod_produto;
} Venda;

Cliente clientes[MAX];
Produto produtos[MAX];
Venda vendas[MAX];

void limpar_linha(char *linha) {
    linha[strcspn(linha, "\n")] = 0;
}

void inserir_cliente() {
    for (int i = 0; i < MAX; i++) {
        if (strlen(clientes[i].nome) == 0) {
            printf("Nome do cliente: ");
            fgets(clientes[i].nome, 50, stdin); limpar_linha(clientes[i].nome);
            printf("CPF: ");
            fgets(clientes[i].cpf, 15, stdin); limpar_linha(clientes[i].cpf);
            printf("Cliente cadastrado!\n");
            return;
        }
    }
    printf("Limite de clientes atingido.\n");
}

void listar_clientes() {
    printf("\n--- Clientes ---\n");
    for (int i = 0; i < MAX; i++) {
        if (strlen(clientes[i].nome) > 0)
            printf("Nome: %s | CPF: %s\n", clientes[i].nome, clientes[i].cpf);
    }
}

void excluir_cliente() {
    char cpf[15];
    printf("Digite o CPF do cliente a ser excluído: ");
    fgets(cpf, 15, stdin); limpar_linha(cpf);

    for (int i = 0; i < MAX; i++) {
        if (strcmp(clientes[i].cpf, cpf) == 0) {
            clientes[i].nome[0] = '\0';
            clientes[i].cpf[0] = '\0';
            printf("Cliente excluído com sucesso.\n");
            return;
        }
    }
    printf("Cliente não encontrado.\n");
}

void inserir_produto() {
    for (int i = 0; i < MAX; i++) {
        if (strlen(produtos[i].nome) == 0) {
            printf("Nome do produto: ");
            fgets(produtos[i].nome, 50, stdin); limpar_linha(produtos[i].nome);
            printf("Código: ");
            scanf("%d", &produtos[i].codigo); getchar();
            printf("Produto cadastrado!\n");
            return;
        }
    }
    printf("Limite de produtos atingido.\n");
}

void listar_produtos() {
    printf("\n--- Produtos ---\n");
    for (int i = 0; i < MAX; i++) {
        if (strlen(produtos[i].nome) > 0)
            printf("Produto: %s | Código: %d\n", produtos[i].nome, produtos[i].codigo);
    }
}

void excluir_produto() {
    int codigo;
    printf("Digite o código do produto a ser excluído: ");
    scanf("%d", &codigo); getchar();

    for (int i = 0; i < MAX; i++) {
        if (produtos[i].codigo == codigo && strlen(produtos[i].nome) > 0) {
            produtos[i].nome[0] = '\0';
            produtos[i].codigo = 0;
            printf("Produto excluído com sucesso.\n");
            return;
        }
    }
    printf("Produto não encontrado.\n");
}

void cadastrar_venda() {
    char cpf[15];
    int codigo;

    printf("CPF do cliente: ");
    fgets(cpf, 15, stdin); limpar_linha(cpf);
    printf("Código do produto: ");
    scanf("%d", &codigo); getchar();

    int cliente_encontrado = 0, produto_encontrado = 0;

    for (int i = 0; i < MAX; i++) {
        if (strcmp(clientes[i].cpf, cpf) == 0) cliente_encontrado = 1;
        if (produtos[i].codigo == codigo) produto_encontrado = 1;
    }

    if (cliente_encontrado && produto_encontrado) {
        for (int i = 0; i < MAX; i++) {
            if (vendas[i].cpf_cliente[0] == '\0') {
                strcpy(vendas[i].cpf_cliente, cpf);
                vendas[i].cod_produto = codigo;
                printf("Venda registrada!\n");
                return;
            }
        }
        printf("Limite de vendas atingido.\n");
    } else {
        printf("Cliente ou produto não encontrado.\n");
    }
}

void listar_vendas() {
    printf("\n--- Vendas ---\n");
    for (int i = 0; i < MAX; i++) {
        if (vendas[i].cpf_cliente[0] != '\0')
            printf("CPF Cliente: %s | Código Produto: %d\n", vendas[i].cpf_cliente, vendas[i].cod_produto);
    }
}

int main() {
    int opcao;

    do {
        printf("\n--- MENU ---\n");
        printf("1. Inserir Cliente\n");
        printf("2. Listar Clientes\n");
        printf("3. Inserir Produto\n");
        printf("4. Listar Produtos\n");
        printf("5. Cadastrar Venda\n");
        printf("6. Listar Vendas\n");
        printf("7. Excluir Cliente\n");
        printf("8. Excluir Produto\n");
        printf("9. Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao); getchar();

        switch (opcao) {
            case 1: inserir_cliente(); break;
            case 2: listar_clientes(); break;
            case 3: inserir_produto(); break;
            case 4: listar_produtos(); break;
            case 5: cadastrar_venda(); break;
            case 6: listar_vendas(); break;
            case 7: excluir_cliente(); break;
            case 8: excluir_produto(); break;
            case 9: printf("Obrigado, até mais!!\n"); break;
            default: printf("Opção inválida, digite um novo comando.\n");
        }
    } while (opcao != 9);

    return 0;
}
