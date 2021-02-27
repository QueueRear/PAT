#include<stdio.h>
#include<math.h>
int main()
{
	int a,b,c;
	scanf("%d %d",&a,&b);
	c=abs(a+b);
	int m[7]={0},i=6;
	do{
		m[i]=c%10;
		c/=10;
		i--;
	}while(c);
	if(a+b<0) printf("-");
	for(i++;i<7;i++)
	{
		printf("%d",m[i]);
		if(i==0||i==3) printf(",");
	}
	return 0;
 } 
