#include<cstdio>
#include<queue>
using namespace std;
queue<int> q;
int n,m,k,x,y,z,a,b,c,e,f,o[6][3]={{1,0,0},{0,1,0},{0,0,1},{-1,0,0},{0,-1,0},{0,0,-1}};
char d[52][52][52];
int main(){
    while(1){
        scanf("%d%d%d",&n,&m,&k);
        if(!n)break;
        for(x=1;x<=n;x++)for(y=1;y<=m;y++)scanf("%s",d[x][y]+1);
        for(x=1;x<=n;x++)for(y=1;y<=m;y++)for(z=1;z<=k;z++)if(d[x][y][z]=='S')q.push(x<<12|y<<6|z);y=1;
        while(!q.empty()){
            f=q.front();q.pop();
            c=f&0x3f;f>>=6;
            b=f&0x3f;f>>=6;
            a=f&0x3f;e=f>>6;
            for(x=0;x<6;x++){
                int nx=a+o[x][0];
                int ny=b+o[x][1];
                int nz=c+o[x][2];
                if(d[nx][ny][nz]=='.')q.push(((e+1)<<18|nx<<12|ny<<6|nz)),d[nx][ny][nz]=0;
                if(d[nx][ny][nz]=='E'){
                    printf("Escaped in %d minute(s).\n",e+1);
                    while(!q.empty())q.pop();y=0;
                    break;
                }
            }
        }
        if(y)printf("Trapped!\n");
    }
}