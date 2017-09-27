#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#define MAXSIZE 1024

typedef char datetype;
typedef struct
{
	datetype date[MAXSIZE];
	int last;
}sequenlist;
sequenlist *L;

//建立
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

//打印
void Output(sequenlist *L){
	int i;
	printf("\n逆序后顺序表L中的元素为：");
	for(i=0;i<=L->last;i++)
		printf("%c ",L->date[i]);
	printf("\n");
}

//顺序表逆置
void nz(sequenlist *L)
{
	int i,j,len;
	char c;
	len = L->last+1;
	j=L->last;
	for(i=0;i<len/2;i++,j--)
	{
		c=L->date[i];
		L->date[i]=L->date[j];
		L->date[j]=c;
	}
}



void main(){
	L=Create();
	nz(L);
	Output(L);
}