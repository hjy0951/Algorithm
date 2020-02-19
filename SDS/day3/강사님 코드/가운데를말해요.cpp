#include<cstdio>
#include<queue>
using namespace std;
int n,t;
priority_queue<int> p,q;
int main(){
    scanf("%d",&n);
    while(n--){
        scanf("%d",&t);
        if(q.empty()||-q.top()<t)q.push(-t);
        else p.push(t);
        if(p.size()>q.size())q.push(-p.top()),p.pop();
        if(q.size()-p.size()>1)p.push(-q.top()),q.pop();
        printf("%d\n",(p.size()+q.size())&1?-q.top():-q.top()>p.top()?p.top():-q.top());
    }
}