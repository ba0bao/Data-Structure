#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

typedef struct node{
	int data;
	struct node *next;
}linklist;
linklist *l; 

typedef struct
{ 
	linklist *front,*rear;  
} linkqueue; 
linkqueue *q;

int len;

linklist *create(){
	int ch,i;
	linklist *s,*r,*head;
	scanf("%d",&len);
	head=(linklist*)malloc(sizeof(linklist));
	r=head;
	for(i=0;i<len;i++){
		scanf("%d",&ch);
		s=(linklist*)malloc(sizeof(linklist));
		s->data=ch;
		r->next=s;
		r=s;
	}
	r->next=NULL;
	q=(linkqueue*)malloc(sizeof(linkqueue));
	q->front=(linklist*)malloc(sizeof(linklist));
	q->rear=(linklist*)malloc(sizeof(linklist));
	q->front=head;
	q->rear=r;
	l=head;
	return head;
}

int frontq(linkqueue *q){
	int ret;
	linklist *s;
	s=q->front->next;
	if(s->next==NULL){
		q->front->next=NULL;
		q->rear=q->front;
	}
	else 
		q->front->next=s->next;
	ret=s->data;
	return ret;
}

void Delete(linklist *l,linklist *a){
	linklist *p;
	p=l;
	while(p->next!=a)
		p=p->next;
		p->next=a->next;
}

linkqueue *correct(linklist *l){
	int i;
	linklist *s,*r,*head,*d,*t,*a;
	head=(linklist*)malloc(sizeof(linklist));
	r=head;
	for(i=0;i<len;i++){
		d=l;
		s=(linklist*)malloc(sizeof(linklist));
		s=d->next;
		d=d->next;
		while(1){
			t=d->next;
			if(t==NULL)
				break;
			if(s->data>t->data){
				s=t;
			}
			a=s;
			d=d->next;
		}
		if(l->next->next!=NULL)
			Delete(l,a);
		r->next=s;
		r=s;
	}
	r->next=NULL;
	q->front=head;
	q->rear=r;
	return q;
}

int main() 
{ 
	int i;
	l=create();
	q=correct(l);
	for(i=0;i<len;i++){
		printf("%d ",frontq(q));
	}
	return 1;
} 
