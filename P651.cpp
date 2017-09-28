#include <cstdio>  
#include <cmath>
#include <climits>
#include <cstdlib>
#include <ctype.h> // <cctype> isalpha isdigit
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <string>   // std:string std:stoi
#include <tuple>
#include <queue>
#include <deque>

using namespace std;

void printVector(vector<int>& v) {
    cout << "[ ";
    for (auto x:v)
        cout << x << " ";
    cout <<"] " << endl;
}

// recusive approach
int maxA(int N) {
    int res;
    for (int i=1; i<N; ++i) 
        res = max(res, maxA(i)*(N-i-1));
    return res;
}

// dp approach
int maxA(int N) {
        
}

int main(int argc, char** argv) {
    return 0;
}
