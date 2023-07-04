# Structs Usadas com Ponteiros em Linguagem C
   Este resumo aborda o uso de structs em conjunto com ponteiros na linguagem C. As structs são estruturas de dados que permitem agrupar diferentes tipos de dados relacionados em uma única entidade, facilitando a organização dos dados. O uso de ponteiros com structs proporciona flexibilidade e eficiência no acesso e manipulação desses dados.

Aqui estão algumas informações relevantes sobre o uso de structs com ponteiros em C:

## Definindo uma Struct:

struct Pessoa {

    char nome[50];
    
    int idade;
    
    float altura;
    
};

## Acessando os Membros da Struct

Para acessar os membros de uma struct por meio de um ponteiro, utilizamos o operador de seta (->):

printf("Nome: %s\n", pessoa->nome);

printf("Idade: %d\n", pessoa->idade);

printf("Altura: %.2f\n", pessoa->altura);

## Modificando os Membros da Struct

Podemos modificar os membros de uma struct através do ponteiro:

strcpy(pessoa->nome, "João");

pessoa->idade = 25;

pessoa->altura = 1.75;

##Liberando a Memória
Após utilizar uma struct alocada dinamicamente, é importante liberar a memória para evitar vazamentos de memória. Utilizamos a função "free()":

free(pessoa);

pessoa = NULL; // Opcional, mas uma boa prática

#### O uso de ponteiros com structs em C proporciona uma maneira flexível e eficiente de trabalhar com dados estruturados. É fundamental alocar e liberar memória corretamente para evitar vazamentos e problemas de gerenciamento de memória.









