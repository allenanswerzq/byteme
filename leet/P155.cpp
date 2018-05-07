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
#include <sstream>  // std:istringstream
#include <queue>
#include <deque>

using namespace std;

void printVector(vector<int>& v) {
    cout << "[ ";
    for (auto x:v)
        cout << x << " ";
    cout <<"] " << endl;
}

class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
       minValue = INT_MAX; 
       idx = 0;
    }
    
    void push(int x) {
        minValue = min(minValue, x);
        dp.push_back(minValue);
        stk.push_back(x);
    }
    
    void pop() {
       stk.pop_back();
       dp.pop_back();
       minValue = stk.empty() ? INT_MAX : dp.back();
    }
    
    int top() {
        if (stk.size())
            return stk.back();
        return -1;
    }
    
    int getMin() {
        if (dp.size())
           return dp.back(); 
        return -1;
    }
private:
    int minValue;
    vector<int> stk;
    vector<int> dp;
};

int main(int argc, char** argv) {
    return 0;
}
