#include<stdio.h>
#define m 5
char sequ[m];
int rear=-1,quelen=0;
//	��������Ϊ(quelen==m) 

//���
void EnSequ(char a[],char r){
	if(quelen==m) printf("Overflow\n");//�ж��Ƿ����
	else{
		a[(rear+1+m)%m]=r;
		quelen++;
		rear=(rear+1)%5;
	}
}

//����
char DeSequ(char a[]){
	char t;
	t=a[(m+rear+1-quelen)%m];
	quelen--;
	return t;
}

//��ӡ����
Print(char a[]){
	int i,j;
	for(i=rear,j=0;j<quelen;i--,j++)
	{
		printf("%c ",sequ[(i+5)%5]);
	}
	printf("\n");
}
void main(){
///*����Ϊ���Դ���
	int i,j;
	EnSequ(sequ,'a');
	EnSequ(sequ,'b');
	EnSequ(sequ,'c');
	EnSequ(sequ,'d');
	EnSequ(sequ,'e');
	Print(sequ);
	EnSequ(sequ,'f');//����ʾ���
	DeSequ(sequ);//'a'����
	Print(sequ);
	EnSequ(sequ,'f');//��ʱ'f'�����
	Print(sequ);
//	*/
}