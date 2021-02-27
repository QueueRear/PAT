#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

/*typedef struct time{
	int hh, mm, ss;
}time;*/

typedef struct person{
	char ID[16];
	int in, out;
}person;

int main(int argc, char *argv[]) {
	int m;
	scanf("%d",&m);
	person per[m];
	int i=0;
	while(i<m){
		scanf("%s",&per[i].ID);
		int hh,mm,ss;
		scanf("%d:%d:%d",&hh,&mm,&ss);
		per[i].in=ss+100*mm+10000*hh;
		scanf("%d:%d:%d",&hh,&mm,&ss);
		per[i].out=10000*hh+100*mm+ss;
		i++;
	}
	int r1, r2;
	int max=0, min=240000;
	for(i=0;i<m;i++){
		if(per[i].in<=min){
			min=per[i].in;
			r1=i;
		}
		if(per[i].out>=max){
			max=per[i].out;
			r2=i;
		}
	}
	printf("%s %s",per[r1].ID,per[r2].ID);
	return 0;
}
