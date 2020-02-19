#include<cstdio>
int n,a[25],i,j,s;
char c[101];
void r(int p,int v){
    if(p==n){
        s+=(v==0x3ffffff);
        return;
    }
    r(p+1,v|a[p]);
    r(p+1,v);
}
int main(){
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%s",c);
        for(j=0;c[j];j++)a[i]|=(1<<(c[j]-'a'));
    }
    r(0,0);
    printf("%d",s);
}