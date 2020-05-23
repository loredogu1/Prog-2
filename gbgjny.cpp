#include <stdio.h>
#include <stdlib.h>

int main(){
	int x, *p, **q;
	
	p = &x;
	q = &p;
	x = 10;
	
	printf("\n%d\n", *p);
	printf("\n%d\n", **q);
	
	
	return 0;
}

void duplica(int *x){
	*x = (*x)*2;
}
