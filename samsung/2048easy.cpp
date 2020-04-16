// 백준 12100 2048(easy)
/*

*/
#include <iostream>
#include <stack>

using namespace std;

int n;
int map[21][21];
int maxn;

void printmap(int m[][21]){
    cout << "\n";
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            cout << m[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

void copy_map(int m1[][21], int m2[][21]){ // m1 -> m2
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            m2[i][j] = m1[i][j];
        }
    }
}

void move(int dir, int m[][21]){
    stack<int> s;
    int pos;

    for(int i = 0 ; i < n ; i++){
        if(dir == 0){ // 아래로 밀기
            pos = n-1;

            for(int j = n-1 ; j >= 0 ; j--){
                int cur = m[j][i];
                m[j][i] = 0;

                if(cur != 0){
                    if(s.empty()) s.push(cur);
                    else{
                        if(s.top() == cur){
                            s.pop();
                            m[pos][i] = cur + cur;
                            pos--;
                        }
                        else{
                            int temp = s.top();
                            s.pop();
                            s.push(cur);
                            m[pos][i] = temp;
                            pos--;
                        }
                    }
                }
            }

            if(!s.empty()){
                m[pos][i] = s.top();
                s.pop();
            }
        }
        else if(dir == 1){ // 오른쪽으로 밀기
            pos = n-1;

            for(int j = n-1 ; j >= 0 ; j--){
                int cur = m[i][j];
                m[i][j] = 0;

                if(cur != 0){
                    if(s.empty() == true) s.push(cur);
                    else{
                        if(s.top() == cur){
                            s.pop();
                            m[i][pos] = cur + cur;
                            pos--;
                        }
                        else{
                            int temp = s.top();
                            s.pop();
                            s.push(cur);
                            m[i][pos] = temp;
                            pos--;
                        }
                    }
                }
            }

            if(!s.empty()){
                m[i][pos] = s.top();
                s.pop();
            }
        }
        else if(dir == 2){ // 왼쪽으로 밀기
            pos = 0;

            for(int j = 0 ; j < n ; j++){
                int cur = m[i][j];
                m[i][j] = 0;

                if(cur != 0){
                    if(s.empty() == true) s.push(cur);
                    else{
                        if(s.top() == cur){
                            s.pop();
                            m[i][pos] = cur + cur;
                            pos++;
                        }
                        else{
                            int temp = s.top();
                            s.pop();
                            s.push(cur);
                            m[i][pos] = temp;
                            pos++;
                        }
                    }
                }
            }

            if(!s.empty()){
                m[i][pos] = s.top();
                s.pop();
            }
        }
        else if(dir == 3){ // 위로 밀기
            pos = 0;

            for(int j = 0 ; j < n ; j++){
                int cur = m[j][i];
                m[j][i] = 0;

                if(cur != 0){
                    if(s.empty() == true) s.push(cur);
                    else{
                        if(s.top() == cur){
                            s.pop();
                            m[pos][i] = cur + cur;
                            pos++;
                        }
                        else{
                            int temp = s.top();
                            s.pop();
                            s.push(cur);
                            m[pos][i] = temp;
                            pos++;
                        }
                    }
                }
            }

            if(!s.empty()){
                m[pos][i] = s.top();
                s.pop();
            }
        }
    }       
}

void rec(int cnt, int m[][21]){
    if(cnt >= 5){
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                if(m[i][j] > 0){
                    if(maxn < m[i][j]) maxn = m[i][j];
                }
            }
        }
        return;
    }
    else{
        int tmap[21][21];

        for(int i = 0 ; i < 4 ; i++){
            copy_map(m,tmap);
            move(i,tmap);
            rec(cnt+1, tmap);
        }
    }
}

int main(){
    maxn = 0;
    cin >> n;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            cin >> map[i][j];
        }
    }
    int temp[21][21];
    copy_map(map,temp);
    rec(0,temp);

    cout << maxn << "\n";

    return 0;
}

/*
    15:33 ~ 15:44
    15:55 ~ 17:55
*/