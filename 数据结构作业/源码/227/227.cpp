#include<stdio.h>
#include<stdlib.h>
#include<conio.h> 
#define MAXSIZE 1024
typedef char datetype;
typedef struct node
{
	datetype data;
	struct node *next;
}linklist;
linklist *L;
//建立单链表
linklist *Creat()
{
	char ch;
	linklist *head,*s,*r;
	head=(linklist*)malloc(sizeof(linklist));
	r=head;
	while((ch=getche())!='#')
	{
		s=(linklist*)malloc(sizeof(linklist));
		s->data=ch;
		r->next=s;
		r=s;
	}
	r->next=NULL;
	return head;
}
//打印
void Output(linklist *head)
{
	linklist *t;
	t=head->next;
	printf("\n");
	while(t->next!=NULL)
	{		
		printf("%c",t->data);
		t=t->next;
	}
	printf("%c\n",t->data);
}

//递减合并
linklist *Union(linklist *la,linklist*lb)
{
	linklist *p,*q,*r,*u,*s,*t;
	p=la->next;
	q=lb->next;
	r=la;
	while((p!=NULL)&&(q!=NULL))
	{
		if(p->data>q->data)
		{
			u=q->next;
			r->next=q;
			r=q;
			q->next=p;
			q=u;
		}
		else  
		{
			r=p;
			p=p->next;
		}
	}
	if(q!=NULL) r->next=q;
	p=la; 
	s=p->next; 
	while(s->next!=NULL)
	{ 
		t=s->next; 
		s->next=p; 
		p=s; 
		s=t; 
	} 
	s->next=p; 
	la->next->next=NULL; 
	la->next=s;


	return la;
}
void main(){
	linklist *L1,*L2;
	L1=Creat();
	L2=Creat();
	//Output(L);
	L=Union(L1,L2);
	Output(L);
}