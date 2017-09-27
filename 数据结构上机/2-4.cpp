#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#define MAXSIZE 100 

//Ê¹ÓÃË³ÐòÕ» 
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
	int mid,i;
	char ch;
	mid=(len-1)/2+1;
	if(len==1||len==0)
		return 1;
	for(i=mid;i<len;i++){
		ch=String[i];
		push(S,ch);
	}
	if((len%2)!=0){
		mid=mid-1;
	}
	for(i=0;i<mid;i++){
		ch=pop(S);
		if(ch!=String[i])
			return 0;
	}
	return 1;
}

int main() 
{ 
int sign; 
int len; 
char str[100];
S = (stack*)malloc(sizeof(stack)); 
S=setnull(S);
gets(str); 
len=strlen(str); 

sign=correct(str,len); 

if (sign) 
printf("right\n"); 
else 
printf("wrong\n"); 
return 0; 
} 

