#include<cstdio>
#define M 1040005
int c[M];
int b,x,y,h,s,v,N,i,j,k;
bool e;
int main(){
	scanf("%d",&N);
	for(i=0;i<N;i++){
		scanf("%d %d %d %d",&b,&h,&x,&y);
		v=x*y;
		c[b]+=v;
		c[b+h]-=v;
	}
	scanf("%d",&v);
	for(i=1;i<M;i++){
		s+=c[i-1];
		v-=s;
		if(v==0){
			printf("%d.00",i);
			return 0;
		}
		else if(v<0){
			v+=s;
			i--;
			e=true;
			break;
		}
	}
	if(!e){
		printf("OVERFLOW");
		return 0;
	}
	v*=10,j=v/s,v=(v%s)*10;
	if(v==0){
		printf("%d.%d",i,j);
		return 0;
	}
	k=v/s,v=(v%s)*10;
	if(v==0){
		printf("%d.%d%d",i,j,k);
		return 0;
	}
	if(s*5<=v){
		k++;
		if(k==10){
			k=0,j++;
			if(j==10)j=0,i++;
		}
	}   
	printf("%d.%d%d\n",i,j,k);
}