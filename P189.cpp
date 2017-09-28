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

void rotate(vector<int>& nums, int k) {
    int k %= nums.size();
    reverse(nums, 0, nums.size());
    reverse(nums, 0, k);
    reverse(nums, k+1, nums.size());    
}

int main(int argc, char** argv) {
    return 0;
}
