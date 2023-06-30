//Grupo 17 - Felipe Bernardes Gomes:223868 -- Carlos Eduardo Ferreira da Silva: 223748
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//struct produto
typedef struct produto{
int reg_prod;
char tipo[20];
char descricao[80];
float preco;
}produto;

//struct vendas
typedef struct venda{
int reg_venda;
char nome[80];
char CPF[15];
int reg_prod;
int qtde;
float preco;
float total;
char pago;
}venda;

// funcoes produtos
void aloca(produto **p, int tam);
void cadastro_produto(produto *p);
int verifica_produto();
void grava_produto(produto *p,char *str, int tam);
int busca_produto(produto *p,int tam);
void consulta_total(produto *p);
void consulta_parcial(produto *p, char *str);
void altera_preco(produto *p, int op);
void mostra(produto *p);
int busca (produto *p, int registro);

// funcoes  venda
void aloca_venda(venda **p, int tam);
int verifica_venda();
void grava_venda(venda *p);
void historico_venda(venda *p, produto *pp);
float busca_preco(produto *p, int reg_venda);
void consulta_pagamento(venda *p, char str);
void consulta_cpf(venda *p, char *str);

int main()
{
    int op;
    produto *pp = NULL;
    venda *pv = NULL;
    char tipo[20];
    char conf;
    char cpf[15];

    aloca(&pp,1);
    aloca_venda(&pv,1);

    do{
        system("cls");
        printf("Menu:\n[1]Cadastro\n[2]Consulta total\n[3]Consulta parcial\n[4]Altera preço\n[5]Deleta produto\n[6]Venda\n[7]Consulta pagamento\n[8]Consulta cliente\n[9]Sair\nOpcao:");
        scanf("%i", &op);
        fflush(stdin);

        switch(op)
        {
            case 1: cadastro_produto(pp);
                           printf("\nProduto cadastrado!!\n");
                           system("pause");
                           break;
            case 2: consulta_total(pp);
                           break;

            case 3: printf("Tipo do produto a ser consultado:");
                           gets(tipo);
                            consulta_parcial(pp,tipo);
                            break;
            case 4:

            case 5: altera_preco(pp, op);
                            break;

            case 6: historico_venda(pv, pp);
                            break;

            case 7: printf("pagamento realizado?[S] ou [N]: ");
                           scanf("%c", &conf);
                            consulta_pagamento(pv, conf);
                            break;

            case 8: printf("CPF do cliente: ");
                           gets(cpf);
                           consulta_cpf(pv, cpf);

        }
    }while(op != 9);

    return 0;
}//main

void aloca(produto **p, int tam)
{
    if((*p=(produto*)realloc(*p,tam*sizeof(produto)))==NULL)
        exit(1);
}//aloca

int verifica_produto()
{
    FILE *fpp = NULL;
    long int cont = 0;

    if((fpp= fopen("produtos.bin","rb"))==NULL){
    return cont;
    } else {
        fseek(fpp,0,2);
        cont = ftell(fpp)/sizeof(produto);
        fclose(fpp);
        return cont;
    }
} // verifica produto

void grava_produto(produto *p,char *str, int tam)
{
    FILE *fpp= NULL;

    if((fpp= fopen("produtos.bin",str))==NULL){
         printf("\nERRO\n\n");
    } else{
        if(strcmp(str,"rb+")==0){
            fseek(fpp,tam*sizeof(produto),0);
        }
        fwrite(p,sizeof(produto), 1, fpp);
    }
    fclose(fpp);
}//grava_produto

int busca_produto(produto *p,int tam)
{
    FILE *fpp = NULL;
    int find= -1, cont;

    system("cls");
    if((fpp=fopen("produtos.bin", "rb"))==NULL)
        return find;
    else{
        for(cont=0;cont<tam;cont++)
        {
            fseek(fpp,cont*sizeof(produto), 0);
            fread(p,sizeof(produto),1,fpp);
            if(p->preco== -1){
                find = cont;
                cont = tam;
            }
        }
        fclose(fpp);
        return find;
    }
}//busca produto

void cadastro_produto(produto *p)
{
    int qreg, indice;
    qreg = verifica_produto();
    indice = busca_produto(p,qreg);
    if(indice != -1)
        qreg = indice;
    p->reg_prod = qreg+1;
    printf("Registro: %i", p->reg_prod);
    printf("\nTipo do produto:");
    gets(p->tipo);
    fflush(stdin);
    printf("\nDescricao:");
    gets(p->descricao);
    fflush(stdin);
    printf("\nPreco:");
    scanf("%f", &(p->preco));
    fflush(stdin);
    if(indice==-1)
        grava_produto(p,"ab",1);
    else
        grava_produto(p,"rb+",qreg);
}// cadastro_produto

void consulta_total(produto *p)
{
    int cont, qreg;
    FILE *fpp = NULL;
    qreg= verifica_produto();
    system("cls");
    if((fpp=fopen("produtos.bin", "rb"))==NULL)
        printf("Erro\n\n");
    else{
        for(cont=0;cont<qreg;cont++)
        {
            fseek(fpp,cont*sizeof(produto),0);
            fread(p, sizeof(produto),1,fpp);
            if(p->preco != -1)
                printf("\nRegistro: %i \nTipo: %s\nDescricao:%s\nPreco:%.2f\n\n",p->reg_prod,p->tipo,p->descricao,p->preco);
        }
        fclose(fpp);
    }
    system("pause");
}//consulta_total

void mostra(produto *p)
{
    int cont, qreg;
    FILE *fpp = NULL;
    qreg= verifica_produto();
    system("cls");
    if((fpp=fopen("produtos.bin", "rb"))==NULL)
        printf("Erro\n\n");
    else{
        for(cont=0;cont<qreg;cont++)
        {
            fseek(fpp,cont*sizeof(produto),0);
            fread(p, sizeof(produto),1,fpp);
            printf("\nRegistro: %i \nTipo: %s\nDescricao:%s\nPreco:%.2f\n\n",p->reg_prod,p->tipo,p->descricao,p->preco);
        }
        fclose(fpp);
    }
    system("pause");
}//mostra

void altera_preco(produto *p, int op)
{
    int registro, pos;
    mostra(p);
    printf("\nRegistro a ser alterado/deletado: ");
    scanf("%i", &registro);
    fflush(stdin);
    pos=busca(p, registro);
    if(pos==-1)
        printf("\nRegistro não existe\n\n");
    else
    {
        printf("Registro: %i\n Tipo: %s\n Descricao: %s\n Preco: %.2f\n\n", p->reg_prod,p->tipo, p->descricao,p->preco);
        if(op==4)
        {
            printf("Novo Preco:");
            scanf("%f", &(p->preco));
            fflush(stdin);
        }
        else
            p->preco=-1;
            grava_produto(p, "rb+", pos);
            printf("\nProduto deletado!\n\n");
            system("pause");
    }
}//altera e deleta

int busca (produto *p, int registro)
{
    FILE *fpp = NULL;
    int qreg, find= -1, cont;
    qreg = verifica_produto();


    system("cls");
    if((fpp=fopen("produtos.bin", "rb"))==NULL)
        printf("Erro\n\n");
    else{
        for(cont=0;cont<qreg;cont++)
        {
            fseek(fpp,cont*sizeof(produto), 0);
            fread(p,sizeof(produto),1,fpp);
            if(p->reg_prod==registro){
                find = cont;
                cont = qreg;
            }
        }
        fclose(fpp);
    }
        return find;
}//busca

void consulta_parcial(produto *p, char *str)
{
    int cont, qreg;
    FILE *fpp = NULL;
    qreg= verifica_produto();
    system("cls");
    if((fpp=fopen("produtos.bin", "rb"))==NULL)
        printf("Erro\n\n");
    else{
        for(cont=0;cont<qreg;cont++)
        {
            fseek(fpp,cont*sizeof(produto),0);
            fread(p, sizeof(produto),1,fpp);
            if(p->preco != -1 && strcmp(str,p->tipo)==0)
                printf("\nRegistro: %i \nTipo: %s\nDescricao:%s\nPreco:%.2f\n\n",p->reg_prod,p->tipo,p->descricao,p->preco);
        }
        fclose(fpp);
    }
    system("pause");
}
//
// funcoes vendas
void aloca_venda(venda **p, int tam)
{
    if((*p=(venda*)realloc(*p,tam*sizeof(venda)))==NULL)
        exit(1);
}//aloca venda

int verifica_venda()
{
    FILE *fpv = NULL;
    long int cont = 0;

    if((fpv= fopen("vendas.bin","rb"))==NULL){
    return cont;
    } else {
        fseek(fpv,0,2);
        cont = ftell(fpv)/sizeof(venda);
        fclose(fpv);
        return cont;
    }
} // verifica venda

void grava_venda(venda *p)
{
    FILE *fpv= NULL;

    if((fpv= fopen("vendas.bin","ab"))==NULL){
         printf("\nERRO\n\n");
    }else{
        fwrite(p,sizeof(venda), 1, fpv);
    }
    fclose(fpv);
}//grava venda

void historico_venda(venda *p, produto *pp)
{
    //int prod =0;
    int qtd = 0;
    int registro_p;
    qtd = verifica_venda();
    p->reg_venda = qtd+1;
    printf("\nVenda %i\n", p->reg_venda);
    printf("Nome do cliente: ");
    gets(p->nome);
    fflush(stdin);
    printf("CPF: ");
    gets(p->CPF);
    fflush(stdin);
    printf("registro do produto: ");
    scanf("%i", &p->reg_prod);
    printf("Quantidade vendida: ");
    scanf("%i", &p->qtde);
    fflush(stdin);
    p->preco = busca_preco(pp, p->reg_prod);
    p->total = p->preco*p->qtde;
    fflush(stdin);
    p->pago = 'N';
    if(p->total > 0){
        printf("\nPreço unitario: %.2f\n", p->preco);
        printf("\nValor a pagar: %.2f\n", p->total);
        printf("pagamento: %c\n", p->pago);
        grava_venda(p);
    }else{
        printf("Produto indisponivel.\n");
    }
    system("pause");

}//historico venda

float busca_preco(produto *p, int reg_venda)
{
    FILE *fpp = NULL;
    int qreg;
    int cont;
    float find = 0;
    qreg = verifica_produto();

    system("cls");
    if((fpp=fopen("produtos.bin", "rb"))==NULL)
        printf("Erro\n\n");
    else{
        for( cont=0;cont<qreg;cont++)
        {
            fseek(fpp,cont*sizeof(produto), 0);
            fread(p,sizeof(produto),1,fpp);

            if(p->reg_prod==reg_venda){
                if(p->preco > 0){
                find = p->preco;
                cont = qreg;
                }
            }
        }
        fclose(fpp);
    }
        return find;
}// busca preco

void consulta_pagamento(venda *p, char str)
{
   int cont, qreg;
    FILE *fpv = NULL;
    qreg= verifica_venda();
    system("cls");
    if((fpv=fopen("vendas.bin", "rb"))==NULL)
        printf("Erro\n\n");
    else{
        for(cont=0;cont<qreg;cont++)
        {
            fseek(fpv,cont*sizeof(venda),0);
            fread(p, sizeof(venda),1,fpv);
            if(p->pago == str)
                printf("\nRegistro de venda: %i \nNome: %s\nCPF:%s\nRegistro do produto:%i\nQuantidade: %i\nPreco: %.2f\nTotal: %.2f\n",p->reg_venda,p->nome,p->CPF,p->reg_prod,p->qtde,p->preco, p->total);
        }
        fclose(fpv);
    }
    system("pause");
}//consulta pagamento

void consulta_cpf(venda *p, char *str)
{
     int cont, qreg;
    FILE *fpv = NULL;
    qreg= verifica_venda();
    system("cls");
    if((fpv=fopen("vendas.bin", "rb"))==NULL)
        printf("Erro\n\n");
    else{
        for(cont=0;cont<qreg;cont++)
        {
            fseek(fpv,cont*sizeof(venda),0);
            fread(p, sizeof(venda),1,fpv);
            if(strcmp(str,p->CPF)==0)
                 printf("\nRegistro de venda: %i \nNome: %s\nRegistro do produto:%i\nQuantidade: %i\nPreco: %.2f\nTotal: %.2f\n\nPago: %c",p->reg_venda,p->nome,p->reg_prod,p->qtde,p->preco, p->total, p->pago);
        }
        fclose(fpv);
    }
    system("pause");
}// consulta cpf





