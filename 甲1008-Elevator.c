/*需求清单上有N个正数，每个数表示电梯需要停留的楼层，排成一个特定
的顺序。上行每层需要6秒，下行每层需要4秒，每层停留5秒。设电梯起始
位置在第0层，且完成后不需要回到起始位置，求完成需求清单所需总时间*/ 

#include <stdio.h>
#include <stdlib.h>

int main(){
	int n;
	scanf("%d",&n);
	int a[n];
	int i=0;
	while(i<n){
		scanf("%d",&a[i++]);
	}
	int t=6*a[0];//一开始就要上行 
	for(i=0;i<n-1;i++){
		if(a[i]<a[i+1]){//上行 
			t+=6*(a[i+1]-a[i]);
		}
		else if(a[i]>a[i+1]){
			t+=4*(a[i]-a[i+1]);
		}
	}
	t+=n*5;//每层停5秒 
	printf("%d",t);
	return 0;
} 
