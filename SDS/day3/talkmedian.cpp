// 백준 1655 가운데를 말해요
#include <iostream> 
#include <queue>
#include <functional>

using namespace std;

/*
max heap과 min heap을 관리하며 항상 max heap의 head를 출력하게 함
힙이 비어있다면 최대힙에 먼저 넣는다
이후, 두 힙의 크기가 같을 때,
	들어오는 수가 최대힙의 헤드보다 크면, 최대힙에 push
	그렇지 않으면 최대힙의 헤드를 뺴서 최소힙에 넣고, 새로 들어오는 값을 최대 힙에 넣는다.
또한, 최대힙의 크기가 최소힙보다 클 때,
	최소힙의 헤드보다 작은 경우, 최소힙에 push
	최소힙의 헤드보다 작거나 같지만 최대힙의 헤드보단 큰 경우, 최소힙에 push
	최대힙의 헤드보다 작거나 같은 경우, 최대합에 push
*/
int n;
priority_queue<int, vector<int>, less<int> > maxh; 
priority_queue<int, vector<int>, greater<int> > minh;

int main(){
	// 빠른 입출력
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n;
	
	for(int i = 0 ; i < n ; i++){
		int cur;
		cin >> cur;
		
		if(maxh.empty() == true && minh.empty() == true) maxh.push(cur);
		else if(maxh.size() == minh.size()){
			if(maxh.top() >= cur) maxh.push(cur);
			else if(maxh.top() < cur && cur <= minh.top()){
				maxh.push(cur);
			}
			else if(minh.top() < cur){
				maxh.push(minh.top());
				minh.pop();
				minh.push(cur);
			}
		}
		else if(maxh.size() > minh.size()){
			if(minh.empty() == true){
				if(maxh.top() < cur) minh.push(cur);
				else{
					minh.push(maxh.top());
					maxh.pop();
					maxh.push(cur);
				}
			}
			else if(maxh.top() >= cur){
				minh.push(maxh.top());	
				maxh.pop();
				maxh.push(cur);
			}
			else if(maxh.top() < cur && cur <= minh.top()){
				minh.push(cur);
			}
			else if(minh.top() < cur){
				minh.push(cur);
			}
		}
		cout << maxh.top() << "\n";
	}
	
	return 0;
}
