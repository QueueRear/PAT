#include<stdio.h>
int main()
{
	int n,m,i=0;
	scanf("%d %d",&n,&m);
	int a[n];
	while(i<n)
		scanf("%d",&a[i++]);
	if(m>=n)
	{
		for(i=0;i<n;i++)
		{
			printf("%d",a[i]);
			if(i<n-1) printf(" ");
		}
	}
	else
	{
		for(i=0;i<m;i++)
			printf("%d ",a[n-m+i]);
		for(i=0;i<n-m;i++)
		{
			printf("%d",a[i]);
			if(i+1!=n-m) printf(" ");
		}
	}
/*	int a[n+m];
	while(i<n)
		scanf("%d",&a[i++]);
	if(n>m) 
	{ 
		for(i=0;i<n;i++)
			a[m+n-i-1]=a[n-i-1];
		for(i=0;i<m;i++)
			a[i]=a[n+i];
		for(i=0;i<n;i++)
		{
			printf("%d",a[i]);
			if(i+1!=n) printf(" ");
		}
	} 
	else
	{
		for(i=0;i<n;i++)
		{
			printf("%d",a[i]);
			if(i+1!=n) printf(" ");
		}
	}*/
	return 0;
} 
