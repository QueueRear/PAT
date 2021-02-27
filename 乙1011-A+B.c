#include<stdio.h>
int main()
{
	int n,i,j;
	scanf("%d",&n);
	int a[n][3];
	for(i=0;i<n;i++)
		for(j=0;j<3;j++)
			scanf("%d",&a[i][j]);
	for(i=0;i<n;i++)
	{
		printf("Case #%d: ",i+1);
		if(i!=n)
			if(a[i][0]+a[i][1]>a[i][2])
				printf("true\n");
			else
				printf("false\n");
		else
			if(a[i][0]+a[i][1]>a[i][2])
				printf("true");
			else
				printf("false");
	}
	return 0;
}
