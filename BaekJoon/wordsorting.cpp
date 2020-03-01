// 백준 1181 단어 정렬
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int n;
vector<string> v[51]; // 자릿수 별로 벡터를 만들어 단어를 저장
set<string> dic; // 중복된 값을 넣지 않기 위함

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for(int i = 0 ; i < n ; i++){
        string word;
        cin >> word;

        if(dic.insert(word).second == true) v[word.size()].push_back(word);
        // set의 insert()가 반환하는 pair의 second가 insert 성공 여부이기 때문에 true라면 처음 들어온 값
    }

    for(int i = 1 ; i <= 50 ; i++){
        if(v[i].empty() == false){
            sort(v[i].begin(), v[i].end()); // 정렬 후 출력
            for(int j = 0 ; j < v[i].size() ; j++){
                cout << v[i][j] << "\n";
            }
        }
    }
    return 0;
}