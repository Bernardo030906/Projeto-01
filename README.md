TRABALHO DE SISTEMA DE VENDAS

Este é um sistema de vendas simples implementado em linguagem C, com funcionalidades de cadastro de clientes, produtos, vendas, controle de estoque, formas de pagamento e alterações de registros. O sistema usa estruturas (structs) e arrays fixos para armazenar os dados em memória.

✅ Funcionalidades

👤 Clientes

Inserção: Cadastro com nome e CPF.

Listagem: Lista todos os clientes cadastrados.

Exclusão: Remove um cliente com base no CPF.

Alteração: Permite alterar o nome de um cliente.

📦 Produtos

Inserção: Cadastro com nome, código numérico e estoque.

Listagem: Exibe todos os produtos cadastrados.

Exclusão: Remove um produto com base no código.

Alteração: Permite alterar o nome de um produto.

🧾 Vendas

Cadastro: Registra uma venda com CPF do cliente, código do produto, quantidade comprada e forma de pagamento.

Listagem: Exibe notas fiscais com cliente, produto, quantidade e forma de pagamento.

Alteração: Permite alterar a quantidade de uma venda, atualizando o estoque corretamente.

💳 Formas de Pagamento

As vendas registram a forma de pagamento escolhida entre:

pix

dinheiro

boleto

cartao

📊 Relatórios

Produto Mais Vendido: Informa qual produto teve o maior volume de vendas.

Cliente que Mais Comprou: Informa o cliente que mais comprou em quantidade total.

🧾 Organização do Código

Funções principais:

inserir_cliente() – Cadastra novo cliente.

listar_clientes() – Lista todos os clientes.

excluir_cliente() – Exclui cliente pelo CPF.

alterar_cliente() – Altera o nome de um cliente.

inserir_produto() – Cadastra novo produto.

listar_produtos() – Lista todos os produtos.

excluir_produto() – Exclui produto pelo código.

alterar_produto() – Altera o nome de um produto.

cadastrar_venda() – Registra uma venda com forma de pagamento.

listar_vendas() – Lista todas as vendas e pagamentos.

alterar_venda() – Altera a quantidade de uma venda existente.

produto_mais_vendido() – Relatório baseado em quantidade de vendas por produto.

cliente_que_mais_comprou() – Relatório baseado em quantidade total comprada por cliente.

🔢 Limites

Máximo de 10 clientes, 10 produtos e 10 vendas.

Dados armazenados em memória (RAM), não persistem após fechar o programa.

Cadastro e buscas são feitas por CPF (clientes) e código numérico (produtos).
