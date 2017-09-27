#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#define SMAX 16
typedef int datatype;
typedef struct{
	int i,j;
	datatype v;
}node;
typedef struct{
	int m,n,t;
	node data[SMAX];
}spmatrix;
//��������
spmatrix* Create(){
	spmatrix* mat;
	mat=(spmatrix*)malloc(sizeof(spmatrix));
	int i,r,s,da,t=0;
	char ch;
	printf("������ϡ���������������������Ԫ����\n");
	scanf("%d %d %d",&mat->m,&mat->n,&mat->t);
	printf("������ϡ�������Ԫ���\n");
	for(i=0;i<mat->t;i++){
		scanf("%d %d %d",&r,&s,&da);
		mat->data[t].i=r;
		mat->data[t].j=s;
		mat->data[t].v=da;
		t++;
	}
	return mat;
}

//��ӡ
void Output(spmatrix*a){
	int k,p;
	for(p=0;p<a->m;p++){
		for(k=0;k<a->t;k++){
			if(a->data[k].i==p){
				printf("%d %d %d",a->data[k].i,a->data[k].j,a->data[k].v);
				printf("\n");
			}
		}		
	}
}


//�˷�
spmatrix* Mult(spmatrix *a,spmatrix *b){
	int p,q,x,y,flag=1,bno=0;
	spmatrix *c;
	c=(spmatrix*)malloc(sizeof(spmatrix));
	c->m=a->m;
	c->n=b->n;
	if(a->t==0||b->t==0) return c;
	for(p=0;p<a->m;p++){	                            //���б�������a
		for(q=0;q<b->n;q++){		                    //���б�������b
			for(x=0;x<a->t;x++){				     	//����a��ÿ��Ԫ��
				if(a->data[x].i==p){				    //��Ԫ�����ڵ�ǰ�����У�p��
					for(y=0;y<b->t;y++){		     	//����b��ÿ��Ԫ��
						if(b->data[y].j==q){	    	//��Ԫ�����ڵ�ǰ�����У�q��
							if(flag){
								c->data[bno].v=0;
								flag=0;
							}
							if(a->data[x].j==b->data[y].i){
								c->data[bno].v=c->data[bno].v+a->data[x].v*b->data[y].v;
							}
						}
					}
					
				}
			}
			if(!flag && c->data[bno].v!=0){   //��a�ĵ�p����b�ĵ�q�о����ڷ���Ԫ���Ұ���������˵õ������Ϊ0
				c->data[bno].i=p;
				c->data[bno].j=q;
				bno++;                       //���������c�У�������һ��cԪ��
				flag=1;
			}
		}
		
	}
	c->t=bno+1;
	return c;
}
void main(){
	spmatrix *a,*b,*c;
	a=Create();
	printf("����a��Ԫ���Ϊ\n");
	Output(a);
	b=Create();
	printf("����b��Ԫ���Ϊ\n");
	Output(b);
	c=Mult(a,b);
	printf("a*b�����Ԫ���Ϊ\n");
	Output(c);	
}

