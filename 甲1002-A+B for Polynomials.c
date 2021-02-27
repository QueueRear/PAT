#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
typedef struct term{
	float coef;
	int expn;
	struct term *next;
}term,*Pterm;

Pterm init_poly(int n){//返回带头结点的链表的头指针
	int i=0;
	/*term hNode;
	hNode.next=NULL;*/
	Pterm s;
	Pterm h,t;//t指示当前尾结点
	if(!(h=(Pterm)malloc(sizeof(term)))) return h;//h指示头结点 
	h->next=NULL;
	t=h;
	while(i<n){
		s=(Pterm)malloc(sizeof(term));
		scanf("%d %f",&s->expn,&s->coef);
		s->next=NULL;
		t->next=s;
		t=t->next; 
		i++;
	}
	return h;
}

int cmp(int a,int b){
	int n;
	if(a>b) n=1;
	else if(a<b) n=-1;
	else n=0;
	return n;
}

int main()
{
	Pterm ha,hb; 
	int a,b;
	scanf("%d",&a);
	ha=init_poly(a);
	scanf("%d",&b);
	hb=init_poly(b);
	int cnt=a+b; 
	Pterm pa=ha->next,pb=hb->next;//pa1 pb1分别指向当前结点 
	Pterm p=ha;//p指向合并后的多项式最后一个结点 
	while(pa&&pb){
		switch(cmp(pa->expn,pb->expn)){
			case -1://pa->expn < pb->expn
				p->next=pb;p=p->next;pb=pb->next;break;
			case 1://pa->expn > pb->expn
				p->next=pa;p=p->next;pa=pa->next;break;
			case 0://pa pb所指结点指数相等 
				cnt--;
				if(fabs(pa->coef+pb->coef)<1e-8){//如果两个系数相加为零
					cnt--;
					Pterm s=pa,t=pb;
					pa=pa->next;free(s); 
					pb=pb->next;free(t);
				}
				else{
					pa->coef+=pb->coef;
					p->next=pa;p=p->next;pa=pa->next;
					Pterm t=pb;
					pb=pb->next;free(t);
				}
				break;
		}
	}
	if(pa==NULL){//把剩下来的结点接上 
		p->next=pb;
	}
	else if(pb==NULL){
		p->next=pa;
	}
	free(hb);
	if(cnt) printf("%d ",cnt);
	else printf("0");
	for(p=ha->next;p;p=p->next){
		if(p->next){//p不是尾结点 
			printf("%d %.1f ",p->expn,p->coef);
		}
		else{
			printf("%d %.1f",p->expn,p->coef);
		}
	}
	return 0;
}
