// 백준 14888 연산자 끼워넣기
#include <iostream>
#include <cstring>

using namespace std;

int N; // 숫자 개수
int op[4]; // 연산자 저장
int num[15]; // 숫자 저장
int maxn, minn; // 최댓값 최솟값

int operation(int res, int cop, int n){
    int temp;

    switch(cop){
        case 0 : // +
            temp = res + n;
            break;
        case 1 : // -
            temp = res - n;
            break;
        case 2 : // *
            temp = res * n;
            break;
        case 3 : // /
            temp = res / n;
            break;
    }

    return temp;
}

void makenum(int res, int next, int cop){
    if(next >= N-1){
        int temp = operation(res, cop, num[next]);

        if(maxn < temp){
            maxn = temp;
        }
        if(minn > temp){
            minn = temp;
        }

        // cout << "maxn : " << maxn << endl;
        // cout << "minn : " << minn << endl;

        return;
    }
    else{
        int temp = operation(res, cop, num[next]);

        for(int j = 0 ; j < 4 ; j++){
            if(op[j] > 0){
                op[j]--; // 연산자 사용
                makenum(temp, next+1, j); // 숫자 만들기
                op[j]++; // 연산자 복구
            }
        }
    }
}

int main(){
    maxn = -98798790;
    minn = 987987987;
    memset(num,0,sizeof(num)); // init

    cin >> N; // 숫자 개수 입력

     // 숫자 입력
    for(int j = 0 ; j < N ; j++){
        cin >> num[j];
    }
    
    // 연산자 입력 + - * / 순
    for(int j = 0 ; j < 4 ; j++){
        cin >> op[j];
    }

    for(int j = 0 ; j < 4 ; j++){
        if(op[j] > 0){
            op[j]--; // 연산자 사용
            makenum(num[0], 1, j); // 숫자 만들기
            op[j]++; // 연산자 복구
        }
    }

    cout << maxn << endl;
    cout << minn << endl;

    return 0;
}
/*
3
5
2 1 0 1
3 5 3 7 9
6
4 1 0 0
1 2 3 4 5 6 
5
1 1 1 1
9 9 9 9 9 
*/
