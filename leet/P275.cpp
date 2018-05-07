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
int hIndex(vector<int>& a) {
    int n = a.size(); // N papers
    int ret = 0;
    for (int i=0; i<n; ++i) {
        int x = min(n-i, a[i]);
        ret = max(x, ret);
    }
    return ret;
}