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
#include <sstream>
#include <queue>
#include <deque>

using namespace std;

void printVector(vector<int>& v) {
    cout << "[ ";
    for (auto x:v)
        cout << x << " ";
    cout <<"] " << endl;
}

void reverseWords(string &s) {
    istringstream in(s);
    bool mark = true;
    string word;
    s = "";
    while (in >> word) {
        s = word + (mark ? "":" ") + s;
        mark = false;
    }    
}

int main(int argc, char** argv) {
    string s = "the sky is blue";
    reverseWords(s);
    cout << s << endl;
    return 0;
}
