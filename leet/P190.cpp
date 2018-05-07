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

// Accepted
uint32_t reverseBits(uint32_t n) {
    uint32_t r = 0;        
    for (int i=0; i<32; ++i) {
        uint32_t y = (n >> i) & 1;
        r = r | (y << 31-i);
    }
    return r;
}

int main(int argc, char** argv) {
    cout << reverseBits(43261596) << endl;
    return 0;
}
