// 백준 1021 회전하는 큐
// lower_bound는 오름차순으로 정렬된 경우에만 사용한다는 점 기억
#include <iostream>
#include <deque>
#include <vector>

using namespace std;

int n,m;
deque<int> dq;
vector<int> seq;
int cnt;

void print(){
    cout << "\n";
    for(int i = 0 ; i < dq.size() ; i++){
        cout << dq[i] << " ";
    }
    cout << "\n";
}
void pop(){
    if(dq.size() <= 0) return;
    dq.pop_front();
}
void l(){
    if(dq.size() <= 1) return;
    int temp = dq.front();
    dq.pop_front();
    dq.push_back(temp);
}
void r(){
    if(dq.size() <= 1) return;
    int temp = dq.back();
    dq.pop_back();
    dq.push_front(temp);
}
int find(int x){
    for(int i = 0 ; i < dq.size() ; i++){
        if(dq[i] == x) return i;
    }
    return -1;
}

void solve(){
    for(int i = 0 ; i < m ; i++){
        int idx = find(seq[i]);

        if(idx == 0 && dq[idx] == seq[i]){
            pop();
            continue;
        }

        if(idx > dq.size()/2){ // 위치가 오른쪽 끝에 가까운 경우 => Right shift
            while(dq[0] != seq[i]){
                r();
                cnt++;
            }
            pop();
        }
        else{ // 위치가 왼쪽 끝에 가까운 경우 => Left shift
            while(dq[0] != seq[i]){
                l();
                cnt++;
            }
            pop();
        }
    }
}

int main(){
    cin >> n >> m;
    for(int i = 0 ; i < m ; i++){
        int a;
        cin >> a;
        seq.push_back(a);
    }

    for(int i = 1 ; i <= n ; i++){
        dq.push_back(i);
    }

    solve();

    cout << cnt << "\n";
    
    return 0;
}
/*
10 3
2 9 5

1 2 3 4 5 6 7 8 9 10
2 3 4 5 6 7 8 9 10 1 - 1 : L
3 4 5 6 7 8 9 10 1 - 1 : L P
1 3 4 5 6 7 8 9 10 - 2 : L P R
10 1 3 4 5 6 7 8 9 - 3 : L P R R
9 10 1 3 4 5 6 7 8 - 4 : L P R R R
10 1 3 4 5 6 7 8 - 4 : L P R R R P
8 10 1 3 4 5 6 7 - 5 : L P R R R P R
7 8 10 1 3 4 5 6 - 6 : L P R R R P R R
6 7 8 10 1 3 4 5 - 7 : L P R R R P R R R
5 6 7 8 10 1 3 4 - 8 : L P R R R P R R R R
6 7 8 10 1 3 4 - 8 : L P R R R P R R R R P
= 8
*/