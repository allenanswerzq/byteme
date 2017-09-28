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

bool judgeCircle(string moves) {
    int x = 0, y = 0;
    for (auto c: moves) {
        if (c == 'L')
            x -= 1;
        else if (c == 'R')
            x += 1;
        else if (c == 'U')
            y += 1;
        else if (c == 'D')
            y -= 1;
        else
            return false;
    }
    return x==0 && y==0;
}

int main(int argc, char** argv) {
    return 0;
}
