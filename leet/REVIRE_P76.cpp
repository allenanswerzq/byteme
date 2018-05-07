#include <cstdio>  
#include <cmath>
#include <climits>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>

using namespace std;

void printVector(vector<int>& v) {
    cout << "[ ";
    for (auto x:v)
        cout << x << " ";
    cout <<"] " << endl;
}

// Need review
string minWindow(string s, string t) {
    // the number of ascii characters is 128
    vector<int> map(128, 0);
    for(auto x: t)
        map[x]++;
    // window: |start------|end
    int total=t.size(), start=0, end=0, resLen=INT_MAX, resStart=0;
    while(end < s.size()) {
        // if s[end] exists in t
        if (map[s[end]] > 0)
           total--;
        map[s[end]]--;
        end++;

        while (total == 0) {
        // all chars of t have included in window
            if(end-start < resLen) {
                resStart = start;
                resLen = end-start;
            } 

            map[s[start]]++;
            if(map[s[start]] > 0)
                total++;
            start++;
       }
    }
    return resLen==INT_MAX ? "":s.substr(resStart, resLen);
}

int main(int argc, char** argv) {
    return 0;
}
