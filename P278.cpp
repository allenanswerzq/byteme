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
int firstBadVersion(int n) {
    int lo=1, hi=n;
    while (lo < hi) {
        int mid = lo + (hi-lo)/2;
        if (isBadVersion(mid)) hi=mid;
        else lo=mid+1;
    }
    return lo;
}