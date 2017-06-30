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

bool exist(vector<vector<char>>& A, int x, int y, const char* word) {
    if(word[0] == '\0') return true;
    if(x<0 || y<0 || x>=A.size() || y>=A[0].size() || A[x][y]!=word[0])
        return false; 
    // mark current visited cell
    A[x][y] = 0; 
    if (exist(A, x, y+1, word+1) || exist(A, x, y-1, word+1) ||
        exist(A, x-1, y, word+1) || exist(A, x+1, y, word+1))
        return true;
    A[x][y] = word[0];
    return false;
}

bool exist(vector<vector<char>>& A, string word) {
    for (int i=0; i<A.size(); ++i)
        for (int j=0; j<A[0].size(); ++j)
            // NOTE: c_str() get c string equivalent
            if (exist(A, i, j, word.c_str()) 
                return true;
    return false;
}

int main(int argc, char** argv) {
    return 0;
}
