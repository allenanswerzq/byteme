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
#define D(x) cerr << #x " is " << (x) << endl

const double EPS = 1e-9;
int cmp(double x, double y = 0, double tol = EPS) {
  return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

//Proof: 
//1+2+3+4+...+k = sum
//assume we want filp x to be -x 
//then sum - 2x = target
//so x = (sum - target) / 2
int reachNumber(int target) {
	target = abs(target)
	int k=0;
	int sum = 0;
	while (true) {
		if (sum>=target && (sum-target)%2==0)
			return k;
		k++;
		sum += k;
	}
	return -1;
}