#include<bits/stdc++.h>

using namespace std;

void printVector(vector<int>& v) {
    cout << "[ ";
    for (auto x:v)
        cout << x << " ";
    cout <<"] " << endl;
}

// Note: duplicate problem
int longestConsecutive(vector<int>& nums) { 
    unordered_set<int> set(nums.begin(), nums.end());         
    int best = 0;
    for (auto x:set) {
        if (set.find(x-1) == set.end()) {
            int y = x+1;
            while (set.find(y) != set.end())
                ++y;
            best = max(best, y-x);
        }
    }
    return best;
}

int longestConsecutive(vector<int>& nums) { 
    unordered_map<int, int> m;
    int best = 0;
    for (auto x: nums) {
        if (m.find(x) == m.end()) {
            int l = m.find(x-1) == m.end() ? 0: m[x-1];
            int r = m.find(x+1) == m.end() ? 0: m[x+1];

            int sum = l + r + 1;
            best = max(best, sum);
            m[x] = sum;
            
            m[x - l] = sum;
            m[x + r] = sum;
        } 
    }
    return best;
}

int main(int argc, char** argv) {
    return 0;
}
