// 백준 14395 4연산
/*
    정수 s가 주어진다. 
    정수 s의 값을 t로 바꾸는 최소 연산 횟수를 구하는 프로그램을 작성하시오.
    사용할 수 있는 연산은 아래와 같다.
        1. s = s + s; (출력: +)
        2. s = s - s; (출력: -)
        3. s = s * s; (출력: *)
        4. s = s / s; (출력: /) (s가 0이 아닐때만 사용 가능)

    첫째 줄에 정수 s를 t로 바꾸는 방법을 출력한다. 
    s와 t가 같은 경우에는 0을, 바꿀 수 없는 경우에는 -1을 출력한다. 
    가능한 방법이 여러 가지라면, 사전 순으로 앞서는 것을 출력한다. 
    연산의 아스키 코드 순서는 '*', '+', '-', '/' 
*/
#include <iostream>
#include <queue>
#include <string>
#include <set>

#define ll long long int
using namespace std;

ll s,t;
string ans;

void bfs(){
    queue<ll> q;
    queue<string> opq;
    set<ll> st;
    q.push(s);
    opq.push("");
    st.insert(s);

    while(!q.empty()){
        ll cur = q.front();
        string cop = opq.front();
        q.pop();
        opq.pop();

        // cout << cur << " : " << cop << '\n';
        if(cur == t){
            ans = cop;
            return;
        }
        
        ll next = cur * cur;
        cop.push_back('*');
        if(st.insert(next).second == true){
            q.push(next);
            opq.push(cop);
        }
        cop.pop_back();

        next = cur + cur;
        cop.push_back('+');
        if(st.insert(next).second == true){
            q.push(next);
            opq.push(cop);
        }
        cop.pop_back();

        next = cur - cur;
        cop.push_back('-');
        if(st.insert(next).second == true){
            q.push(next);
            opq.push(cop);
        }
        cop.pop_back();

        if(cur == 0) continue;
        next = cur / cur;
        cop.push_back('/');
        if(st.insert(next).second == true){
            q.push(next);
            opq.push(cop);
        }
        cop.pop_back();
    }
}

int main(){
    cin >> s >> t;
    if(s == t){
        cout << 0 << '\n';
        return 0;
    }
    
    bfs();

    if(ans.size() == 0) cout << "-1\n";
    else cout << ans << '\n';
    return 0;
}