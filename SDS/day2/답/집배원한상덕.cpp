#include<cstdio>
#include<vector>
#include<algorithm>
#include<string.h>
using namespace std;
int n,i,j,d[52][52],x,y,c,a=1000001,o[8][2]={{1,0},{0,1},{-1,0},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}},w[52][52];
char e[52][52];
vector<int>v;
int r(int x,int y){
    if(d[x][y]<v[i]||d[x][y]>v[j]||w[x][y])return 0;
    w[x][y]=1;
    int s=e[x][y]=='K';
    for(int k=0;k<8;k++)s+=r(x+o[k][0],y+o[k][1]);
    return s;
}
int main(){
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%s",e[i]+1);
        for(j=1;j<=n;j++){
            if(e[i][j]=='P')x=i,y=j;
            if(e[i][j]=='K')c++;
        }
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            scanf("%d",d[i]+j);
            v.push_back(d[i][j]);
        }
    }
    sort(v.begin(),v.end());
    i=j=0;
    while(i<v.size()&&j<v.size()){
        memset(w,0,sizeof(w));
        if(r(x,y)==c){
            a=v[j]-v[i]>a?a:v[j]-v[i];
            i++;
        }else j++;
    }
    printf("%d",a);
}