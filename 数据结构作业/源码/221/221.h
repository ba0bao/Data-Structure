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

//����
sequenlist *Create(){
	int i=0;
	char ch;
	L=(sequenlist*)malloc(sizeof(sequenlist));
	L -> last = -1;
	printf("������˳���L�е�Ԫ�أ��ԡ�#��������\n");
	while((ch=getche())!='#'){
		L -> date[i++]=ch;
		L ->last++;
	}
	return L;
}

//��ӡ
void Output(sequenlist *L){
	int i;
	printf("\n˳���L�е�Ԫ��Ϊ��");
	for(i=0;i<=L->last;i++)
		printf("%c ",L->date[i]);
	printf("\n");
}

//����
void nz(sequenlist *L)
{
	int i=0;
	len = L->last;
	while(i<len/2)
	{
		L->date[i++]=L->date[len--];
	}
}

void main(){
	L=Create();
	nz(L);
	Output(L);
}