// 백준 1026 보물
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<int> a;
vector<int> b;
vector<int> t;
bool visit[51];

int main(){
    cin >> n;
    for(int i = 0 ; i < n ; i++){
        int num;
        cin >> num;
        a.push_back(num);
    }
    for(int i = 0 ; i < n ; i++){
        int num;
        cin >> num;
        b.push_back(num);
        t.push_back(num);
    }
    sort(a.begin(), a.end());
    sort(t.begin(), t.end());

    int s = 0;
    /*
        B를 재배열하면 안된다고 했지만, 상관없는 문제였다.
        하지만 그렇게 안하고도 binary search를 이용해서 다르게 풀어보았다.
    */
    for(int i = 0 ; i < n ; i++){
        int idx = binary_search(t.begin(), t.end(), b[i]);

        if(visit[idx] == true){
            bool find = true;
            int temp = idx;
            while(temp++){
                if(t[temp] != b[i]) break;
                else if(t[temp] == b[i] && visit[temp] == false){
                    visit[temp] = true;
                    find = true;
                    break;
                }
            }
            if(find) idx = temp;
            else{
                while(temp--){
                    if(t[temp] != b[i]) break;
                    else if(t[temp] == b[i] && visit[temp] == false){
                        visit[temp] = true;
                        find = true;
                        break;
                    }
                }
            }
        }

        s += t[i] * a[n-1-i];
    }

    /*
        정말 간단하게는 A는 오름차순 B는 내림차순으로 정렬하여 차례대로 곱해가며 더하면 최소값이 나온다.
    */

    cout << s << '\n';
    return 0;
}