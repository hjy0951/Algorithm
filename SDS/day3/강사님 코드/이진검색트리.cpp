#include<cstdio>
int d[10000],i;
void r(int s,int e){
    if(s>=i||s>e)return;
    if(s==e){
        printf("%d\n",d[s]);
        return;
    }
    int x=s+1;
    for(;x<=e&&d[x]<d[s];x++);
    r(s+1,x-1);
    r(x,e);
    printf("%d\n",d[s]);
}
int main(){
    while(~scanf("%d",&d[i++]));
    r(0,i-2);
}
