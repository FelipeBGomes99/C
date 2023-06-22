# Alocação Dinâmica em Linguagem C

   A alocação dinâmica de memória é uma técnica importante em linguagem C, que permite reservar e liberar memória durante a execução de um programa. Ao contrário da alocação estática, em que a quantidade de memória é determinada em tempo de compilação, a alocação dinâmica permite ajustar a quantidade de memória conforme necessário durante a execução do programa.

   A alocação dinâmica de memória em linguagem C pode ser feita tanto por referência quanto por valor. A diferença fundamental entre esses dois métodos está relacionada à forma como os ponteiros são passados e manipulados.


## Alocação Dinâmica por Referência:

   - Nesse método, a função recebe um ponteiro para um ponteiro (duplo ponteiro) como parâmetro.
   - A função é responsável por alocar a memória dinamicamente e atribuir o endereço da memória alocada ao ponteiro recebido por referência.
   - Após a execução da função, o ponteiro original, passado como argumento, apontará para a memória alocada.
   - Qualquer alteração feita no ponteiro dentro da função afetará diretamente o ponteiro original fora da função.


## Alocação Dinâmica por Valor:

   - Nesse método, a função recebe um ponteiro simples (valor do ponteiro) como parâmetro.
   - A função é responsável por alocar a memória dinamicamente e retorna o endereço da memória alocada.
   - Após a execução da função, é necessário atribuir explicitamente o retorno da função ao ponteiro original fora da função.
  
 
Em resumo, a alocação dinâmica por referência permite modificar o ponteiro original diretamente dentro da função, enquanto a alocação dinâmica por valor requer a atribuição explícita do retorno da função ao ponteiro original fora da função.
   
