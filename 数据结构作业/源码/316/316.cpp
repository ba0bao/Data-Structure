#include<stdio.h>
#define m 5
char sequ[m];
int rear=-1,quelen=0;
//	队满条件为(quelen==m) 

//入队
void EnSequ(char a[],char r){
	if(quelen==m) printf("Overflow\n");//判断是否队满
	else{
		a[(rear+1+m)%m]=r;
		quelen++;
		rear=(rear+1)%5;
	}
}

//出队
char DeSequ(char a[]){
	char t;
	t=a[(m+rear+1-quelen)%m];
	quelen--;
	return t;
}

//打印队列
Print(char a[]){
	int i,j;
	for(i=rear,j=0;j<quelen;i--,j++)
	{
		printf("%c ",sequ[(i+5)%5]);
	}
	printf("\n");
}
void main(){
///*以下为测试代码
	int i,j;
	EnSequ(sequ,'a');
	EnSequ(sequ,'b');
	EnSequ(sequ,'c');
	EnSequ(sequ,'d');
	EnSequ(sequ,'e');
	Print(sequ);
	EnSequ(sequ,'f');//将提示溢出
	DeSequ(sequ);//'a'出队
	Print(sequ);
	EnSequ(sequ,'f');//此时'f'可入队
	Print(sequ);
//	*/
}