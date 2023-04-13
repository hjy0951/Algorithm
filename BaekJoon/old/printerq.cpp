// 백준 1966 프린터큐
#include <iostream>
#include <algorithm>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

int n,m;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while(t--){
        cin >> n >> m;
        queue<pair<int,int> > q;
        vector<int> p;
        for(int i = 0 ; i < n ; i++){
            int s;
            cin >> s;
            q.push(make_pair(s,i));
            p.push_back(s);
        }

        int cnt = 0;
        sort(p.begin(), p.end(), greater<int>());

        while(!q.empty()){
            int cs = q.front().first;
            int cd = q.front().second;
            q.pop();

            if(cs == p[cnt]){
                cnt++;
                if(cd == m){
                    cout << cnt << "\n";
                    break;
                }
            }
            else{
                q.push(make_pair(cs,cd));
            }
        }
    }

    return 0;
}