#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define MAXSIZE 1024
typedef char datatype;
typedef struct node{
	datatype data;
	struct node *lchild,*rchild;
}bitree;


bitree* CreateTree(){
	char ch;
	bitree *Q[MAXSIZE];
	int front,rear;
	bitree *root,*s;
	root=NULL;
	front=1,rear=0;
	while((ch=getchar())!='#'){
		s=NULL;
		if(ch!='@'){
			s=(bitree*)malloc(sizeof(bitree));
			s->data=ch;
			s->lchild=NULL;
			s->rchild=NULL;
		}
		rear++;
		Q[rear]=s;
		if(rear==1){
			root=s;
		}
		else{
			if(s&&Q[front]){
				if(rear%2==0)
					Q[front]->lchild=s;
				else
					Q[front]->rchild=s;
			}
			if(rear%2==1){
				front++;
			}
		}
		
	}
	return root;
}

int CountLeaf(bitree *p){
	if(!p)
		return 0;
	else if(!p->lchild && !p->rchild){
		printf("%c ",p->data);
		return 1;
	}
	else
		return CountLeaf(p->lchild)+CountLeaf(p->rchild);
}

int main(){
	bitree *T=CreateTree();
	int a=CountLeaf(T);
	printf("\n");
	printf("%d",a);
	return 0;
}
