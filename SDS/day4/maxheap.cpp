// 백준 11279 최대 힙
#include <iostream>
#include <queue>

using namespace std;

priority_queue<long long, vector<long long >, less<long long> > pq;
int n;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;
    for(int i = 0 ; i < n ; i++){
        int x;
        cin >> x;
        if(x == 0){
            if(pq.empty() == true){
                cout << "0" << "\n";
            }
            else{
                cout << pq.top() << "\n";
                pq.pop();
            }
        }
        else pq.push(x);
    }
    return 0;
}