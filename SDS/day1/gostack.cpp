// 백준 : 고스택 3425번
// 단순 구현 문제
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <stack>
#include <vector>

using namespace std;

#define LIM 1000000000

stack<long long int> stk;
int cnt;
char op[100000];
vector<long long int> num;
int ncnt;

int num_x(int x){ // push
    stk.push(x);
    return 1;
}
int pop(){
    if(stk.empty() == true) return 0;

    stk.pop();
    return 1; // complete
}
int inv(){
    if(stk.empty() == true) return 0; // 연산할 숫자 X
    
    long long int x = stk.top() * (-1);
    stk.pop();
    stk.push(x);

    return 1;
}
int dup(){
    if(stk.empty() == true) return 0;// 연산할 숫자 X

    stk.push(stk.top());
    return 1;
}
// binary operation
int swp(){ // a <-> b
    if(stk.empty() == true) return 0;
    long long int a = stk.top();
    stk.pop();

    if(stk.empty() == true) return 0;
    long long int b = stk.top();
    stk.pop();
    
    stk.push(a);
    stk.push(b);

    return 1;
}
int add(){ // a + b
    if(stk.empty() == true) return 0;
    long long int a = stk.top();
    stk.pop();

    if(stk.empty() == true) return 0;
    long long int b = stk.top();
    stk.pop();

    long long int ans = a + b;
    // if(abs(ans) > LIM) return 0; // 연산 결과가 10^9 을 넘는 경우

    stk.push(ans);
    return 1;
}
int sub(){ // b - a
    if(stk.empty() == true) return 0;
    long long int a = stk.top();
    stk.pop();

    if(stk.empty() == true) return 0;
    long long int b = stk.top();
    stk.pop();

    long long int ans = b - a;
    // if(abs(ans) > LIM) return 0; // 연산 결과가 10^9 을 넘는 경우

    stk.push(ans);
    return 1;
}
int mul(){ // a * b
    if(stk.empty() == true) return 0;
    long long int a = stk.top();
    stk.pop();

    if(stk.empty() == true) return 0;
    long long int b = stk.top();
    stk.pop();

    long long int ans = a*b;
    if(abs(ans) > LIM) return 0; // 연산 결과가 10^9 을 넘는 경우

    stk.push(ans);
    return 1;
}
int div(){ // b / a
    int m = 0;

    if(stk.empty() == true) return 0;
    long long int a = stk.top();
    stk.pop();

    if(a == 0) return 0; // 0으로 나누는 경우
    
    if(a < 0){
        m++;
        a = a*(-1);
    }

    if(stk.empty() == true) return 0;
    long long int b = stk.top();
    stk.pop();
    
    if(b < 0){
        m++;
        b = b*(-1);
    }

    long long int ans = abs(b/a);
    if(m == 1) ans = ans*(-1);
    stk.push(ans);

    return 1;
}
int mod(){ // b % a
    int m = 0;

    if(stk.empty() == true) return 0;
    long long int a = stk.top();
    stk.pop();

    if(a == 0) return 0; // 0으로 나누는 경우

    if(a < 0){
        a = a*(-1);
    }

    if(stk.empty() == true) return 0;
    long long int b = stk.top();
    stk.pop();

    if(b < 0){
        m++;
        b = b*(-1);
    }

    long long int ans = abs(b%a);
    if(m == 1) ans = ans * (-1);
    stk.push(ans);

    return 1;
}

int main(){
    while(1){
        // 명령
        ncnt = 0; // 숫자 개수
        cnt = 0; // 명령 개수
        while(1){
            char com[5];
            scanf(" %s", com);

            if(strcmp(com, "END") == 0) break;  // 명령어 입력 종료
            else if(strcmp(com, "QUIT") == 0){  // 기계 종료
                return 0;
            }
            else{
                if(strcmp(com, "NUM") == 0){
                    op[cnt++] = 1;
                    long long int p;
                    scanf(" %d", &p);
                    num.push_back(p);
                }
                else if(strcmp(com, "POP") == 0) op[cnt++] = 2;
                else if(strcmp(com, "INV") == 0) op[cnt++] = 3;
                else if(strcmp(com, "DUP") == 0) op[cnt++] = 4;
                else if(strcmp(com, "SWP") == 0) op[cnt++] = 5;
                else if(strcmp(com, "ADD") == 0) op[cnt++] = 6;
                else if(strcmp(com, "SUB") == 0) op[cnt++] = 7;
                else if(strcmp(com, "MUL") == 0) op[cnt++] = 8;
                else if(strcmp(com, "DIV") == 0) op[cnt++] = 9;
                else if(strcmp(com, "MOD") == 0) op[cnt++] = 10;
            }
        }

        // 연산 숫자
        int n;
        scanf(" %d" , &n);

        for(int i = 0 ; i < n ; i++){
            long long int operand;
            scanf(" %d", &operand); // 연산 숫자 입력
            
            //
            stk.push(operand);
            int nidx = 0;
            int res = 1;

            for(int i = 0 ; i < cnt ; i++){
                res = 1;

                switch(op[i]){
                    case 1: // num_x
                        res = num_x(num[nidx]);
                        ++nidx;
                        break;
                    case 2: // pop
                        res = pop();
                        break;
                    case 3: // inv
                        res = inv();
                        break;
                    case 4: // dup
                        res = dup();
                        break;
                    case 5: // swp
                        res = swp();
                        break;
                    case 6: // add
                        res = add();
                        break;
                    case 7: // sub
                        res = sub();
                        break;
                    case 8: // mul
                        res = mul();
                        break;
                    case 9: // div
                        res = div();
                        break;
                    case 10: // mod
                        res = mod();
                        break;
                }

                if(!stk.empty() && (stk.top() > LIM || stk.top() < -LIM)) res = 0;
                if(res == 0) break;
            }

            if(stk.size() != 1 || res == 0){
                printf("ERROR\n");
            }
            else printf("%lld\n", stk.top());

            while(!stk.empty()){
                stk.pop();
            } // 스택 비우기
            //
        }
        num.clear();
        printf("\n");
    }
    return 0;
}

/*

DUP
MUL
NUM 2
ADD
END
3
1
10
50

NUM 1
NUM 1
ADD
END
2
42
43

NUM 600000000
ADD
END
3
0
600000000
1

QUIT


NUM 3
DUP
MUL
NUM 15
SWP
MOD
ADD
END
1
42

QUIT
*/
