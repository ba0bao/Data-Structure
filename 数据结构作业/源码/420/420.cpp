#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
typedef struct linknode{
	char data;
	struct linknode *next;
}linkstring;

linkstring *S;

//����һ����
linkstring *Create(){
	char ch;
	linkstring *head,*s,*r;
	head=(linkstring*)malloc(sizeof(linkstring));
	r=head;
	printf("�����봮�е�Ԫ�أ���#����\n");
	while((ch=getche())!='#'){
		s=(linkstring*)malloc(sizeof(linkstring));
		s->data=ch;
		r->next=s;
		r=s;
	}
	s=(linkstring*)malloc(sizeof(linkstring));
		s->data='\n';
		r->next=s;
		r=s;
	r->next=NULL;
	return head;
}

//��ӡ
void Output(linkstring *head)
{
	linkstring *t;
	t=head->next;
	printf("\n");
	while(t->next!=NULL)
	{		
		printf("%c",t->data);
		t=t->next;
	}
	printf("%c\n",t->data);
}

//�滻
void Replace(linkstring *S,char s,char c){
	linkstring *p;
	p=S;
	do{
		if(p->data==s){
			p->data=c;
		}
		p=p->next;
	}
	while(p->next!=NULL);
}

void main(){
	char m,n;
	S=Create();
	Output(S);
	printf("����������Ҫ���滻���ַ����滻����ַ�\n");
	m=getche();
	n=getche();
	Replace(S,m,n);
	Output(S);
}