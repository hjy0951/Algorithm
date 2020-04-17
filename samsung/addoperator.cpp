// 백준 14888 연산자 끼워넣기
/*
    N개의 수로 이루어진 수열
    N-1개의 연산자는 덧셈(+), 뺄셈(-), 곱셈(×), 나눗셈(÷)
    식의 계산은 연산자 우선 순위를 무시하고 앞에서부터 진행
    또, 나눗셈은 정수 나눗셈으로 몫만 취한다.
    음수를 양수로 나눌 때 양수로 바꾼 뒤 몫을 취하고, 그 몫을 음수로 바꾼 것
    N개의 수와 N-1개의 연산자가 주어졌을 때, 만들 수 있는 식의 결과가 최대인 것과 최소인 것을 구하는 프로그램
*/
#include <iostream>

#define ll long long int
using namespace std;

int n;
int num[15];
int op[4];
ll maxn;
ll minn;

void rec(int cur, ll res){
    if(cur == n-1){
        if(res > maxn) maxn = res;
        if(res < minn) minn = res;
        return;
    }
    else{
        for(int i = 0 ; i < 4 ; i++){
            if(op[i] == 0) continue;

            op[i]--;
            if(i == 0) rec(cur+1, res + num[cur+1]); // +
            else if(i == 1) rec(cur+1, res - num[cur+1]); // -
            else if(i == 2) rec(cur+1, res * num[cur+1]); // *
            else if(i == 3){ // /
                int temp = res;
                if(temp < 0){
                    temp = temp * (-1);
                    temp = temp / num[cur+1];
                    temp = temp * (-1);
                }
                else{
                    temp = temp / num[cur+1];
                }
                rec(cur+1, temp);
            }
            op[i]++;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for(int i = 0 ; i < n ; i++){
        cin >> num[i];
    }
    for(int i = 0 ; i < 4 ; i++){
        cin >> op[i];
    }

    maxn = -987987987;
    minn = 987987987;

    rec(0,num[0]);

    cout << maxn << "\n";
    cout << minn << "\n";
    return 0;
}
/*
    22:23 ~ 22:38
*/