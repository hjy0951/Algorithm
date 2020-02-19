#include<iostream>
typedef long long ll;
using namespace std;
ll d[1000001],e[4000002],c;
int n,m,k,a,b;
ll init(int p,int l,int r){
    if(l==r)return e[p]=d[l];
    return e[p]=init(p*2,l,(l+r)/2)+init(p*2+1,(l+r)/2+1,r);
}
void update(int p,int i,int l,int r,ll v){
    if(i<l||i>r)return;
    e[p]+=v;
    if(l!=r){
        update(p*2,i,l,(l+r)/2,v);
        update(p*2+1,i,(l+r)/2+1,r,v);
    }
}
ll sum(int p,int s,int x,int l,ll r){
    if(x<l||s>r)return 0;
    if(l<=s&&r>=x)return e[p];
    return sum(p*2,s,(s+x)/2,l,r)+sum(p*2+1,(s+x)/2+1,x,l,r);
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n>>m>>k;
    m+=k;
    for(a=1;a<=n;a++)cin>>d[a];
    init(1,1,n);
    while(m--){
        cin>>a>>b>>c;
        if(a&1)update(1,b,1,n,c-d[b]),d[b]=c;
        else cout<<sum(1,1,n,b,c)<<"\n";
    }
}