#include<stdio.h>
#include<string.h>
int main()
{
	int a,b,i=1;//i�����ж��Ƿ��һ��������������ʽ���Ƿ���1���񷵻�0 
	char ch=' ';
	while(ch!='\n')
	{
		scanf("%d %d",&a,&b);
		ch=getchar();
		if(!b&&i)//����һ������0ָ�� 
			printf("0 0");
		else
		{
			if(b)//���������ָ�� 
			{
				if(i)//���ǵ�һ������ 
				{
					printf("%d %d",a*b,b-1);
					i=0;//�ѵ�һ������ı��Ĩ�� 
				}
				else //���ǵ�һ������
					printf(" %d %d",a*b,b-1);//���������ǰҪ�ȴ���ո� 
			} 
		}
	}
	return 0;
} 
