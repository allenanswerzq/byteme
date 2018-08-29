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
	int strStr2(string aa, string bb) {
		if (aa == bb || bb == "") return 0;
		int m = aa.size(), n = bb.size();
		for (int i = 0; i < m - n + 1; ++i) {
			int p = i; 
			int k = 0;
			while (k < bb.size() && p < aa.size()) {
				if (aa[p] == bb[k]) {
					p++;
					k++;
				} else break;
			}
			if (k == bb.size()) return i;
		}
		return -1;
	}

	int strStr(string aa, string bb) {
		if (aa == bb || bb == "") return 0;
		int m = aa.size(), n = bb.size();
		for (int i = 0; i < m - n + 1; ++i) {
			int j = 0;
			for (; j < n; ++j) {
				if (aa[i + j] != bb[j]) break;
			}
			if (j == n) return i;
		}
		return -1;
	}
};

void test(string aa, string bb) {
	Solution go;
	int res = go.strStr2(aa, bb);
	output(1, res);
}

int main(){
	test("", "");
	test("abcbcde", "bcde");
	test("mississippi", "issip");
	return 0;
}

