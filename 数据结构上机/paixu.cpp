#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
int main(){
	int m,t,k,p,i,j;
	int list[100];
	scanf("%d",&m);
	for(i=0;i<m;i++){
		scanf("%d",&list[i]);
	}
	for(i=0;i<m;i++){
		for(j=0;j<m-i-1;j++){
			if(list[j]>list[j+1]){
				t=list[j];
				list[j]=list[j+1];
				list[j+1]=t;
			}
		}
	}
	for(i=0;i<m-1;i++){
		printf("%d ",list[i]);
	}
	printf("%d",list[i]);
	return 0;
}
