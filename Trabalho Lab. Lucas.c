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
    int estoque;
} Produto;

typedef struct {
    char cpf_cliente[15];
    int cod_produto;
    int quantidade;
} Venda;

typedef struct {
    char cpf_cliente[15];
    char forma[20]; // pix, dinheiro, boleto, cartao
} Pagamento;

Cliente clientes[MAX];
Produto produtos[MAX];
Venda vendas[MAX];
Pagamento pagamentos[MAX];

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
            scanf("%d", &produtos[i].codigo);
            printf("Estoque: ");
            scanf("%d", &produtos[i].estoque);
            getchar();
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
            printf("Produto: %s | Código: %d | Estoque: %d\n", produtos[i].nome, produtos[i].codigo, produtos[i].estoque);
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
            produtos[i].estoque = 0;
            printf("Produto excluído com sucesso.\n");
            return;
        }
    }
    printf("Produto não encontrado.\n");
}

void cadastrar_venda() {
    char cpf[15];
    int codigo, quantidade;

    printf("CPF do cliente: ");
    fgets(cpf, 15, stdin); limpar_linha(cpf);
    printf("Código do produto: ");
    scanf("%d", &codigo);
    printf("Quantidade: ");
    scanf("%d", &quantidade);
    getchar();

    int cliente_encontrado = 0, produto_index = -1;

    for (int i = 0; i < MAX; i++) {
        if (strcmp(clientes[i].cpf, cpf) == 0) cliente_encontrado = 1;
        if (produtos[i].codigo == codigo) produto_index = i;
    }

    if (!cliente_encontrado || produto_index == -1) {
        printf("Cliente ou produto não encontrado.\n");
        return;
    }

    if (produtos[produto_index].estoque < quantidade) {
        printf("Estoque insuficiente.\n");
        return;
    }

    char forma_pagamento[20];
    printf("Forma de pagamento (pix/dinheiro/boleto/cartao): ");
    fgets(forma_pagamento, 20, stdin); limpar_linha(forma_pagamento);

    for (int i = 0; i < MAX; i++) {
        if (vendas[i].cpf_cliente[0] == '\0') {
            strcpy(vendas[i].cpf_cliente, cpf);
            vendas[i].cod_produto = codigo;
            vendas[i].quantidade = quantidade;
            produtos[produto_index].estoque -= quantidade;
            strcpy(pagamentos[i].cpf_cliente, cpf);
            strcpy(pagamentos[i].forma, forma_pagamento);
            printf("Venda registrada com pagamento via %s!\n", forma_pagamento);
            return;
        }
    }

    printf("Limite de vendas atingido.\n");
}

void listar_vendas() {
    printf("\n--- Notas Fiscais ---\n");
    for (int i = 0; i < MAX; i++) {
        if (vendas[i].cpf_cliente[0] != '\0') {
            char nome_cliente[50] = "Desconhecido";
            char nome_produto[50] = "Desconhecido";

            for (int j = 0; j < MAX; j++) {
                if (strcmp(clientes[j].cpf, vendas[i].cpf_cliente) == 0)
                    strcpy(nome_cliente, clientes[j].nome);
                if (produtos[j].codigo == vendas[i].cod_produto)
                    strcpy(nome_produto, produtos[j].nome);
            }

            printf("Cliente: %s | CPF: %s | Produto: %s | Código: %d | Qtde: %d | Pagamento: %s\n",
                nome_cliente, vendas[i].cpf_cliente,
                nome_produto, vendas[i].cod_produto,
                vendas[i].quantidade, pagamentos[i].forma);
        }
    }
}

void alterar_cliente() {
    char cpf[15];
    printf("Digite o CPF do cliente a alterar: ");
    fgets(cpf, 15, stdin); limpar_linha(cpf);

    for (int i = 0; i < MAX; i++) {
        if (strcmp(clientes[i].cpf, cpf) == 0) {
            printf("Novo nome: ");
            fgets(clientes[i].nome, 50, stdin); limpar_linha(clientes[i].nome);
            printf("Nome alterado com sucesso.\n");
            return;
        }
    }
    printf("Cliente não encontrado.\n");
}

void alterar_produto() {
    int codigo;
    printf("Digite o código do produto a alterar: ");
    scanf("%d", &codigo); getchar();

    for (int i = 0; i < MAX; i++) {
        if (produtos[i].codigo == codigo) {
            printf("Novo nome do produto: ");
            fgets(produtos[i].nome, 50, stdin); limpar_linha(produtos[i].nome);
            printf("Produto alterado com sucesso.\n");
            return;
        }
    }
    printf("Produto não encontrado.\n");
}

void alterar_venda() {
    char cpf[15];
    int codigo;
    printf("Digite o CPF da venda: ");
    fgets(cpf, 15, stdin); limpar_linha(cpf);
    printf("Digite o código do produto da venda: ");
    scanf("%d", &codigo); getchar();

    for (int i = 0; i < MAX; i++) {
        if (strcmp(vendas[i].cpf_cliente, cpf) == 0 && vendas[i].cod_produto == codigo) {
            printf("Nova quantidade: ");
            int nova_quantidade;
            scanf("%d", &nova_quantidade); getchar();

            for (int j = 0; j < MAX; j++) {
                if (produtos[j].codigo == codigo) {
                    produtos[j].estoque += vendas[i].quantidade;
                    if (produtos[j].estoque < nova_quantidade) {
                        printf("Estoque insuficiente para alterar a venda.\n");
                        produtos[j].estoque -= vendas[i].quantidade;
                        return;
                    }
                    produtos[j].estoque -= nova_quantidade;
                    vendas[i].quantidade = nova_quantidade;
                    printf("Venda atualizada!\n");
                    return;
                }
            }
        }
    }
    printf("Venda não encontrada.\n");
}

void produto_mais_vendido() {
    int contagem[MAX] = {0};
    for (int i = 0; i < MAX; i++) {
        if (vendas[i].cpf_cliente[0] != '\0') {
            for (int j = 0; j < MAX; j++) {
                if (produtos[j].codigo == vendas[i].cod_produto)
                    contagem[j] += vendas[i].quantidade;
            }
        }
    }
    int max = -1, index = -1;
    for (int i = 0; i < MAX; i++) {
        if (contagem[i] > max) {
            max = contagem[i];
            index = i;
        }
    }
    if (index != -1)
        printf("Produto mais vendido: %s (Qtde: %d)\n", produtos[index].nome, max);
    else
        printf("Nenhuma venda realizada ainda.\n");
}

void cliente_que_mais_comprou() {
    int contagem[MAX] = {0};
    for (int i = 0; i < MAX; i++) {
        if (vendas[i].cpf_cliente[0] != '\0') {
            for (int j = 0; j < MAX; j++) {
                if (strcmp(clientes[j].cpf, vendas[i].cpf_cliente) == 0)
                    contagem[j] += vendas[i].quantidade;
            }
        }
    }
    int max = -1, index = -1;
    for (int i = 0; i < MAX; i++) {
        if (contagem[i] > max) {
            max = contagem[i];
            index = i;
        }
    }
    if (index != -1)
        printf("Cliente que mais comprou: %s (Qtde: %d)\n", clientes[index].nome, max);
    else
        printf("Nenhuma venda registrada ainda.\n");
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
        printf("9. Produto Mais Vendido\n");
        printf("10. Cliente que Mais Comprou\n");
        printf("11. Alterar Venda\n");
        printf("12. Alterar Cliente\n");
        printf("13. Alterar Produto\n");
        printf("14. Sair\n");
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
            case 9: produto_mais_vendido(); break;
            case 10: cliente_que_mais_comprou(); break;
            case 11: alterar_venda(); break;
            case 12: alterar_cliente(); break;
            case 13: alterar_produto(); break;
            case 14: printf("Obrigado, até mais!\n"); break;
            default: printf("Opção inválida.\n");
        }
    } while (opcao != 14);

    return 0;
}
        
