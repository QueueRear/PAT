#include<stdio.h>
#include<math.h>
int ornot(int n)
{
	int i=2;
	while(i<=sqrt(n))
	{
		if(n%i==0) return 0;
		else i++;
	}
	return n;
}
int main()
{
	int n,i=0,m=0;
	scanf("%d",&n);
	int a[n];
	while(i-1<n)
	{
		a[i-1]=ornot(i);
		i++;
	}
	for(i=1;i<n;i++)//1不是素数，从2开始计数 
		if(a[i+2]-a[i]==2) m++;
	printf("%d",m);
	return 0;
}  
