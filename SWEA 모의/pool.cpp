#include <iostream>
#include <cstdio>

using namespace std;

int fee[4]; // 1 day | 1 month | 3 month | 1 year
int plan[15];
int minfee;

void cmpfee(int cur, int curfee){
    if(cur > 12){
        // if(curfee < fee[3]) minfee = curfee;
        // else minfee = curfee;
        if(curfee < minfee) minfee = curfee;
        if(minfee > fee[3]) minfee = fee[3];
        return;
    }
    else if(plan[cur] == 0){
        cmpfee(cur+1, curfee);
    }
    else{
        cmpfee(cur+1, curfee+plan[cur]*fee[0]);
        cmpfee(cur+1, curfee+fee[1]);
        cmpfee(cur+3, curfee+fee[2]);
    }
}

int main(){
    int T;
    cin >> T;

    for(int i = 1 ; i <= T ; i++){
        minfee = 987987987;
        for(int j = 0 ; j < 4 ; j++){
            cin >> fee[j];
        }

        for(int j = 1 ; j <= 12 ; j++){
            cin >> plan[j];
        }

        cmpfee(1,0);

        cout << "#" << i << " " << minfee << endl;
    }

    return 0;
}