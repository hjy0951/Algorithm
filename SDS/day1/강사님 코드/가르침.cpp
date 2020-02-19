#include<cstdio>
int n,m,d[50][26],i,j,a,b[26];
char s[16];
void r(int x,int y){
    if(y<1){
        int t=0;
        for(int i=0;i<n;i++){
            int c=1;
            for(int j=0;j<26;j++){
                if(!b[j]&&d[i][j]){
                    c=0;
                    break;
                }
            }
            t+=c;
        }
        a=a>t?a:t;
        return;
    }
    if(x<0)return;
    if(x!=0&&x!=2&&x!=8&&x!=13&&x!=19){
        b[x]=1;
        r(x-1,y-1);
        b[x]=0;
    }
    r(x-1,y);
}
int main(){
    b[0]=b[2]=b[8]=b[13]=b[19]=1;
    scanf("%d%d",&n,&m);
    for(i=0;i<n;i++){
        scanf("%s",s);
        for(j=0;s[j];j++)d[i][s[j]-'a']++;
    }
    r(25,m-5);
    printf("%d",m<5?0:a);
}