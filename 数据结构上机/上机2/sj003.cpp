#include<stdio.h>
int main(){
	int i,j,m,s=0,t=0,k,top=-1,flag=0;
	char ss[100][10000];
	char a[10000];
	scanf("%d",&k);
	for(i=0;i<k;i++){
		scanf("%s",&ss[i]);
	}
	for(i=0,flag=0;i<k;i++){
		for(m=0;m<20;m++){
			a[m]=NULL;
		}
		for(j=0,flag=0,s=0,t=0;ss[i][j]!=NULL;j++){
			if(ss[i][j] =='(' || ss[i][j] =='['){
				top++;
				s++;
				a[top]=ss[i][j];
			}
			else{
				top--;
				t++;
				if(top==-2){
					flag=0;
					top=-1;
					break;
				}
				else if(a[top+1]=='('){
					if(ss[i][j]==')'){
						flag=1;
						 continue;
					}
					else{
						flag=0;
						break;
					}
			    }
			    else if(a[top+1]=='['){
			    	if(ss[i][j]==']'){
						flag=1;
						 continue;
					}
					else{
						flag=0;
						break;
					}
				}
			}
		}
		if(flag==1 && (j%2)==0 && s==t){
			   printf("Yes");
			   printf("\n");}
		else {printf("No");
		printf("\n");
		}
	}
	return 0;
}
