#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int main(){
	int m,n,k,l,i,j,t,s=0,flag=1;
	int p[10];
	int q[10];
	int elements[1000];
	int a[1000];
	int b[100][1000];
	scanf("%d %d %d",&m,&n,&k);
	for(i=0;i<n;i++){
		scanf("%d",&elements[i]);
	}
	for(i=0;i<k;i++){
		for(j=0;j<n;j++){
			scanf("%d",&b[i][j]);
		}
	}
	for(i=0,j=0,s=0;i<k;i++){
		t=1;
		q[0]=b[i][0];
		while(j<n-1){
			if(b[i][j]>b[i][j+1]){
				t++;
				j++;
			}
			else{
				p[s++]=t;
				q[s]=b[i][j+1];
				t=1;
				j++;
				continue;
			}
		}
		for(l=0;l<s;l++){
			if(q[l]<q[l+1]) continue; 
			else{
				flag=0;
				printf("NO\n");
				for(l=0;l<10;l++) p[l]=0;
				j=0;s=0;flag=1;
				break;
			}
		}
		if(flag){
			if(t==1) p[s++]=t;
			t=p[0];
			for(l=1;l<s;l++){
				t=(t>=p[l]?t:p[l]);
			}
			if(t<=m) printf("YES\n");
			else printf("NO\n");
			for(l=0;l<10;l++){ p[l]=0;}
			j=0;s=0;flag=1;
			continue;
		}
	}
}
