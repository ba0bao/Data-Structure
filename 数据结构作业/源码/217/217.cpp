#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<conio.h>
#define MAXSIZE 1024
typedef char datetype;
typedef struct{
	datetype date[MAXSIZE];
	int last;
}sequenlist;
sequenlist *L;    

//����˳���
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



/*����*/
int Rmv(sequenlist *L){
	int i,j,k,len;
	len = L->last;
	printf("����������λ��:");
	scanf("%d",&k);
	for(j=0;j<k;j++)
	{
		L->date[len+1] = L->date[len];
		for(i=len;i>0;i--)
		L->date[i] = L->date[i-1];
		L->date[0] = L->date[len+1];
	}
	return 0;
}


void main(){
	int k;
	L=Create();
	Rmv(L);
	Output(L);
}
