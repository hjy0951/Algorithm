#include<cstdio>
int n,m,k,i,j,d[200][201]={{1,1}},s;
char a[401];
int main(){
    for(i=1;i<200;i++)for(d[i][0]=j=1;j<=i+1;j++){
        s=d[i-1][j-1]+d[i-1][j];
        d[i][j]=s<=1000000000?s:1000000001;
    }
    scanf("%d%d%d",&n,&m,&k);
    n+=m;
    for(s=i=0;i<n-1&&m>-1;i++,m-=s){
        s=d[n-i-2][m]<k;
        a[i]=s?'z':'a';
        k-=d[n-i-2][m]*s;
    }
    a[i]=m?'z':'a';
    if(m<0)printf("-1");
    else printf("%s",a);
}