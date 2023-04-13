// 백준 2251 물통
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

int a,b,c;
vector<int> ans;
bool num[201];
bool ox[201][201];

void bfs(){
    queue<int> aq;
    queue<int> bq;
    queue<int> cq;
    aq.push(0);
    bq.push(0);
    cq.push(c);

    while(!aq.empty()){
        int ca = aq.front();
        int cb = bq.front();
        int cc = cq.front();
        aq.pop();
        bq.pop();
        cq.pop();
        int ta = ca;
        int tb = cb;
        int tc = cc;

        if(ox[ca][cb] == true) continue;
        ox[ca][cb] = true;
        
        // cout << ca << " , " << cb << " , " << cc << "\n";

        if(ca == 0 && num[cc] == false){
            num[cc] = true;
            ans.push_back(cc);
            // cout << cc << '\n';
        }

        // a에 붓는 경우
        if(ca < a){
            if(cb > 0){
                if(cb > a-ca){
                    cb -= a-ca;
                    ca = a;

                    aq.push(ca);
                    bq.push(cb);
                    cq.push(cc);
                }
                else{
                    ca += cb;
                    cb = 0;

                    aq.push(ca);
                    bq.push(cb);
                    cq.push(cc);
                }
            }
            ca = ta;
            cb = tb;
            cc = tc;
            if(cc > 0){
                if(cc > a-ca){
                    cc -= a-ca;
                    ca = a;

                    aq.push(ca);
                    bq.push(cb);
                    cq.push(cc);
                }
                else{
                    ca += cc;
                    cc = 0;

                    aq.push(ca);
                    bq.push(cb);
                    cq.push(cc);
                }
            }
        }
        ca = ta;
        cb = tb;
        cc = tc;
        // b에 붓는 경우
        if(cb < b){
            if(ca > 0){
                if(ca > b-cb){
                    ca -= b-cb;
                    cb = b;

                    aq.push(ca);
                    bq.push(cb);
                    cq.push(cc);
                }
                else{
                    cb += ca;
                    ca = 0;

                    aq.push(ca);
                    bq.push(cb);
                    cq.push(cc);
                }
            }
            ca = ta;
            cb = tb;
            cc = tc;
            if(cc > 0){
                if(cc > b-cb){
                    cc -= b-cb;
                    cb = b;

                    aq.push(ca);
                    bq.push(cb);
                    cq.push(cc);
                }
                else{
                    cb += cc;
                    cc = 0;

                    aq.push(ca);
                    bq.push(cb);
                    cq.push(cc);
                }
            }
        }
        ca = ta;
        cb = tb;
        cc = tc;
        // c에 붓는 경우
        if(cc < c){
            if(ca > 0){
                if(ca > c-cc){
                    ca -= c-cc;
                    cc = c;

                    aq.push(ca);
                    bq.push(cb);
                    cq.push(cc);
                }
                else{
                    cc += ca;
                    ca = 0;

                    aq.push(ca);
                    bq.push(cb);
                    cq.push(cc);
                }
            }
            ca = ta;
            cb = tb;
            cc = tc;
            if(cb > 0){
                if(cb > c-cc){
                    cb -= c-cc;
                    cc = c;

                    aq.push(ca);
                    bq.push(cb);
                    cq.push(cc);
                }
                else{
                    cc += cb;
                    cb = 0;

                    aq.push(ca);
                    bq.push(cb);
                    cq.push(cc);
                }
            }
        }
        
    }
}

int main(){
    cin >> a >> b >> c;
    bfs();

    sort(ans.begin(), ans.end());
    for(int i = 0 ; i < ans.size() ; i++){
        cout << ans[i] << ' ';
    }
    cout << '\n';

    return 0;
}