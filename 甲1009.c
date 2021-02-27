#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

typedef struct node{
	int n;//exponent
	int a;//coeffeicient
}node,*pn;

pn init(int k, pn p){
	p=(pn)malloc(sizeof(node));
	
} 

int main(int argc, char *argv[]) {
	int k;
	pn s=null,t=null;
	scanf("%d",&k);
	s=init(k,s);
	scanf("%d",%k);
	t=init(k,t);
	return 0;
}
