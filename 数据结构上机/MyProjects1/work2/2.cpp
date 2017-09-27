#include <stdio.h>
#include <stdlib.h>
#include<conio.h>
typedef struct node{
	int height;
	struct node *next;
}linklist;

void Print(linklist *l){
	linklist *t;
	t=(linklist*)malloc(sizeof(linklist));
	t=l->next;
	while(t->next!=NULL){
		printf("%d",t->height);
		printf(" ");
		t=t->next;
	}
	printf("%d",t->height);
}

linklist *Create(){
	linklist *p,*q;
	int Len,i,insert,num[20];
	scanf("%d",&Len);
	scanf("%d",&insert);
	for(i=0;i<Len;i++){
		scanf("%d",&num[i]);
	}
	int Height=0;
	linklist *head,*s,*r;
	head=(linklist*)malloc(sizeof(linklist));
	r=head;
	for(i=0;i<Len;i++){
		s=(linklist*)malloc(sizeof(linklist));
		s->height=num[i];
		r->next=s;
		r=s;
	}
	r->next=NULL;
	p=head;
	q=p->next;
	for(i=0;i<Len;i++)
	{
		if(q->height>insert){
			s=(linklist*)malloc(sizeof(linklist));
			s->height=insert;
			p->next=s;
			s->next=q;
			break;
		}
		else{
			p=p->next;
			q=q->next;
		}
	}
	if(i==Len){
		s=(linklist*)malloc(sizeof(linklist));
		s->height=insert;
		p->next=s;
		s->next=NULL;
	}
	return head;
}

int main(){
	linklist *L;
	L=(linklist*)malloc(sizeof(linklist));
	L=Create();
	Print(L);
	return 0;
}