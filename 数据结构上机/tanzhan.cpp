#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct Stack{
	int elements[100];
	int Top;
};
struct Stack *SetNull(struct Stack *S){
	S->Top=-1;
	return S;
}
int IsEmpty(struct Stack *S){
	if(S->Top>=0)
	return 0;
	else return 1;
}
struct Stack *Push(struct Stack *S,int e){
	if(S->Top>=100-1){
		printf("Stack Overflow\n");
		return NULL;
	}
	else{
		S->Top++;
		S->elements[S->Top]=e;
	}
	return S;
}
int *Pop(struct Stack *S){
	int *ret;
	if(IsEmpty(S)){
		printf("Stack Underflow\n");
		return NULL;
	}
	else{
		S->Top--;
		ret=(int*)malloc(sizeof(int));
		*ret=S->elements[S->Top+1];
		return ret;
	}
}

int main(){
	int m,n,k,p,t,i,j,flag;
	int data[100],check[20][100];
	struct Stack *P;
	P=(struct Stack *)malloc(sizeof(struct Stack));
	SetNull(P);
	scanf("%d %d %d",&m,&n,&k);
	for(i=0;i<n;i++){
		scanf("%d",&data[i]);
	}
	for(j=0;j<k;j++){
		for(i=0;i<n;i++){
			scanf("%d",&check[j][i]);
		}
	}
	for(i=0,j=0,t=0,p=0,flag=1;i<k;i++,j=0,t=0,p=0,flag=1){
		Push(P,data[j]);
		j++;
		t++;
		while(p<n){
			if(IsEmpty(P)){
				Push(P,data[j]);
				j++;
				t++;
				if(t>m){
					flag=0;
					break;
				}
				else
					continue;
			}
			else if(check[i][p]>P->elements[P->Top]){
				Push(P,data[j]);
				j++;
				t++;
				if(t>m){
					flag=0;
					break;
				}
				else
					continue;
			}
			else if(check[i][p]=P->elements[P->Top]){
				Pop(P);
				p++;
				t=0;
				continue;
			}
			else if(check[i][p]<P->elements[P->Top]){
				flag=0;
				break;
			}
		}
		if(flag) printf("YES\n");	
		else printf("NO\n");
	}	
	return 0;
}








