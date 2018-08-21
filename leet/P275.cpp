#include<bits/stdc++.h>

using namespace std;
int hIndex(vector<int>& a) {
    int n = a.size(); // N papers
    int ret = 0;
    for (int i=0; i<n; ++i) {
        int x = min(n-i, a[i]);
        ret = max(x, ret);
    }
    return ret;
}
