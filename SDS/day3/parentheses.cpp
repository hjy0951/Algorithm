// 백준 2504 괄호의 값
#include <iostream>
#include <stack>
#include <cstdio>
#include <cstring>

using namespace std;

char str[30];
stack<int> s;
int len;
int sum;

int main(){
    scanf("%s", str);
    len = strlen(str);
    sum = 0;

    for(int i = 0 ; i < len ; i++){
        int cur = str[i];

        if(s.empty() == true && (cur == ')' || cur == ']')){
            cout << "0" << "\n";
            return 0;
        }

        if(cur == '(' || cur == '[') s.push(cur);
        else{
            if(cur == ')'){
                int temp = 0;
                while(1){
                    int x = s.top();
                    s.pop();

                    if(x != '(' && s.empty() == true){
                        cout << '0' << "\n";
                        return 0;
                    }
                    else if(x == '(') break;
                    else if(x < 0) temp += x;
                }
                if(temp == 0) s.push(-2);
                else s.push(temp * 2);
            }
            else if(cur == ']'){
                int temp = 0;
                while(1){
                    int x = s.top();
                    s.pop();

                    if(x != '[' && s.empty() == true){
                        cout << '0' << "\n";
                        return 0;
                    }
                    else if(x == '[') break;
                    else if(x < 0) temp += x;
                }
                if(temp == 0) s.push(-3);
                else s.push(temp * 3);
            }
        }
    }
    
    while(s.empty() == false){
        int cur = s.top();
        s.pop();

        if(cur > 0){
            cout << "0\n";
            return 0;
        }
        else sum -= cur;
    }

    cout << sum << "\n";
    return 0;
}