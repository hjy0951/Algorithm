/*
SWEA SW 문제해결 string
    주어지는 영어 문장에서 특정한 문자열의 개수를 반환하는 프로그램
*/

#include <cstdio>
#include <cstring>

using namespace std;

char str[1010];
char pat[15];
int cnt;
int sl,pl;

void find(){
    int cur = 0;
    int sec = -1;

    for(int i = 0 ; i < sl ; i++){
        if(str[i] == pat[0]){
            for(int j = 0 ; j < pl ; j++){
                if(str[i+j] == pat[j]){
                    cur++;

                    if(sec < 0 && pat[0] == str[i+j]) sec = i + j;
                }
                if(cur == pl) cnt++;
                
                cur = 0;
                if(sec >= 0){
                    i = sec;
                    sec = -1;
                }
                else{
                    i = i + pl - 1;
                }
            }
        }
    }
}

int main(){
    for(int q = 1 ; q <= 10 ; q++){
        memset(str, 0, sizeof(str));
        memset(pat, 0, sizeof(pat));

        int t;
        scanf(" %d", &t);
        scanf(" %s", str);
        scanf(" %s", pat);

        sl = strlen(str);
        pl = strlen(pat);
        cnt = 0;

        find();

        printf("#%d %d\n", q, cnt);
    }
    return 0;
}

/*
#1 4
#2 2
#3 19
#4 4
#5 6
#6 2
#7 5
#8 5
#9 8
#10 14
*/