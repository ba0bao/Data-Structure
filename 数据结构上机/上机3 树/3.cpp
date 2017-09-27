#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
typedef struct{
	int weight;
	int lchild,rchild,parent;
}hufmtree;


void Huffman(hufmtree tree[],int M,int N){
	int i,j,p1,p2;
	int small1,small2,f;
	for(i=0;i<M;i++){
		tree[i].parent=-1;
		tree[i].lchild=-1;
		tree[i].rchild=-1;
		tree[i].weight=0.0;
	}
	for(i=0;i<N;i++){
		scanf("%d",&f);
		tree[i].weight=f;
	}
	for(i=N;i<M;i++){
		p1=p2=0;
		small1=small2=100;
		for(j=0;j<i;j++){
			if(tree[j].parent==-1){
				if(tree[j].weight<small1){
					small2=small1;
					small1=tree[j].weight;
					p2=p1;
					p1=j;
				}else if(tree[j].weight<small2){
					small2=tree[j].weight;
					p2=j;
				}
			}
		}
		tree[p1].parent=i;
		tree[p2].parent=i;
		tree[i].lchild=p1;
		tree[i].rchild=p2;
		tree[i].parent=-1;
		tree[i].weight=tree[p1].weight+tree[p2].weight;
	}
}

int Len(hufmtree tree[],int N){
	int i,j,p,m=0;
	int Weight,len=0;
	for(i=0;i<N;i++){
		Weight=tree[i].weight;
		j=i;
		p=tree[j].parent;
		while(p!=-1){
			j=p;
			p=tree[j].parent;
			m++;
		}
		len=len+m*Weight;
		m=0;
	}
	return len;
}

int main(){
	int m,n,i,j;
	hufmtree Tree[100];
	scanf("%d",&n);
	m=2*n-1;
	Huffman(Tree,m,n);
	printf("%d",Len(Tree,n));
	return 0;
}
