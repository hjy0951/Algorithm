#include<cstdio>
int n,d[500000],answer,i,temp[500000];
long long merge(int s,int e){
	int start=s;
	int end=e;
	long long retval=0;
	if(start==end){
		return 0;
	}
	int mid=(start+end)/2;
	int p=mid+1;
	retval += merge(start,mid);
	retval += merge(mid+1,end);
	int i=0;
	while(start<=mid&&p<=end){
		if(d[start]>d[p]){
			temp[i]=d[p++];
			retval+=(mid-start+1);
		}else{
			temp[i]=d[start++];
		}
		i++;
	}
	while(start<=mid){
		temp[i++]=d[start++];
	}
	while(p<=end){
		temp[i++]=d[p++];
	}
	for(i=0;i<=e-s;i++){
		d[s+i]=temp[i];
	}
	return retval;
}
int main(){
	scanf("%d",&n);
	for(i=0;i<n;i++)scanf("%d",d+i);
	printf("%lld",merge(0,n-1));
}