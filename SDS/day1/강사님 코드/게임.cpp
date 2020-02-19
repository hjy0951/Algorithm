#include<cstdio>
int n,m,i,j,d[50][50],v[50][50],w[50][50],o[4][2]={{1,0},{0,-1},{-1,0},{0,1}};
char t;
int r(int x,int y){
    if(x<0||y<0||x>=n||y>=m||d[x][y]<0)return 0;
    if(v[x][y])return -1;
    if(w[x][y])return w[x][y];
    v[x][y]=1;
    for(int i=0;i<4;i++){
        int a=r(x+o[i][0]*d[x][y],y+o[i][1]*d[x][y]);
        if(a<0)return -1;
        w[x][y]=w[x][y]>a?w[x][y]:a;
    }
    v[x][y]=0;
    return ++w[x][y];
}
int main(){
    scanf("%d%d",&n,&m);
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            scanf("\n%c",&t);
            d[i][j]=t=='H'?-1:t-'0';
        }
    }
    i=r(0,0);
    printf("%d",i>0?i:-1);
}