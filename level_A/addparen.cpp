// 백준 16637 괄호 추가하기
#include <iostream>
#include <string>
#include <vector>

using namespace std;
typedef long long int ll;

int n; // 수식의 길이
string str;
// 수식: 0보다 크거나 같고, 9보다 작거나 같은 정수와 연산자(+, -, ×)로 이루어짐
// 수식의 각 연산자는 모두 우선순위가 같음

vector<int> num;
vector<char> op;
ll maxn;

ll cal(ll a, int curop, ll b){
    if(op[curop] == '+'){
        return a+b;
    }
    else if(op[curop] == '-'){
        return a-b;
    }
    else return a*b;
}

void solve(ll result, int curop){
    if(curop >= op.size()){
        if(maxn < result) maxn = result;
        return;
    }
    else{
        // (result -op- num[c+1]) ...
        ll cur = cal(result, curop, num[curop+1]);
        solve(cur, curop + 1);

        // result -op1- (num[c+1] -op2- num[c+2]) ...
        if(curop+1 < op.size()){
            ll cur2 = cal(num[curop+1], curop+1, num[curop+2]);
            solve(cal(result, curop, cur2), curop + 2);
        }
    }
}

int main(){
    maxn = -987987987; // 최대값이 음수가 될 수 있다는 점을 빼먹어서 오래 걸림..

    cin >> n >> str;
    for(int i = 0 ; i < str.size() ; i++){
        // operator와 operand 구분
        if(str[i] == '+' || str[i] == '-' || str[i] == '*') op.push_back(str[i]);
        else num.push_back(str[i] - '0');
    }

    solve(num[0], 0);

    cout << maxn << "\n";

    return 0;
}