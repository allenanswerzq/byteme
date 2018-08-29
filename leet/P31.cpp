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

class Solution {
public:
	void nextPermutation(vector<int>& aa) {
		int n = aa.size();
		int mi;
	  for (int i = n - 2; i >= 0; --i) {
			if (aa[i] < aa[i + 1]) {
				int mi = i + 1;
				for (int j = i + 2; j < n; ++j)
					if (aa[i] < aa[j] && aa[j] < aa[mi])
						mi = j;
				swap(aa[i], aa[mi]);
				sort(aa.begin() + i + 1, aa.end());
				return;
			}
		}
		sort(aa.begin(), aa.end());
	}
};

void test(vi aa) {
	Solution go;
	go.nextPermutation(aa);
	pvi(aa);
}

int main() {
	test({1, 2, 3});
	test({3, 2, 1});
	test({1, 1, 5});
	return 0;
}
