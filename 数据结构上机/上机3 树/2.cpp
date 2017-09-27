#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define MAXSIZE 1024
typedef int keytype;
typedef struct node{
	keytype key;
	struct node *lchild,*rchild;
}bstnode;

bstnode* InsertBst(bstnode *t,bstnode *s){
	bstnode *p,*f;
	p=t;
	while(p!=NULL){
		f=p;
		if(s->key==p->key)return t;
		if(s->key<p->key)p=p->lchild;
		else
			p=p->rchild;
	}
	if(t==NULL)
		return s;
	if(s->key<f->key)
		f->lchild=s;
	else
		f->rchild=s;
	return t;
}

bstnode* CreateBst(int i,int num[]){
	int j=0;
	bstnode *t,*s;
	keytype key;
	t=NULL;
	for(j=0;j<i;j++){
		s=(bstnode*)malloc(sizeof(bstnode));
		s->lchild=s->rchild=NULL;
		s->key=num[j];
		t=InsertBst(t,s);
	}
	return t;
}



void InOrder(bstnode*p){
	if(p!=NULL){
		InOrder(p->lchild);
		printf("%d ",p->key);
		InOrder(p->rchild);
	}
}

int main(){
	bstnode *t;
	int i,m;
	int a[100];
	scanf("%d",&m);
	for(i=0;i<m;i++){
		scanf("%d",&a[i]);
	}
	t=CreateBst(m,a);
	InOrder(t);
	return 0;
}
