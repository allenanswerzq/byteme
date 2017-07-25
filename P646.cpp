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

typedef struct {
    int id;
    bool mark;
    int time;
} T;

vector<T> parse(vector<string>& logs) {
    vector<T> res;
    for (int i=0; i<logs.size(); ++i) {
        string s = logs[i];
        int lo=0, hi=s.size()-1;
        while (s[lo]!=':') ++lo;
        while (s[hi]!=':') --hi;
        T t;
        t.id = stoi(s.substr(0, lo));
        t.mark = s.substr(lo+1, hi-lo-1)=="start";
        t.time = stoi(s.substr(hi+1));
        printf("PARSE: %d %d %d\n", t.id, t.mark, t.time);
        res.push_back(T);
    }
    return res;
}

vector<int> exclusiveTime(int n, vector<string>& logs) {
}

int main(int argc, char** argv) {
    return 0;
}
