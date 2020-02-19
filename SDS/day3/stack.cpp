// 백준 10828 스택
#include <iostream> 
#include <string>
#include <stack>

using namespace std;

stack<int> s;
int n;

int main(){
	cin >> n;
	for(int i = 0 ; i < n ; i++){
		string str;
		cin >> str;
		
		if(!str.compare("push")){
			int x;
			cin >> x;
			s.push(x);
		}
		else if(!str.compare("top")){
			if(s.empty()) cout << "-1" << endl;
			else cout << s.top() << "\n";
		}
		else if(!str.compare("size")){
			cout << s.size() << "\n";
		}
		else if(!str.compare("empty")){
			cout << s.empty() << "\n";
		}
		else if(!str.compare("pop")){
			if(s.empty()) cout << "-1" << endl;
			else{
				cout << s.top() << "\n";
				s.pop();
			}
		}	
		
	}
	
	return 0;
}
