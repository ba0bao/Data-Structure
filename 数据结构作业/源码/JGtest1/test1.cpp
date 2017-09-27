#include <stdio.h>
#include<stdlib.h>
#include<conio.h>
#define MAXSIZE 1024
typedef char datetype;
typedef struct{
	datetype date[MAXSIZE];
	int last;
}sequenlist;
sequenlist *L;


sequenlist *Create(){
	int i=0;
	char ch;
	L=(sequenlist*)malloc(sizeof(sequenlist));
	L -> last = -1;
	printf("请输入顺序表L中的元素，以‘#’结束。\n");
	while((ch=getche())!='#'){
		L -> date[i++]=ch;
		L ->last++;
	}
	return L;
}


int Insert(sequenlist *L,char x,int i){
	int j;
	if((L->last)>=MAXSIZE-1){
		printf("overflow\n");
		return 0;
	}
	else
		if((i<1)||(i>(L->last)+2)){
			printf("error\n");
			return 0;
		}
		else{
			for(j=L->last;j>=i-1;j--)
				L->date[j+1]=L->date[j];
				L->date[i-1]=x;
				L->last=L->last+1;
		}
	return 1;
}


void Output(sequenlist *L){
	int i;
	printf("\n顺序表L中的元素为：");
	for(i=0;i<=L->last;i++)
		printf("%c",L->date[i]);
	printf("\n");
}


void main(){
	char ch;
	int i,ret;
	L=Create();
/*	printf("\n请输入插入字符：");
	scanf("%c",&ch);
	printf("\n请输入插入位置：");
	scanf("%d",&i);
	ret=Insert(L,ch,i);
	if(ret)*/
		Output(L);
	printf("\n%d",L->last);
}