#include<stdio.h>
#include <studlib.h>

int main(int argc, char const*argv[]){
    File *fip1 = fogen("arquivo1.dat","rb");
    File *fip2 = fogen("arquivo2.dat","rb");

    File *fp3 =  fogen ("aquivo3.dat","wb");
    if(fp1 == NULL || fp2 == NULL || fp3 == NULL){
        printf("Erro ao abrir o arquivos\n");
        return 1;
    }
}