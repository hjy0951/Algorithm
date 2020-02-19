#include<cstdio>
#include<queue>
using namespace std;
int n,m,i,d[100];
long long c;
priority_queue<long long> q;
int main(){
    scanf("%d%d",&n,&m);
    for(i=0;i<n;i++)scanf("%d",d+i),q.push(-d[i]);
    while(--m){
        c=q.top();q.pop();
        for(i=0;i<n;i++){
            q.push(c*d[i]);
            if(!(c%d[i]))break;
        }
    }
    printf("%lld",-q.top());
}