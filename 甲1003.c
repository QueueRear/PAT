#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

#define MAX 500

int n;
int ret[2]={1000,0};//当前最短路径长度、当前最多救援队
int teams[MAX],len[MAX][MAX],visit[MAX];
int cnt;//数最短路线数 

void dfs(int cur,int C2,int dis,int num);

int main(int argc, char *argv[]) {
	int m,C1,C2;
	scanf("%d %d %d %d",&n,&m,&C1,&C2);//n for cities, m for roads
	int i=0;
	while(i<n){
		scanf("%d",&teams[i]);
		i++;
	}
	for(i=0;i<m;i++){ //下三角邻接矩阵 
		int a,b;
		scanf("%d %d",&a,&b);
		scanf("%d",&len[a][b]);
		len[b][a]=len[a][b];
	}
	visit[C1]=1; 
	dfs(C1,C2,0,teams[C1]);
	printf("%d %d",cnt,ret[1]);
	return 0;
}
void dfs(int cur,int C2,int dis,int num){
	//递归出口
	if(cur==C2){
		if(dis<ret[0]){
			cnt=1;
			ret[0]=dis;ret[1]=num; 
		}
		else if(dis==ret[0]){
			cnt++;
			if(num>ret[1])
				ret[1]=num;
		}
		return;
	} 
	//递
	if(dis>ret[0]) return;
	int i;
	for(i=0;i<n;i++){
		if(visit[i]==0 && len[cur][i]!=0){
			visit[i]=1;
			dfs(i,C2,dis+len[cur][i],num+teams[i]);
			visit[i]=0;//用于找下一条通路时对该点进行访问 
		}
	}
}
