// 백준 2529 부등호
#include <iostream>
#include <algorithm>

using namespace std;
typedef long long int ll;

int n;
char str[20];
int num[10];
int ans[15];
ll minn,maxn;

void dfs(int idx){
    if(idx >= n+1){
        ll temp = 0;
        ll std = 1;
        for(int i = n ; i >= 0 ; i--){
            temp += ans[i] * std;
            std = std * 10;
        }

        maxn = max(maxn, temp);
        minn = min(minn, temp);
        return;
    }
    else{
        char op = str[idx];
        if(op == '<'){
            for(int i = ans[idx-1] + 1 ; i < 10 ; i++){
                if(num[i] == 1) continue;

                num[i] = 1;
                ans[idx] = i;
                dfs(idx+1);
                ans[idx] = 0;
                num[i] = 0;
            }
        }
        else if(op == '>'){
            for(int i = ans[idx-1] - 1 ; i >= 0 ; i--){
                if(num[i] == 1) continue;

                num[i] = 1;
                ans[idx] = i;
                dfs(idx+1);
                ans[idx] = 0;
                num[i] = 0;
            }
        }
    }
}

int main(){
    minn = 9879879879;
    maxn = -1;
    cin >> n;
    for(int i = 1 ; i <= n ; i++){
        cin >> str[i];
    }

    for(int i = 0 ; i < 10 ; i++){
        num[i] = 1;
        ans[0] = i;
        dfs(1);
        num[i] = 0;
        ans[0] = 0;
    }

    ll std = 1;
    for(int i  = 0 ; i < n ; i++){
        std = std * 10;
    }
    if(maxn < std) cout << "0";
    cout << maxn << "\n";
    if(minn < std) cout << "0";
    cout << minn << "\n";
    return 0;
}

/*
9
> > > > > < < < <

9876501234
5432106789
*/