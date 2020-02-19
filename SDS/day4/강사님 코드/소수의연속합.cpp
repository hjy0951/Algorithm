#include<cstdio>
#include<vector>
using namespace std;
int n,d[4000001],i,j,s=2,a,l,r;
vector<int> v;
int main(){
    scanf("%d",&n);
    for(i=2;i*i<=n;i++)for(j=2;i*j<=n;j++)d[i*j]=1;
    for(i=2;i<=n;i++)if(!d[i])v.push_back(i);
    while(r<v.size()){
        if(s<n){if(r+1==v.size())break;s+=v[++r];}
        else if(s>n){s-=v[l++];}
        else{a++,s+=v[++r];}
    }
    printf("%d",a);
}
