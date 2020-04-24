// 백준 15686 치킨 배달
/*
    치킨 거리는 집과 가장 가까운 치킨집 사이의 거리
    도시의 치킨 거리는 모든 집의 치킨 거리의 합
    (r1, c1)과 (r2, c2) 사이의 거리는 |r1-r2| + |c1-c2|
    0은 빈 칸, 1은 집, 2는 치킨집
    도시에 있는 치킨집 중에서 최대 M개를 고르고, 나머지 치킨집은 모두 폐업
    어떻게 고르면, 도시의 치킨 거리가 가장 작게 될지 구하는 프로그램
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

int n,m;
int map[51][51];
int cnt;
int city_dist;
vector<pair<int,int> > ck;
vector<pair<int,int> > h;
vector<int> p;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    city_dist = 987987987;

    cin >> n >> m;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            cin >> map[i][j];
            if(map[i][j] == 1) h.push_back(make_pair(i,j));
            else if(map[i][j] == 2){
                ck.push_back(make_pair(i,j));
                cnt++;
            }
        }
    }

    for(int i = 0 ; i < m ; i++) p.push_back(1);
    for(int i = 0 ; i < cnt - m ; i++) p.push_back(0);
    sort(p.begin(), p.end());

    do{
        vector<pair<int,int> > t;
        for(int i = 0 ; i < p.size() ; i++){
            if(p[i] == 1){
                t.push_back(ck[i]);
            }
        }

        int dist = 0;
        for(int i = 0 ; i < h.size() ; i++){
            int hy = h[i].first;
            int hx = h[i].second;
            int min_dist = 987987987;

            for(int j = 0 ; j < t.size() ; j++){
                int cy = t[j].first;
                int cx = t[j].second;

                int temp_dist = abs(hy - cy) + abs(hx - cx);
                min_dist = min(min_dist, temp_dist);
            }

            dist += min_dist;
        }

        city_dist = min(city_dist, dist);
        // cout << city_dist << "\n";
    }while(next_permutation(p.begin(), p.end()));

    cout << city_dist << "\n";
    return 0;
}
/*
    next_permutation
    - algorithm header에 존재
    - 순열을 만들때 사용
    - 중복된 원소가 있는 경우, 중복을 제외하고 만듦
    - vector를 이용하여 조합도 가능
        -> nCk 라면 벡터에 k개의 1을 넣고 n-k개의 0을 넣고 next_permutation
        -> 정렬 후, 1인 경우에만 동작시키면 조합 완성
*/
/*
    12:50 ~ 13:12
*/