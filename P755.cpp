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

vector<int> pourWater(vector<int>& heights, int V, int K) {
	while (V--) {
		auto low = make_pair(K, heights[K]);        
		for (int i=K; i>=0; i--)
			// Note case when height equals low.second
			if (heights[i] < low.second)
				low = make_pair(i, heights[i]);		
			else if(heights[i] > low.second)
				break;
		// Does not find a lower place on the left side	
		// So we check on the right side
		if (low.first == K) {
			for (int i=K+1; i<heights.size(); ++i)
				if (heights[i] < low.second)
					low = make_pair(i, heights[i]);
				else if (heights[i] > low.second)
					break;
		}
		heights[low.first]++;
	}
	return heights;
}