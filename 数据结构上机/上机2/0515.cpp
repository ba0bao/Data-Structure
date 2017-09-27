#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
typedef int keytype;
typedef int datatype;
typedef struct node{
	keytype key;		//关键字项 
	datatype other;		//其他数据项 
	struct node *lchild,*rchild;
}bstnode;
//在二叉排序树中插入结点 
bstnode* InsertBst(bstnode *t,bstnode *s){
	bstnode *p,*f;
	p=t;
	while(p!=NULL){
		f=p;
		if(s->key==p->key) return t;	//树中已有该结点，无须插入
		if(s->key<p->key) p=p->lchild;	//在左子树中查找插入位置
		else
		p=p->rchild; 
	}
	if(t==NULL)			//原树为空，返回s作为根节点 
		return s;
	if(s->key < f->key)
		f->lchild=s;
	else
		f->rchild=s;
	return t; 
} 

//建立二叉排序树 
bstnode* CreateBst(){
	bstnode *t,*s;
	keytype key,endflag=0;		//endflag为结点结束标志
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

//删除结点
bstnode* DelBstNode(bstnode* t,keytype k){
	bstnode *p,*q,*s,*f;
	p=t;
	q=NULL;
	while(p!=NULL){					//查找关键字为k的待删结点 
		if(p->key==k)break;
		q=p;
		if(p->key>k)
			p=p->lchild;
		else
			p=p->rchild;
	}
	if(p==NULL) return t;			//找不到结点，返回原树
	if(p->lchild==NULL){			//p所指结点的左子树为空
	 	if(q==NULL) 
			t=p->rchild;				//p为原树的根 
		else if(q->lchild==p){
			q->lchild=p->rchild;
		}else
			q->rchild=p->rchild;
			free(p);
	}else{
		f=p;
		s=p->lchild;
		while(s->rchild!=NULL){		//在pl中查找最右下结点，即查找p的先序结点 
			f=s;
			s=p->rchild;
		}
		if(f==p)
			f->lchild=s->lchild;		//将s所指结点的左子树链接到*f上
		else
			f->rchild=s->lchild;
		p->key=s->key;
		p->other=s->other;
		free(s);
		}
		return t;
	
} 

//中序遍历
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
