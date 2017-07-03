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
// backtracking approach 
// not right
void bt(vector<int> res, vector<int> ans, int n) {
    if (ans.size() == n) {
        int x = 0;
        for (int i=0; i<n; i++)
            x = x*2 + ans[i];
        res.push_back(x);
    } else {
        for (int i=0; i<2; ++i) {
            ans.push_back(i);
            bt(res, ans, n);
            ans.pop_back();
        }
    }
}

vector<int> grayCode(int n) {
    vector<int> res;
    vector<int> ans;
    bt(res, ans, n);
    return res;
}

/*
 * This function converts an unsigned binary
 * number to reflected binary Gray code.
 *
 * The operator >> is shift right. The operator ^ is exclusive or.
 */
unsigned int binaryToGray(unsigned int num)
{
    return num ^ (num >> 1);
}
// reference: https://en.wikipedia.org/wiki/Gray_code
// #Constructing_an_n-bit_Gray_code
vector<int> grayCode(int n) {
    vector<int> res;
    for (int i=0; i< 1<<n; ++i) res.push_back(i ^ (i>>1));
    return res;
}


int main(int argc, char** argv) {
    printf("%d\n", binaryToGray(2));
    return 0;
}
