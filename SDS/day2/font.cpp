// 백준 9997 폰트
#include <iostream> 
#include <cstdio>

using namespace std;
// 폰트에는 알파벳 소문자만 포함
// 문장은 알파벳 소문자로만
// 테스트 문장에는 알파벳 소문자 26개 모두 포함해야 함
// 테스트 문장은 사전에 포함된 단어로만 이용
// 각 단어는 한 번씩만 사용
// 단어 순서는 중요하지 않음
// 테스트 문장의 개수를 구하는 프로그램

int n;
int word[25];
int allone = 0x3ffffff;
int cnt;

// ***다시 공부 : 재귀로 완탐
// 비트 연산으로 하면 편함
// 비트를 .......fedcba 로 함
//       ........3210
void find(int cur, int next){
	if (next >= n-1) {
		// 알파벳에 해당하는 모든 비트가 켜질 경우 카운트+1
        if (cur == allone)
            cnt++;
        return;
    }
 
 
    find(cur | word[next + 1], next + 1); // 다음 단어 포함
    find(cur, next + 1); // 다음 단어 포함 X
}

int main(){
	cnt = 0;
	cin >> n;
	for(int i = 0 ; i < n ; i++){
		string str;
		cin >> str;
		
		for(int j = 0 ; j < str.size(); j++){
			int cur = str[j] - 'a';
			cur = 1 << cur;
			word[i] = word[i]|cur;
		}
	}

	find(0, -1);
	
	cout << cnt << endl;
	return 0;
}
