#include<iostream>
using namespace std;
int n,a,b,c,d[4000004];
void u(int p,int l,int r,int x,int v){
    if(l>x||r<x)return;
    d[p]+=v;
    if(l!=r)u(p*2,l,(l+r)/2,x,v),u(p*2+1,(l+r)/2+1,r,x,v);
}
int f(int p,int l,int r,int v){
    d[p]--;
    if(l==r)return l;
    if(d[p*2]<v)return f(p*2+1,(l+r)/2+1,r,v-d[p*2]);
    else return f(p*2,l,(l+r)/2,v);
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    while(n--){
        cin>>a;
        if(a&1){
            cin>>b;
            cout<<f(1,1,1000000,b)<<"\n";
        }else{
            cin>>b>>c;
            u(1,1,1000000,b,c);
        }
    }
}