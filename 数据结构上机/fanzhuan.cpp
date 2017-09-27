#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

typedef int datatype;
typedef struct node{
	datatype data;
	struct node *next;
}linklist;

linklist *CreateList(int t){
	int m,i;
	linklist *head,*s,*r;
	head=(linklist*)malloc(sizeof(linklist));
	r=head;
	for(i=0;i<t;i++){
		scanf("%d",&m);
		s=(linklist*)malloc(sizeof(linklist));
		s->data=m;
		r->next=s;
		r=s;
	}
	r->next=NULL;
	return head;
}

linklist* Re(linklist *p){
	linklist *r,*s,*t,*q;
	r=p->next;
	s=r->next;
	if(s==NULL) return p;
	t=s->next;
	while(t!=NULL){
		s->next=r;
		r=s;
		s=t;
		t=s->next;
	}
	s->next=r;
	p->next->next=NULL;
	p->next=s;
	return p;
}

void Print(linklist *q){
	linklist *p;
	p=q->next;
	while(p!=NULL){
		printf("%d ",p->data);
		p=p->next;
	}
	printf("\n");
}

int main(){
	int n,k,i;
	linklist* Head[20];
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&k);
		Head[i]=CreateList(k);
		Head[i]=Re(Head[i]);
	}
	for(i=0;i<n;i++){
		Print(Head[i]);
	}
	return 0;
}
