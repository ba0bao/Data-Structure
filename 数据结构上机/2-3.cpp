#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#define MAXSIZE 1000 

typedef struct node 
{ 
char element[MAXSIZE]; 
int Top; 
} stack; 

stack *S; 

stack *setnull(stack *S){
	S->Top=-1;
	return S;
}

int empty(stack *p){
	if(p->Top>=0)
		return 0;
	else 
		return 1;
}

stack *push(stack *p, char e){
	p->Top++;
	p->element[p->Top]=e;
	return p;
}

char pop(stack *r){
	char p;
	r->Top--;
	p=r->element[r->Top+1];
	return p;
}

int correct(char String[],int len){
	int i;
	char ch;
	for(i=0;i<len;i++){
		ch=String[i];
		if(ch=='['||ch=='(')
			push(S,ch);
		else if(ch-(S->element[S->Top])<3)
			pop(S);
		else
			return 0;
	}
	if(empty(S))
		return 1; 
	else
		return 0;	
}

int main(){ 
	int num,i,len,sign;
	char n[MAXSIZE];
	int s[MAXSIZE];
	S = (stack*)malloc(sizeof(stack));
	S=setnull(S);
	scanf("%d",&num);
	for(i=0;i<num;i++){
		S=setnull(S);
		scanf("%s",n);
		len=strlen(n); 
		sign=correct(n,len);
		if(sign)
			s[i]=1;
		else
			s[i]=0;	
	}
	for(i=0;i<num;i++){
		if(s[i]==0)
			printf("No\n");
		if(s[i]==1)
			printf("Yes\n");
	}
	return 0; 
} 

