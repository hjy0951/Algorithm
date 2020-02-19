#include<cstdio>
int n,t,i,j;
long long d[100][21];
int main(){
	scanf("%d %d",&n,&t);
	d[1][t]=1;
	for(i=2;i<n;i++){
		scanf("%d",&t);
		for(j=0;j<21;j++){
			if(d[i-1][j]){
				if(j+t<21)d[i][j+t]+=d[i-1][j];
				if(j-t>=0)d[i][j-t]+=d[i-1][j];
			}
		}
	}
	scanf("%d",&t);
	printf("%lld",d[n-1][t]);
}