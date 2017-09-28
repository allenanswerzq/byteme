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

int main(int argc, char** argv) {
    vector<vector<string>> res;
    res.push_back(vector<string> ({"aaaa"});
    res.push_back(vector<string> ({"front"});
    for (auto x: res) {
        x.insert(x.begin(), "xxx");
    } 

    for (auto r: res) {
        for (auto c: r) 
            cout << c << " ";
         cout <<endl;
    }
    return 0;
}
