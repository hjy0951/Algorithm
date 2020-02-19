// 백준 1062 가르침
#include <iostream>
#include <string>
#include <set>

// 어떤 K개의 글자를 가르쳐야 학생들이 읽을 수 있는 단어의 개수가 최대가 되는지 구하는 프로그램
// 남극언어의 모든 단어는 "anta"로 시작되고, "tica"로 끝
using namespace std;

int n,k;
char b[] = {'a','c','i','n','t'}; // "anta", "tica"를 처리하기 위함
string word[50]; // 남극 단어
int alpha[27]; // 가르친 단어들은 1 아니면 0
int maxn;

void find(int cnt, int cur){
    if(cnt == k){
        int num = 0;

        for(int i = 0 ; i < n ; i++){
            string cur = word[i];
            int ox = 0;

            for(int j = 4 ; j < cur.size()-3 ; j++){
                int ca = cur[j] - 'a';

                if(alpha[ca] == 0){ // 단어에 가르치지 않은 알파벳이 있으면 break;
                    ox = 1;
                    break;
                }
            }

            if(ox == 0) num++; // 모두 가르친 단어이므로 개수 + 1;
        }

        if(num > maxn) maxn = num;
        return;
    }
    else{
        for(int i = cur+1 ; i < 26 ; i++){
            if(alpha[i] == 1) continue;

            alpha[i] = 1;
            find(cnt+1, i);
            alpha[i] = 0;
        }
    }
}

int main(){
    cin >> n >> k;
    if(k < 5){ // 기본적으로 포함되는 "anta","tica"를 알지 못함
        cout << "0\n";
        return 0;
    }

    for(int i = 0 ; i < n ; i++){
        cin >> word[i];
    }

    for(int i = 0 ; i < 5 ; i++){
        alpha[b[i] - 'a'] = 1 ;
    }
    k -= 5;

    if(k == 0){
        int num = 0;
        for(int i = 0 ; i < n ; i++){
            string cur = word[i];
            int ox = 0;

            for(int j = 4 ; j < cur.size()-3 ; j++){
                int ca = cur[j] - 'a';

                if(alpha[ca] == 0){ // 단어에 가르치지 않은 알파벳이 있으면 break;
                    ox = 1;
                    break;
                }
            }

            if(ox == 0) num++; // 모두 가르친 단어이므로 개수 + 1;
        }
        cout << num << endl;
        
        return 0;
    }

    // k-5개의 가르칠 알파벳을 조합하여 갯수를 세고 이 중 최대값을 구함
    for(int i = 0 ; i < 26 ; i++){
        if(alpha[i] == 1) continue; // 이미 가르친 단어 pass

        alpha[i] = 1;
        find(1,i);
        alpha[i] = 0;
    }

    cout << maxn << endl;
    return 0;
}

/*
2 6
antaxtica
antaytica
*/
