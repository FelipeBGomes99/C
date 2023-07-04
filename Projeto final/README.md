# Projeto sistema de padaria

## 1ª etapa - Fazer menu e rotina para:
- Cadastro Produto: receber as informações do produto (abaixo) e guardar em
produtos.bin, verificar se há espaço vago no arquivo, se sim: gravar nesse
espaço, senão: adicionar no final do arquivo.Struct:

o Nº do registro do produto (nº gerado automaticamente pelo sistema).

o Tipo: receber o tipo do produto.

o Descrição: receber a descrição do produto.

o Preço: receber o preço do produto.

- Consulta Produto – 2 tipos de consulta:

o Total: mostrar o registro, tipo, descrição e preço de TODOS os produtos
válidos (que não estejam com preço = -1).

o Parcial: o acesso deve ser feito através do tipo, o usuário deverá entrar com
o tipo a ser mostrado. Mostrar o registro, descrição e preço dos produtos válidos do
tipo escolhido (que não estejam com preço = -1).

- Altera Preço: mostrar todos os produtos válidos. O acesso será feito através
do registro do produto, atualizar o preço e gravar.

- Deleta Produto: mostrar todos os produtos válidos. O acesso será feito através
do registro do produto, alterar o preço para -1 e gravar, dessa forma, deixará
espaço livre para o cadastro de outro produto.

### OBS.: alocar apenas 1 espaço de memória para a estrutura produto

