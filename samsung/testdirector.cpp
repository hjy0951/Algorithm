// 백준 13458 시험감독
/*
    총 N개의 시험장
    각각의 시험장마다 응시자들이 있다. i번 시험장에 있는 응시자의 수는 Ai명이다.
    총감독관은 한 시험장에서 감시할 수 있는 응시자의 수가 B명이고, 부감독관은 한 시험장에서 감시할 수 있는 응시자의 수가 C명이다.
    각각의 시험장에 총감독관은 오직 1명만 있어야 하고, 부감독관은 여러 명 있어도 된다.
    각 시험장마다 응시생들을 모두 감시해야 한다.
    이때, 필요한 감독관 수의 최솟값을 구하는 프로그램
*/
#include <iostream>
#include <vector>

#define ll long long int

using namespace std;

int n; // N개의 시험장
int b,c; // 총감독관 감시 응시자의 수 B명 | 부감독관은 감시 응시자의 수 C명
vector<int> a;
ll cnt;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n;
    for(int i = 0 ; i < n ; i++){
        int num;
        cin >> num;
        a.push_back(num);
    }
    cin >> b >> c;

    for(int i = 0 ; i < n ; i++){
        int cur = a[i];
        cur -= b;
        cnt++;

        if(cur > 0){
            if(cur%c == 0) cnt+= cur/c;
            else cnt += cur/c + 1;
        }
    }
    cout << cnt << "\n";
    return 0;
}

/*
    13:25 ~ 13:35
*/