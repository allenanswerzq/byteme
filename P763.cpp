#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
#include <sstream>
#include <fstream>
#include <cassert>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <bitset>
#include <string>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
#include <deque>
#include <stack>
#include <list>
#include <map>
#include <set>
using namespace std;

#define foreach(x, v) for (typeof (v).begin() x=(v).begin(); x !=(v).end(); ++x)
#define For(i, a, b) for (int i=(a); i<(b); ++i)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#define PII pair<int, int>
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define D(x) cerr << #x " is " << (x) << endl

const double EPS = 1e-9;
int cmp(double x, double y = 0, double tol = EPS) {
  return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

class Solution {
public:
    vector<int> partitionLabels(string S) {
 			map<char, int> mp;      
 			int n = SZ(S);
 			// find maximum index for each characters
 			for (int i=0; i<n; ++i) mp[S[i]] = i;
 			vector<int> ret;		
 			int i = 0;
 			while (i < n) {
 				int x = mp[S[i]];	
 				int k = i;
 				for (k=i; k<x; k++) {
 					if (mp[S[k]] > x) x = mp[S[k]];		
 				}
 				ret.PB(x-i+1);
 				i = k+1;
 			}
 			return ret;
    }
};