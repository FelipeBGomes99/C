Introdução:

Operações em discos são executadas em entidades chamadas "arquivos".
Um arquivo é uma coleção de bytes referenciados por um nome único.
A linguagem C divide as categorias de acesso a disco em dois grupos: alto-nível e baixo-nível.
Arquivos em I/O - Alto-Nível:

Também conhecida como bufferizada, permite acessar arquivos de quatro modos diferentes:
Leitura e escrita de um caractere por vez.
Leitura e escrita de strings.
Leitura e escrita formatada.
Leitura e escrita de registros ou blocos, utilizados para armazenar matrizes e estruturas.
Arquivos em I/O - Baixo-Nível:

Também conhecida como não bufferizada, permite acessar arquivos de apenas um modo:
Os dados são lidos e escritos através de um buffer cheio de dados. O programador é responsável por criar e manter o buffer.
Texto X Binário:

Refere-se à forma como os arquivos são abertos e classifica o acesso a arquivos.
Modo Texto: o arquivo é interpretado como sequências de caracteres agrupados em linhas. Caracteres numéricos são armazenados como cadeias de caracteres.
Modo Binário: os dados são lidos e gravados sem alterações, sem indicação de fim de arquivo. Números são armazenados conforme estão na memória.
Operações com Arquivos em Disco - Alto-Nível:

Utiliza-se a biblioteca stdio.h.
É necessário declarar um ponteiro para o tipo FILE.
A função fopen() é usada para criar (abrir) um arquivo e retorna um ponteiro para FILE.
A função fclose() é utilizada para fechar um arquivo.
Leitura e Gravação - Modo Registro (Binário):

Usado para manipular dados complexos como matrizes e estruturas.
A função fread() é usada para ler informações do arquivo.
A função fwrite() é usada para gravar informações no arquivo.
Cabe ressaltar que o resumo fornecido é baseado no texto fornecido e pode não abranger todos os aspectos e detalhes relacionados às operações de entrada/saída de arquivos em linguagem C. É recomendado consultar a documentação oficial da linguagem C e explorar exemplos e tutoriais mais detalhados para obter um entendimento completo dessas operações.
