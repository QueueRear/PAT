#include<stdio.h>
#include<string.h>
void gyaku(char*s,int n,char*m)
{
	char t[80]={0},*p;
	int i;
	for(i=0;i<n;i++)
	{
		if(s[i]==' ')
		{
			p=&s[i+1];
			gyaku(p,n-i-1,m);
			break;
		}
		else
			t[i]=s[i];
	}
	printf("%s",t);
	if(s!=m)
		printf(" ");
}
int main()
{
	char s[80];
	int i;
	gets(s);
 	gyaku(s,strlen(s),s);
	return 0;
} 
