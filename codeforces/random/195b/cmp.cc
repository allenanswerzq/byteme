#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <utility>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>

using namespace std;

#define REP(i,n) for((i)=0;(i)<(int)(n);(i)++)
#define foreach(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)

vector <int> v;

int main(void){
    int N,K,i;

    cin >> N >> K;
    K--; // [0, K]

    if(K%2 == 0){
        v.push_back(K/2);
        REP(i,K/2){
            v.push_back(K/2-1-i);
            v.push_back(K/2+1+i);
        }
    } else {
        int half = K/2;
        REP(i,half+1){
            v.push_back(half-i);
            v.push_back(half+1+i);
        }
    }

    REP(i,N) cout << v[i%(K+1)] + 1 << endl;

    return 0;
}
