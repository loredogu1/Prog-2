//Data:06/05/2020 By: Guilherme Pereira Loredo - USP - Universidade de São Paulo
// Codigo: palindromo - palavras que pode ser lidas de tras pra frente

#include <stdio.h>
#include <string.h>


int main(){
    char palavra[30], contrario;
    int i,j =0;
    int flag = 1, tam;
    scanf("%s", palavra);

    tam =  strlen(palavra);
    i = tam-1;
    while(flag & j < tam){
        if(palavra[i] != palavra[j]){
            flag = 0;
        }
        j++;
        i--;
    }
    if(flag)
        printf("Sim");
    else
        printf("Nao");

   

    return 0;
}