//Data:06/05/2020 By: Guilherme Pereira Loredo - USP - Universidade de São Paulo
// Codigo: fatorar um numero usando uma função

#include <stdio.h>
int fatorial(int n) {
     int i;
     for ( i= 1; 1 < n; n--)
     {
         i= i*n;
     }
     printf ("%i", i);
   return i;
 }
int main (void) {
    int n;
    scanf("%d", &n);
    int aux = fatorial(n);
    return 0;
}