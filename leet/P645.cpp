#include<bits/stdc++.h>

using namespace std;

void printVector(vector<int>& v) {
    cout << "[ ";
    for (auto x:v)
        cout << x << " ";
    cout <<"] " << endl;
}

vector<int> findErrorNums(vector<int>& nums) {
    vector<int> res;
    unordered_map<int, int> mp;
    int n = nums.size();
    for (auto x: nums)
        mp[x]++;

    int a = 0, b=0;
    for (int i=1; i<=n; ++i) {
        if (mp.find(i) == mp.end())
            a = i;
        else if (mp[i] > 1) 
            b = i;
    }
    res.push_back(b);
    res.push_back(a);
    return res;
}

int main(int argc, char** argv) {
    return 0;
}
