#include<stdio.h>
#include<string.h>

int main(){
	char n[101];
	int a=0;
	scanf("%s",&n);
	int i=0;
	for(i=0;i<strlen(n);i++){
		a+=n[i]-'0';
	}
	char b[3]={0};
	i=0;
	do{
		b[i++]='0'+a%10;
		a/=10;
	}while(a);
	for(i=strlen(b)-1;i>=0;i--){
		switch(b[i]){
			case '0':printf("zero");break;
			case '1':printf("one");break;
			case '2':printf("two");break;
			case '3':printf("three");break;
			case '4':printf("four");break;
			case '5':printf("five");break;
			case '6':printf("six");break;
			case '7':printf("seven");break;
			case '8':printf("eight");break;
			case '9':printf("nine");break;
		}
		if(i) printf(" ");
	}
	return 0;
} 
