#include <stdio.h>

int main() {

    int a,b;

    scanf("%i %i",&a,&b);

    if(a<b)
        printf("Crescente\n");
    else
        printf("Decrescente\n");

    return 0;
}