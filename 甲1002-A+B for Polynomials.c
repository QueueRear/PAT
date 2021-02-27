#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
typedef struct term{
	float coef;
	int expn;
	struct term *next;
}term,*Pterm;

Pterm init_poly(int n){//���ش�ͷ���������ͷָ��
	int i=0;
	/*term hNode;
	hNode.next=NULL;*/
	Pterm s;
	Pterm h,t;//tָʾ��ǰβ���
	if(!(h=(Pterm)malloc(sizeof(term)))) return h;//hָʾͷ��� 
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
	Pterm pa=ha->next,pb=hb->next;//pa1 pb1�ֱ�ָ��ǰ��� 
	Pterm p=ha;//pָ��ϲ���Ķ���ʽ���һ����� 
	while(pa&&pb){
		switch(cmp(pa->expn,pb->expn)){
			case -1://pa->expn < pb->expn
				p->next=pb;p=p->next;pb=pb->next;break;
			case 1://pa->expn > pb->expn
				p->next=pa;p=p->next;pa=pa->next;break;
			case 0://pa pb��ָ���ָ����� 
				cnt--;
				if(fabs(pa->coef+pb->coef)<1e-8){//�������ϵ�����Ϊ��
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
	if(pa==NULL){//��ʣ�����Ľ����� 
		p->next=pb;
	}
	else if(pb==NULL){
		p->next=pa;
	}
	free(hb);
	if(cnt) printf("%d ",cnt);
	else printf("0");
	for(p=ha->next;p;p=p->next){
		if(p->next){//p����β��� 
			printf("%d %.1f ",p->expn,p->coef);
		}
		else{
			printf("%d %.1f",p->expn,p->coef);
		}
	}
	return 0;
}
