# Projeto sistema de padaria

## 1ª etapa - Fazer menu e rotina para:
- Cadastro Produto: receber as informações do produto (abaixo) e guardar em
produtos.bin, verificar se há espaço vago no arquivo, se sim: gravar nesse
espaço, senão: adicionar no final do arquivo. Struct:

 Nº do registro do produto (nº gerado automaticamente pelo sistema).

 Tipo: receber o tipo do produto.

 Descrição: receber a descrição do produto.

 Preço: receber o preço do produto.

- Consulta Produto – 2 tipos de consulta:

 Total: mostrar o registro, tipo, descrição e preço de TODOS os produtos
válidos (que não estejam com preço = -1).

 Parcial: o acesso deve ser feito através do tipo, o usuário deverá entrar com
o tipo a ser mostrado. Mostrar o registro, descrição e preço dos produtos válidos do
tipo escolhido (que não estejam com preço = -1).

- Altera Preço: mostrar todos os produtos válidos. O acesso será feito através
do registro do produto, atualizar o preço e gravar.

- Deleta Produto: mostrar todos os produtos válidos. O acesso será feito através
do registro do produto, alterar o preço para -1 e gravar, dessa forma, deixará
espaço livre para o cadastro de outro produto.

### OBS.: alocar apenas 1 espaço de memória para a estrutura produto.

## 2ª etapa - Fazer menu e rotina para:
- Histórico Vendas: receber as informações da venda (abaixo) e guardar em
vendas.bin. Struct:
 Nº do registro da venda (nº inteiro gerado automaticamente pelo
sistema).

 Nome: receber o nome do cliente.

 CPF: receber o CPF do cliente.

 Registro do produto: receber o registro do produto a ser comprador pelo
cliente.

 Quantidade: receber a quantidade do produto a ser comprador pelo
cliente.

 Preço: deve-se buscar o preço no arquivo produtos.bin, de acordo com
o registro.

 Total: calcular o valor da venda (quantidade * preço).

 Pago: colocar [N]ão.

- Consulta Vendas – 2 tipos de consulta:
  
  Pagamento (S ou N). O acesso deve ser feito através da verificação do pagamento, o
usuário deverá entrar com a letra [S]im ou [N]ão para a variável
pago. Mostrar o registro da venda, o nome do cliente, CPF do cliente,
registro do produto, quantidade, preço e total de TODAS as vendas
efetuadas e que estiverem com o pagamento escolhido.

 CPF: O acesso deve ser feito através do CPF do cliente. Mostrar o registro da venda, o nome do cliente, registro do
produto, quantidade, preço, total e pagamento de TODAS as compras efetuadas pelo cliente (tanto as pagas como as em aberto).

### OBS.: alocar apenas 1 espaço de memória para a estrutura venda.

## 3ª etapa - Fazer menu e rotina para:

 - Pagamento:
 O acesso deve ser feito através do CPF do cliente.

 Mostrar o registro da venda, o nome do cliente, registro do produto,
quantidade, preço, total e status das compras efetuadas pelo cliente, cujo
status esteja como NÃO PAGO.

 O cliente deverá digitar o registro da venda que ele quer fazer o
pagamento.

 Realizar o pagamento e trocar o status de pagamento para [S]im
o atualizar o arquivo vendas.bin.

- Histórico de Clientes: cada vez que o cliente pagar uma conta, pegar as
informações do cliente (ver abaixo) e guardar em clientes.bin. Verificar
se o cliente já existe no arquivo (buscar por CPF), se sim: atualizar o valor
gasto, senão: adicionar no final do arquivo.

- Nº do registro do cliente (nº inteiro gerado automaticamente pelo
sistema). Struct:

 Nome: nome do cliente contido no arquivo vendas.bin.
 
 CPF: CPF do cliente contido no arquivo vendas.bin.
 
 Gasto: total gasto até o momento, se for a 1ª vez é o valor pago, se
não: deve-se somar o valor pago ao que já estava armazenado no
arquivo.

- Consulta do Histórico de Clientes:
o Mostrar registro do cliente,nome, CPF e total gasto até o momento.

### OBS.: alocar apenas 1 espaço de memória para a estrutura cliente.

