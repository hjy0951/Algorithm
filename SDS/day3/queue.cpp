// 백준 10845 큐 | 연결리스트 관련 문제 = 개구리 공주 
#include <iostream> 
#include <string>
#include <queue>

using namespace std;

queue<int> q;
int n;

int main(){
	cin >> n;
	for(int i = 0 ; i < n ; i++){
		string str;
		cin >> str;
		
		if(!str.compare("push")){
			int x;
			cin >> x;
			q.push(x);
		}
		else if(!str.compare("pop")){
			if(q.empty()) cout << "-1" << endl;
			else{
				cout << q.front() << "\n";
				q.pop();
			}
		}
		else if(!str.compare("size")){
			cout << q.size() << "\n";
		}
		else if(!str.compare("empty")){
			cout << q.empty() << "\n";
		}
		else if(!str.compare("front")){
			if(q.empty()) cout << "-1" << endl;
			else cout << q.front() << "\n";
		}
		else if(!str.compare("back")){
			if(q.empty()) cout << "-1" << endl;
			else cout << q.back() << "\n";
		}		
	}
	
	return 0;
}
