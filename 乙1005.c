#include <stdio.h>
int main() {
	int m,a[m],n=0,i,j=0,b;
	scanf("%d",&m);
	while(n<m)
		scanf("%d",&a[n++]);
	for(n=0;n<m;n++)
	{
		b=a[n];
		while(b>1)
		{
			switch(b%2){
			case 0:b/=2;break;
			case 1:b=(3*b+1)/2;break;}
			for(i=0;i<m;i++)
				if(a[i]==b&&b!=1)
					a[i]=1;
		}
	}
	for(n=0;n<m;n++)
	{
		for(i=n+1;i<m;i++)
		{
			if(a[n]<a[i])
			{
				int t=a[n];a[n]=a[i];a[i]=t;
			}
		}
	}
	while(j<m&&a[j]>1)
	{
		if(a[j]!=1)
		printf("%d",a[j]);
		if(j+1<m&&a[j+1]!=1)
		printf(" ");
		j++;
	}
	return 0;
}
