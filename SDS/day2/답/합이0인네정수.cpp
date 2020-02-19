#include<cstdio>
#include<algorithm>
using namespace std;
int n,d[4][4000],e[2][16000000],i,j;
long long s,a,b;
int main(){
    scanf("%d",&n);
    for(i=0;i<n;i++)for(j=0;j<4;j++)scanf("%d",d[j]+i);
    for(i=0;i<n;i++)for(j=0;j<n;j++)e[0][i*n+j]=d[0][i]+d[1][j],e[1][i*n+j]=d[2][i]+d[3][j];
    n*=n;
    sort(e[1],e[1]+n);
    for(i=0;i<n;i++){
        a=lower_bound(e[1],e[1]+n,-e[0][i])-e[1];
        b=upper_bound(e[1],e[1]+n,-e[0][i])-e[1];
        a+=(e[1][a]!=-e[0][i]);
        b-=(b==n||e[1][b]!=-e[0][i]);
        if(b>=a)s+=b-a+1;
    }
    printf("%lld",s);
}