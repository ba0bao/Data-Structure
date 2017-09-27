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
	while(t->next!=head)
	{		
		printf("%c",t->data);
		t=t->next;
	}
	printf("%c\n",t->data);
}

//分类
void fl(linklist* L)
{
	linklist *p,*q,*la,*lb,*lc,*r,*s,*t;
	la=(linklist*)malloc(sizeof(linklist));
	lb=(linklist*)malloc(sizeof(linklist));
	lc=(linklist*)malloc(sizeof(linklist));
	p=L->next;
	r=la;
	s=lb;
	t=lc;
	while(p->next!=NULL)
	{
		if('0'<=p->data && p->data<='9')
		{
			r->next=p;
			r=r->next;
			p=p->next;
		}
		else if(('a'<=p->data && p->data<='z') || ('A'<=p->data && p->data<='Z'))
		{
			s->next=p;
			s=s->next;
			p=p->next;
		}
		else
		{
			t->next=p;
			t=t->next;
			p=p->next;
		}

	}
	if('0'<=p->data && p->data<='9')
		{
			r->next=p;
			r=r->next;
		}
		else if(('a'<=p->data && p->data<='z') || ('A'<=p->data && p->data<='Z'))
		{
			s->next=p;
			s=s->next;
		}
		else
		{
			t->next=p;
			t=t->next;
		}
		r->next=la;
		s->next=lb;
		t->next=lc;
		Output(la);
		Output(lb);
		Output(lc);


}
void main(){
	L=Creat();
	fl(L);
}