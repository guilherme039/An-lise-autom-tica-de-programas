#include <stdio.h>

int main()
{
    int n, m, i, indice1, indice2, aux = 1;
    char tipo;
 
    printf("Digite a quantidade de variaveis (n): ");
    scanf("%d", &n);
    printf("Digite a quantidade de restricoes (m): ");
    scanf("%d", &m);
    
    int variaveis[n];
    for(i = 0; i < n; i++) variaveis[i] = 0; // Preenchendo o vetor com zeros.

    for(i = 0; i < m; i++)
    {
        printf("Restricao de numero %d.\n", i + 1);

        printf("Digite o indice da primeira variavel: ");
        scanf("%d", &indice1);
        
        printf("Digite o indice da segunda variavel: ");
        scanf("%d", &indice2);

        printf("Digite o tipo da resticao (i ou d): ");
        scanf(" %c", &tipo);
        
        // Ajuste dos indices (considerando que a sequencia comeca do 1: x1, x2, …, xn)
        indice1--;
        indice2--;
        
        if(tipo == 'i')
        {
            if(variaveis[indice1] == 0 && variaveis[indice2] == 0)
               variaveis[indice1] = variaveis[indice2] = aux;
            else if(variaveis[indice1] == 0)
                variaveis[indice1] = variaveis[indice2];
            else if(variaveis[indice2] == 0)
                variaveis[indice2] = variaveis[indice1];
            else if(variaveis[indice1] != variaveis[indice2]) // contradicao
                break;

        }
        else // 'd'
        {
            if(variaveis[indice1] == 0 && variaveis[indice2] == 0)
            {
                variaveis[indice1] = aux;
                aux++;
                variaveis[indice2] = aux;
            }
            else if(variaveis[indice1] == 0)
                variaveis[indice1] = ++aux;
            else if(variaveis[indice2] == 0)
                variaveis[indice2] = ++aux;
            else if(variaveis[indice1] == variaveis[indice2]) // contradicao
                break;
        }
        
        aux++;
    }
    
    if(i == m)
        printf("Sim, eh possivel satisfazer todas as condicoes.\n");
    else
        printf("Nao, NAO eh possivel satisfazer todas as condicoes.\n");
    
    return 0;
}