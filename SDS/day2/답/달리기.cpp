#include<cstdio>
struct s{
    int i,a;
}d[500000],t[500000];
int n,i,a[500000];
void m(int s,int e){
    if(s==e)return;
    int c=(s+e)/2;
    int l=s,r=c+1,p=0;
    m(s,c);m(r,e);
    while(l<=c&&r<=e){
        if(d[l].a>d[r].a)t[p++]=d[l++];
        else a[d[r].i]+=(r-s-p>0)?r-s-p:0,t[p++]=d[r++];
    }
    while(l<=c)t[p++]=d[l++];
    while(r<=e)a[d[r].i]+=(r-s-p>0)?r-s-p:0,t[p++]=d[r++];
    for(l=s;l<=e;l++)d[l]=t[l-s];
}
int main(){
    scanf("%d",&n);
    for(i=0;i<n;i++)scanf("%d",&d[i].a),d[i].i=i;
    m(0,n-1);
    for(i=0;i<n;i++)printf("%d\n",i-a[i]+1);
}