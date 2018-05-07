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

// finally, accepted
// :-(
int compareVersion(string version1, string version2) {
    if (version1[0]=='.' || version2[0]=='.') return 0;
    istringstream s1(version1);
    istringstream s2(version2);
    char _;
    int a=INT_MIN, b=INT_MIN;
    s1 >> a >> _;
    s2 >> b >> _;
    cout << a << " " << b << endl;
    while (a!=INT_MIN && b!=INT_MIN) {
        if (a != b)
            return a>b ? 1:-1;
        else {
            a = b = INT_MIN;
            s1 >> a >> _;
            s2 >> b >> _;
            if (a==INT_MIN && b==INT_MIN) return 0; // reach the end of input
            if (a==INT_MIN) a = 0;
            if (b==INT_MIN) b = 0;
            cout << a << " " << b << endl;
        }
    }
    return 0; 
}

int main(int argc, char** argv) {
    return 0;
}
