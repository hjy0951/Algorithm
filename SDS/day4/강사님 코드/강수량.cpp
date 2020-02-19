#include<cstdio>
#include<vector>
#define pii pair<int,int>
using namespace std;
int n,m,i,d[200000],a,b,t,x,y,z,ex,ey;
vector<int>e,f;
int max(int a,int b){return a<b?b:a;}
int init(int p,int l,int r){
    if(l==r)return d[p]=f[l];
    return d[p]=max(init(p*2,l,(l+r)/2),init(p*2+1,(l+r)/2+1,r));
}
int q(int p,int l,int r,int x,int y){
    if(x>y||r<x||l>y)return 0;
    if(l>=x&&r<=y)return d[p];
    return max(q(p*2,l,(l+r)/2,x,y),q(p*2+1,(l+r)/2+1,r,x,y));
}
int main(){
    scanf("%d",&n);
    for(i=0;i<n;i++)scanf("%d%d",&x,&y),e.push_back(x),f.push_back(y);
    init(1,0,n-1);
    scanf("%d",&m);
    while(m--){
        scanf("%d%d",&a,&b);
        x=lower_bound(e.begin(),e.end(),a)-e.begin();
        y=lower_bound(e.begin(),e.end(),b)-e.begin();
        ex=x<n&&e[x]==a;
        ey=y<n&&e[y]==b;
        t=lower_bound(e.begin(),e.end(),a+1)-e.begin();
        z=q(1,0,n-1,t,y-1);
        if((ey&&ex&&f[x]<f[y])||(ey&&z>=f[y])||(ex&&z>=f[x]))printf("false\n");
        else if(ex&&ey&&y-x==b-a)printf("true\n");
        else printf("maybe\n");
    }
}