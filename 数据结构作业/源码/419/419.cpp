#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#define MAXSIZE 100
typedef struct{
	char ch[MAXSIZE];
	int len;
}seqstring;
seqstring *S;

//������
seqstring *Create(){
	int i=0;
	char ch1;
	S=(seqstring*)malloc(sizeof(seqstring));
	S->len=0;
	printf("�����봮�е�Ԫ�أ���#����\n");
	while((ch1=getche())!='#'){
		S->ch[i++]=ch1;
		S->len++;
	}
	S->ch[i]='\0';
	return S;
}

//��ӡ
void Print(seqstring *S){
	int i=0;
	printf("\n");
	while(i<S->len){
		printf("%c",S->ch[i]);
		i++;
	}
	printf("\n");
}

//ɾ��
void Del(seqstring *S,int i,int j){
	int m;
	if(i>S->len || i+j>S->len+1) printf("Error.\n");
	else{
		for(m=i-1;m+j<S->len;m++){
			S->ch[m]=S->ch[m+j];
		}
		S->ch[m]='\0';
		S->len=S->len-j;
	}
}

void main(){
	S=Create();
	Print(S);
	Del(S,2,3);
	Print(S);
}