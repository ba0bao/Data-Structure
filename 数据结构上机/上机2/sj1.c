#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
typedef struct {
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
	queue *S;
	S=(queue*)malloc(sizeof(queue));
	Setnull(S);
	S=Q;
	S->rear++;
	S->data[S->rear]=n;
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
queue* Paixu(queue *S){
		int len,i,a,b;
		queue *R,*T;
		R=(queue*)malloc(sizeof(queue));
		T=(queue*)malloc(sizeof(queue));
		Setnull(R);
		Setnull(T);
		R=S;
		len=R->rear-R->front;
		while(len>0)
		{	a=DeQueue(R);
			for(i=0;i<len-1;i++){
			b=DeQueue(R);
			if(a<b){
				EnQueue(R,b);
			}
			else{
				EnQueue(R,a);
				a=b;
			}
		}
			EnQueue(T,a);
			len--;
		}
	return T;
}
int main(){
	int i,k,n;
	queue *R;
	R=(queue*)malloc(sizeof(queue));
	Setnull(R);
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&k);
		EnQueue(R,k);
	}
	Print(Paixu(R));
	return 0;
}

