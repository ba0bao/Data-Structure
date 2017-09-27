#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#define MAXSIZE 1024
typedef char datetype;
typedef struct node
{
	datetype date;
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
		s->date=ch;
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
		printf("%c",t->date);
		t=t->next;
	}
	printf("%c\n",t->date);
}

//单链表逆置
void nz(linklist *head)
{ 
	linklist *p,*s,*t; 
	p=head; 
	s=p->next; 
	while(s->next!=NULL)
	{ 
		t=s->next; 
		s->next=p; 
		p=s; 
		s=t; 
	} 
	s->next=p; 
	head->next->next=NULL; 
	head->next=s;
}
void main(){
	L=Creat();
	Output(L);
	nz(L);
	Output(L);
}