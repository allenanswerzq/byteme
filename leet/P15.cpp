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

#define vi vector<int>
#define vvi vector<vi>

class Solution {
public:
	vvi threeSum(vector<int>& aa) {
		vvi res;
		int n = sz(aa);
		if (n < 3) return res;
		sort(all(aa));
		// a + b + c = 0
		// -a = b + c
		for (int i = 0; i < n - 2; ++i) {
			if (i > 1 && aa[i - 1] == aa[i]) continue;
			int lo = i + 1, hi = sz(aa) - 1;	
			int goal = -aa[i];
			while (lo < hi) {
				if (aa[lo] + aa[hi] == goal) {
					res.push_back({aa[i], aa[lo], aa[hi]});
					while (lo < hi && aa[lo] == aa[lo + 1]) ++lo;
					while (lo < hi && aa[hi] == aa[hi - 1]) --hi;
					++lo; --hi;
				}	
				else if (aa[lo] + aa[hi] < goal) ++lo;
				else --hi;
			}
		}
		return res;
	}
};

void test(vector<int> inp) {
	Solution go;
	vvi res = go.threeSum(inp);	
	fora (r, res) {
		pvi(r);
	}
}

int main() {
	test({-1, 0, 1, 2, -1, -4});
	test({0, 0, 0, 0, 0});
	return 0;
}
