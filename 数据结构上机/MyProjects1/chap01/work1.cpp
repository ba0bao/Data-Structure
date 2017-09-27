#include <stdio.h>
#include <stdlib.h>
#include<conio.h>
#include<string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

typedef struct node{
	char name[20];
	int number;
	char sex;
	struct node *next;
}linklist;

linklist *Create(){
	int i=0;
	char Name[20];
	int Number;
	char Sex;
	linklist *head,*s,*r;
	head=(linklist*)malloc(sizeof(linklist));
	r=head;
	while(1){
		scanf("%s",Name);
		if(Name[0]!='#'){
			scanf("%d %c",&Number,&Sex);
			s=(linklist*)malloc(sizeof(linklist));
			strcpy(s->name,Name);
			s->number=Number;
			s->sex=Sex;
			r->next=s;
			r=s;
			continue;
		}
		else break;
	}
	r->next=NULL;
	return head;
}

void Print(linklist *l){
	linklist *t;
	t=(linklist*)malloc(sizeof(linklist));
	t=l->next;
	while(t!=NULL){
		printf("%s %d %c\n",t->name,t->number,t->sex);
		t=t->next;
	}
}

void Del(linklist *l){
	int delnumber,flag=1;
	scanf("%d",&delnumber);
	linklist *p,*q;
	p=(linklist*)malloc(sizeof(linklist));
	q=(linklist*)malloc(sizeof(linklist));
	p=l;
	q=l->next;
	while(q!=NULL){
		if(q->number==delnumber){
			p->next=q->next;
			flag=0;
		    break;
		}
		else{
			p=p->next;
			q=q->next;
		}
	}
	if(flag) printf("No\n");
	else Print(l);
}


int main(){
	linklist *r;
	r=(linklist*)malloc(sizeof(linklist));
	r=Create();
	Del(r);
	return 0;
}