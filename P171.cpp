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

int titleToNumber(string s) {
    int n = s.size()-1;
    int res = 0;
    for (auto x: s) {
        res += (pow(26,n) * (toupper(x)-'A'+1));
        --n;
    }
    return res;
}

int main(int argc, char** argv) {
    return 0;
}
