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
	string convert(string ss, int n) {
		if (n <= 1 || n >= ss.size()) return ss;
		
		vector<string> r(n);
		int row = 0;
		int step = 1;
		for (int i = 0; i < ss.size(); ++i) {
			r[row] += ss[i];
			if (row == n-1) step = -1;
			if (row == 0) step = 1;
			row += step;
		}	

		string res;
		for (auto c: r)
			res += c;
		return res;
	}
};

void test(string inp, int aa) {
	Solution go;
	string res = go.convert(inp, aa);
	output(1, res);
}

int main() {
	test("PAYPALISHIRING", 3);
	test("PAYPALISHIRING", 4);
	test("AB", 1);
	return 0;
}
