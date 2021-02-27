#include<stdio.h>
#include<string.h>
int main()
{
	int a,b,i=1;//i用以判断是否第一个输入就是零多项式，是返回1，否返回0 
	char ch=' ';
	while(ch!='\n')
	{
		scanf("%d %d",&a,&b);
		ch=getchar();
		if(!b&&i)//若第一次输入0指数 
			printf("0 0");
		else
		{
			if(b)//若输入非零指数 
			{
				if(i)//若是第一次输入 
				{
					printf("%d %d",a*b,b-1);
					i=0;//把第一次输入的标记抹掉 
				}
				else //若非第一次输入
					printf(" %d %d",a*b,b-1);//在输出数字前要先打个空格 
			} 
		}
	}
	return 0;
} 
