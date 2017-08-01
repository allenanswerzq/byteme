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
#include <queue>
#include <deque>

using namespace std;

void printVector(vector<int>& v) {
    cout << "[ ";
    for (auto x:v)
        cout << x << " ";
    cout <<"] " << endl;
}

bool isPal(string s) {
    if (s == "") return true;
    int lo=0, hi=s.size()-1;
    while (lo < hi) 
        if (s[lo++] != s[hi--])
            return false;
    return true;
}
// Perfect
int countSubstrings(string s) {
    if (s == "") return 0;
    int cnt = 0;
    for (int j=0; j<s.size(); ++j) {
        for (int i=1; i<=s.size()-j; ++i)
           if (isPal(s.substr(j, i))) {
               cnt++;
           }
    }
    return cnt;
}

int main(int argc, char** argv) {
    return 0;
}
