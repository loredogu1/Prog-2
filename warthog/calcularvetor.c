//Data:06/05/2020 By: Guilherme Pereira Loredo - USP - Universidade de São Paulo
// Codigo: calular operação com dois vetores

#include <stdio.h>
#include <stdlib.h>

struct ponto{
  int x;
  int y;
  int z;
};
typedef  struct ponto Ponto;

int main(void) {

    Ponto a, b,resultado;

    scanf("%d %d %d",&a.x,&a.y,&a.z);
    scanf("%d %d %d",&b.x,&b.y,&b.z);
    resultado.x = b.x - a.x;
    resultado.y = b.y - a.y;
    resultado.z = b.z - a.z;
    printf("%d %d %d ", resultado.x,resultado.y,resultado.z);

    return 0;
}