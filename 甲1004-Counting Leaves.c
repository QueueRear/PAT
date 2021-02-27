#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int lv;//level
	int lch,rsb;
}Tnode,*Tree;

void Init(Tree T,int n,int m);

int main(){
	int m,n;
	scanf("%d",&n);//n:总结点数, m:非叶节点数 
	if(n){//树非空 
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
			if(j==0){//如果是长子，父母的左子要指向它 
				T[id].lch=t;
				T[t].lv=T[id].lv+1;
				T[t].lch=T[t].rsb=0; 
			}
			else{//如果不是长子，兄长的右兄弟要指向它 
				T[t-1].rsb=t;
				T[t].lv=T[id].lv+1;
				T[t].lch=T[t].rsb=0;
			}
		} 
	}
	T[0].lv=T[n].lv;
	return;
}
