#include<iostream>
#include<queue>
#include<algorithm>
#include<set>
using namespace std;
int k,l,x,i,j;
string s;
char a;
queue<string>q;
set<string>z;
int main(){
    cin>>s>>k;
    q.push(s);
    while(k--){
        x=q.size();
        z.clear();
        while(x--){
            s=q.front();
            q.pop();
            for(i=0;i<s.length();i++){
                for(j=i+1;j<s.length();j++){
                    string t=s;
                    a=t[i];t[i]=t[j];t[j]=a;
                    if(t[0]!='0'&&z.find(t)==z.end())q.push(t),z.insert(t);
                }
            }
        }
    }
    s="0";
    if(q.empty())printf("-1");
    else{
        while(!q.empty()){
            if(s<q.front())s=q.front();
            q.pop();
        }
        cout<<s;
    }
}
