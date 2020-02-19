#include<cstdio>
int n,m,d[10000],s,e,a,c,i;
int main(){
	scanf("%d %d",&n,&m);
	for(i=0;i<n;i++)scanf("%d",d+i);
	while(e<=n){
		if(a>m)a-=d[s++];
		else if(a<m)a+=d[e++];
		if(a==m)c++,a+=d[e++];
	}
	printf("%d",c);
}