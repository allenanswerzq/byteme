#include<bits/stdc++.h>
using namespace std;

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
	// Count
	// time complexity O(n + m)
	double findMedianSortedArrays2(vector<int>& aa, vector<int>& bb) {
		int na = aa.size();
		int nb = bb.size();	
		int total = na + nb;
		int i = 0, j = 0, k = 0;
		int sum = 0;
		int tmp = 0;

		while (i < na || j < nb) {

			if (i < na && j < nb) { 
				if (aa[i] <= bb[j]) tmp = aa[i++]; 
				else tmp = bb[j++];
			} else if (i < na) {
				tmp = aa[i++];
			} else {
				tmp = bb[j++];
			}

			if (k == total / 2) sum += tmp;
			if (k == total / 2 - 1 && total % 2 == 0) sum += tmp;
			k++;
		}

		return total % 2 ? sum * 1.0 : sum / 2.0;
	}

	// Merge sort
	// time complexity O(m + n)
	double findMedianSortedArrays1(vector<int>& aa, vector<int>& bb) {
		int na = aa.size();
		int nb = bb.size();	
		vector<int> vv(na + nb, 0);
		int i = 0, j = 0, k = 0;

		while (i < na || j < nb) {
			if (i < na && j < nb) {
				if (aa[i] <= bb[j]) vv[k++] = aa[i++];
				else vv[k++] = bb[j++];
			} else if (i < na) {
				vv[k++] = aa[i++];
			} else {
				vv[k++] = bb[j++];
			}
		}

		// trace(k, na + nb);
		return k % 2 ? vv[k / 2] : (vv[k / 2] + vv[k / 2 - 1]) / 2.0;
	}
};

void test(vi aa, vi bb) {
	Solution go;
	double res = go.findMedianSortedArrays1(aa, bb);
	output(1, res);
}

int main() {
	test({1, 3}, {2});
	test({1, 2}, {3, 4});
	return 0;
}
