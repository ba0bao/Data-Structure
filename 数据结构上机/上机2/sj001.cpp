#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
typedef struct sequeue{
	int data[1000];
	int front,rear;
}queue;
queue *sq;

void Setnull(queue *SS){
	SS->front=-1;
	SS->rear=-1;
}
int IsEmpty(queue *Q){
	if(Q->front==Q->rear)
		return 1;
	else 
		return 0;
}

void EnQueue(queue *Q,int n){
	Q->rear++;
	Q->data[Q->rear]=n;
}

int DeQueue(queue *Q){
	Q->front++;
	return Q->data[Q->front];
}

void Print(queue *S){
	int i;
	for(i=0;i<S->rear-S->front-1;i++){
		printf("%d ",S->data[i]);
	}
	printf("%d",S->data[i]);
} 
queue* Paixu(queue*S){
		int len,flag,i,j,a,b,c;
		queue *R,*T;
		R=(queue*)malloc(sizeof(queue));
		T=(queue*)malloc(sizeof(queue));
		Setnull(R);
		Setnull(T);
		R=S;
		len=R->rear-R->front;
		a=0;
		for(i=0;i<len;i++){
		flag=0;
			for(j=0;j<len;j++){
				c=DeQueue(R);
				EnQueue(R,c);
				if(c>a){
					if(flag==0) b=c;
					else b=(b<c?b:c);
					flag=1; 
				}
		}
		EnQueue(T,b);
		a=b;
	}
	return T;
}
int main(){
	int i,k,n;
	scanf("%d",&n);
	queue *R;
	R=(queue*)malloc(sizeof(queue));
	for(i=0;i<n;i++){
		scanf("%d",&k);
		EnQueue(R,k);
	}
	printf("\n");
	Print(Paixu(R));
	return 0;
}
