#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
typedef int keytype;
typedef int datatype;
typedef struct node{
	keytype key;		//�ؼ����� 
	datatype other;		//���������� 
	struct node *lchild,*rchild;
}bstnode;
//�ڶ����������в����� 
bstnode* InsertBst(bstnode *t,bstnode *s){
	bstnode *p,*f;
	p=t;
	while(p!=NULL){
		f=p;
		if(s->key==p->key) return t;	//�������иý�㣬�������
		if(s->key<p->key) p=p->lchild;	//���������в��Ҳ���λ��
		else
		p=p->rchild; 
	}
	if(t==NULL)			//ԭ��Ϊ�գ�����s��Ϊ���ڵ� 
		return s;
	if(s->key < f->key)
		f->lchild=s;
	else
		f->rchild=s;
	return t; 
} 

//�������������� 
bstnode* CreateBst(){
	bstnode *t,*s;
	keytype key,endflag=0;		//endflagΪ��������־
	datatype data;
	t=NULL;
	scanf("%d",&key);
	while(key!=endflag){
		s=(bstnode*)malloc(sizeof(bstnode));
		s->lchild=s->rchild=NULL;
		s->key=key;
		scanf("%d",&data);
		s->other=data;
		t=InsertBst(t,s);
		scanf("%d",&key);
	} 
	return t;
} 

//ɾ�����
bstnode* DelBstNode(bstnode* t,keytype k){
	bstnode *p,*q,*s,*f;
	p=t;
	q=NULL;
	while(p!=NULL){					//���ҹؼ���Ϊk�Ĵ�ɾ��� 
		if(p->key==k)break;
		q=p;
		if(p->key>k)
			p=p->lchild;
		else
			p=p->rchild;
	}
	if(p==NULL) return t;			//�Ҳ�����㣬����ԭ��
	if(p->lchild==NULL){			//p��ָ����������Ϊ��
	 	if(q==NULL) 
			t=p->rchild;				//pΪԭ���ĸ� 
		else if(q->lchild==p){
			q->lchild=p->rchild;
		}else
			q->rchild=p->rchild;
			free(p);
	}else{
		f=p;
		s=p->lchild;
		while(s->rchild!=NULL){		//��pl�в��������½�㣬������p�������� 
			f=s;
			s=p->rchild;
		}
		if(f==p)
			f->lchild=s->lchild;		//��s��ָ�������������ӵ�*f��
		else
			f->rchild=s->lchild;
		p->key=s->key;
		p->other=s->other;
		free(s);
		}
		return t;
	
} 

//�������
void InOrder(bstnode *p){
	if(p!=NULL){
	InOrder(p->lchild);
	printf("%d ",p->other);
	InOrder(p->rchild); 
}
}

int main(){
	bstnode *tr;
	tr=CreateBst();
	InOrder(tr);
	return 0;
	}
