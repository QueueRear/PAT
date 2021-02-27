#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int lv;//level
	int lch,rsb;
}Tnode,*Tree;

void Init(Tree T,int n,int m);

int main(){
	int m,n;
	scanf("%d",&n);//n:�ܽ����, m:��Ҷ�ڵ��� 
	if(n){//���ǿ� 
		scanf("%d",&m);
		Tnode T[n+1];
		Init(T,n,m);
		int cnt[T[0].lv];
		int i;
		for(i=0;i<T[0].lv;i++){
			cnt[i]=0;
		}
		for(i=1;i<n+1;i++){
			if(T[i].lch==0){
				cnt[T[i].lv-1]++;
			}
		}
		for(i=0;i<T[0].lv;i++){
			printf("%d",cnt[i]);
			if(i<T[0].lv-1) printf(" ");
		}
	}
	return 0;
} 

void Init(Tree T,int n,int m){
	T[0].lv=T[0].lch=T[0].rsb=0;
	T[1].lv=1;T[1].lch=T[1].rsb=0;
	int i;
	for(i=0;i<m;i++){
		int id,k;
		scanf("%d %d",&id,&k);
		int j;
		for(j=0;j<k;j++){
			int t;
			scanf("%d",&t);
			if(j==0){//����ǳ��ӣ���ĸ������Ҫָ���� 
				T[id].lch=t;
				T[t].lv=T[id].lv+1;
				T[t].lch=T[t].rsb=0; 
			}
			else{//������ǳ��ӣ��ֳ������ֵ�Ҫָ���� 
				T[t-1].rsb=t;
				T[t].lv=T[id].lv+1;
				T[t].lch=T[t].rsb=0;
			}
		} 
	}
	T[0].lv=T[n].lv;
	return;
}
