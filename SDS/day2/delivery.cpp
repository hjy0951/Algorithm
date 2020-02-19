// 백준 2842 집배원 한상덕
#include <iostream> 
#include <cstdio>
#include <vector> 
#include <algorithm>
#include <cstring>

using namespace std;

int n;
char map[50][50];
int visit[50][50];
int h[50][50];
int kn;
int tired;
int hy,hx;
vector<int> v;
int s,e;

int dy[] = {-1,1,0,0,-1,-1,1,1}; // 8 2 4 6 7 9 1 3
int dx[] = {0,0,-1,1,-1,1,-1,1}; // 상하좌우 좌상 우상 좌하 우하

int rec(int y, int x){
	if(h[y][x] < v[s] || h[y][x] > v[e] || visit[y][x]) return 0;
	visit[y][x] = 1;
	int cnt = 0;
	if(map[y][x] == 'K') cnt++; // 집 도착
	
	for(int i = 0 ; i < 8 ; i++){
		int ny = y + dy[i];
		int nx = x + dx[i];
		
		if(ny >= n || ny < 0 || nx >= n || nx < 0) continue;
		
		cnt += rec(ny,nx);
	}
	return cnt;
}

int main(){
	tired = 987987987;
	cin >> n;
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < n ; j++){
			cin >> map[i][j];
			if(map[i][j] == 'K') kn++;
			if(map[i][j] == 'P') hy = i, hx = j;
		}
	}	
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < n ; j++){
			cin >> h[i][j];
			v.push_back(h[i][j]);
		}
	}
	
	sort(v.begin(), v.end());
	// 고도를 모두 정렬하여 투 포인터
	
	s=0;
	e=0;
	while(s < v.size() && e < v.size()){
		memset(visit,0,sizeof(visit));
		if(rec(hy,hx) == kn){ // 모든 집을 들렀다면
			// 최소 피로도 업데이트
			if(tired > v[e] - v[s]){
				tired = v[e]-v[s];
			}
			s++;
		}
		else e++;
	}
	
	cout << tired << endl;
	return 0;
}
