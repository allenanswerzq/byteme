#include <cstdio>
#include <stdio.h> // for using printf
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
#include <deque>
#include <stack>
#include <sstream>  // std:istringstream
#include <queue>
#include <iterator>

using namespace std;

// A scientist has index h if h of his/her N papers have at least h citations each
int hIndex(vector<int>& a) {
    int n = a.size(); // N papers
    int ret = 0;
    sort(a.begin(), a.end());
    for (int i=0; i<n; ++i) {
        int x = min(n-i, a[i]);
        ret = max(x, ret);
    }
    return ret;
}

int hIndex(vector<int>& a) {
    int n = a.size();
    vector<int> mp(n+1, 0);
    for (int i=0; i<n; ++i) 
        if (a[i] > n) mp[n]++;
        else mp[a[i]]++;

    int h = 0;
    for (int i=n; i>=0; ++i) {
        h += mp[i];  // h means total number of papers which all of them at least have i citations
        if (h >= i) return i;
    }
    return 0;
}