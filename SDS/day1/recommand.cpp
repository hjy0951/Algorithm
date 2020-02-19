// 백준 1713 후보 추천하기
/*
추천받은 학생의 사진을 게시할 수 있는 사진틀을 후보의 수만큼 만들었다
추천받은 학생의 사진을 사진틀에 게시하고 추천받은 횟수를 표시하는 규칙은 다음과 같다.

    1.시작하기 전 모든 사진틀은 비어있다.
    2.특정 학생을 추천하면, 추천받은 학생의 사진이 반드시 사진틀에 게시
    3.비어있는 사진틀이 없는 경우 현재까지 추천 받은 횟수가 가장 적은 학생의 사진을 삭제, 새롭게 추천받은 학생의 사진을 게시
        - 이때, 추천 횟수가 가장 적은 학생이 두 명 이상일 경우, 게시된 지 가장 오래된 사진을 삭제
    현재 사진이 게시된 학생이 다른 학생의 추천을 받은 경우에는 추천받은 횟수만 증가시킨다.
    사진틀에 게시된 사진이 삭제되는 경우 해당 학생이 추천받은 횟수는 0으로 바뀐다.
후보의 수 즉, 사진틀의 개수와 전체 학생의 추천 결과가 추천받은 순서대로 주어졌을 때, 최종 후보가 누구인지 결정하는 프로그램을 작성하시오.
*/ 
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int n,r;
int age[101];
int num[101];
vector<int> live;

void print(){
    cout << "recom\n";
    for(int i = 0 ; i < live.size() ; i++){
        cout << live[i] << " ";
    }
    cout << "\n";
    cout << "age\n";
    for(int i = 0 ; i < live.size() ; i++){
        cout << age[live[i]] << " ";
    }
    cout << "\n";
    cout << "num\n";
    for(int i = 0 ; i < live.size() ; i++){
        cout << num[live[i]] << " ";
    }
    cout << "\n\n";
}

// 오래된 정도 비교
bool agecmp(const int& x, const int& y){
    return age[x] > age[y];
}
// 추천 수 비교
bool numcmp(int x, int y){
    return num[x] < num[y];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> r;

    for(int x = 0 ; x < r ; x++){
        int rec;
        cin >> rec;

        if(live.empty() == true){
            // 빈 경우
            live.push_back(rec);
            num[rec]++;
        }
        else if(live.size() > 0 && live.size() < n){ // 꽉 차지 않은 경우
            // 게시되지 않은 후보
            if(age[rec] == 0){
                live.push_back(rec);
                num[rec]++;
            }
            // 게시된 후보
            else{
                num[rec]++;
            }
        }
        else if(live.size() == n){ // 꽉 찬 경우 
            // 게시되지 않은 후보
            if(age[rec] == 0){
                // 가장 추천수가 작은 후보들 찾기
                vector<int> temp;

                sort(live.begin(),live.end(), numcmp);
                
                int minnum = num[live[0]];
                
                temp.push_back(live[0]);
                for(int i = 1 ; i < live.size() ; i++){
                    if(minnum == num[live[i]]) temp.push_back(live[i]);
                    else break;
                }
                
                // 이 중 가장 오래된 후보를 찾아야 함
                sort(temp.begin(),temp.end(), agecmp);
                int old = temp[0];
                age[old] = -1;

                live.push_back(rec);
                num[rec]++;
            }
            // 게시된 후보
            else{
                num[rec]++;
            }
        }

        // aging
        int ll = live.size();
        vector<int> temp;
        for(int i = 0 ; i < ll ; i++){
            int cur = live.back();
            live.pop_back();

            if(age[cur] < 0){
                age[cur] = 0;
                num[cur] = 0;
            }
            else{
                age[cur]++;
                temp.push_back(cur);
            }
        }
        for(int i  = 0 ; i < temp.size() ; i++){
            live.push_back(temp[i]);
        }
    }

    sort(live.begin(), live.end());
    for(int i = 0 ; i < live.size() ; i++){
        cout << live[i] << " ";
    }
    cout << "\n";
    
    return 0;
}

/*
3
9
2 1 4 3 5 6 2 7 2

2 6 7
*/
