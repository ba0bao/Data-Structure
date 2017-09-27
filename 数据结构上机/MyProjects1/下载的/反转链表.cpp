#include <stdio.h>
#include <stdlib.h>
#include<conio.h>
#include<string.h>
typedef struct node{
	int data;
	struct node *next;
}linklist;

linklist *Create(){
	int i,len;
	int number;
	scanf("%d",&len);
	linklist *head,*s,*r;
	head=(linklist*)malloc(sizeof(linklist));
	r=head;
	for(i=0;i<len;i++){
		scanf("%d",&number);
		s=(linklist*)malloc(sizeof(linklist));
		s->data=number;
		r->next=s;
		r=s;
	}
	r->next=NULL;
	return head;
}

void Print(linklist *l){
	linklist *t;
	t=(linklist*)malloc(sizeof(linklist));
	t=l->next;
	while(t!=NULL){
		printf("%d ",t->data);
		t=t->next;
	}
}


linklist *Over(linklist *L){
	linklist *p,*s,*t;
	p=L;
	s=p->next;
	while(s->next!=NULL){
			t=s->next;
			s->next=p;
			p=s;
			s=t;
		}
	s->next=p;
	L->next->next=NULL;
	L->next=s;
	return L;
}

int main(){
	int i,t;
	scanf("%d",&t);
	linklist* a[10];
	for(i=0;i<t;i++){
		a[i]=(linklist*)malloc(sizeof(linklist));
		a[i]=Create();
	}
	for(i=0;i<t;i++){ 
		a[i]=Over(a[i]);
	}
	for(i=0;i<t;i++){
		Print(a[i]);
		printf("\n");
	}
	return 0;
}

