#include<cstdio>
int h,w,n,i,j,d[1000][1000],e[1001][1001];
int main(){
    scanf("%d%d%d",&h,&w,&n);
    e[0][0]=n-1;
    for(i=0;i<h;i++)for(j=0;j<w;j++){
        scanf("%d",d[i]+j);
        e[i+1][j]+=((e[i][j]>>1)+(e[i][j]&1)*(d[i][j]==0));
        e[i][j+1]+=((e[i][j]>>1)+(e[i][j]&1)*d[i][j]);
        d[i][j]^=(e[i][j]&1);
    }
    i=j=0;
    while(i<h&&j<w)d[i][j]?j++:i++;
    printf("%d %d",i+1,j+1);
}