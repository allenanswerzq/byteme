#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define mst(x, y) memset(x, y, sizeof(x))
#define fora(e, c) for (auto &e : c)
#define fori(i, a, b) for (int i=(a); i<(b); ++i)
#define ford(i, a, b) for (int i=(a); i>(b); --i)
#define pvi(x) fora(a, x) cout << a << " "; cout << endl
#define par(x, n) fori(a, 0, n) cout << x[a] << " "; cout << endl
#define output(ix, val) cout << "Case #" << (ix) << ": " << (val) << endl

#define trace(...) _f(#__VA_ARGS__, __VA_ARGS__)
template <typename T>
void _f(const char* name, T&& arg) {
  cout << name << ": " << arg << endl;
}

template <typename T, typename... Args> 
void _f(const char* names, T&& arg, Args&&... args) {
  const char* split = strchr(names + 1, ','); 
  cout.write(names, split - names) << ": " << arg << " |";
  _f(split, args...); 
} 

class Solution {
public:
	int threeSumClosest(vector<int>& aa, int target) {
		sort(aa.begin(), aa.end());

		int n = aa.size();
		int diff = (1 << 30);
		int result = 0;
		for (int i = 0; i< n - 2; ++i) {
			if (i > 1 && aa[i] == aa[i-1]) continue;
			int a = aa[i];
			int lo = i + 1, hi = n - 1;
			while (lo < hi) {
				int b = aa[lo];
				int c = aa[hi];
				int sum = a + b +c; 
				if (sum - target == 0) {
					return target;
				} else {
					if (abs(sum - target) < diff) {
						diff = abs(sum - target);
						result = sum;
					}	
					
					if (sum > target) {
						// Because array already sorted, 
						// just need to decrease sum to more closer to target
						while (hi > 0 && aa[hi] == aa[hi - 1]) hi--;
						hi--;	
					} else {
						while (lo < n - 1 && aa[lo] == aa[lo + 1]) ++lo;
						++lo;
					}
				}
			}
		}
		return result;
	}
};

void test(vector<int> inp, int bb) {
	Solution go;
	int res = go.threeSumClosest(inp, bb);	
	output(1, res);
}

int main() {
	test({-1, 2, 1, -4}, 1);
	test({-4,-7,-2,2,5,-2,1,9,3,9,4,9,-9,-3,7,4,1,0,8,5,-7,-7}, -11);
	return 0;
}
