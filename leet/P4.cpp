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

const double eps = 1e-9;
int dcmp(double x, double y = 0, double tol = eps) {
  return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

// Method 1: merge sort
// Method 2: median compare
// Method 3: count 
// Divide & conquer

#define vi vector<int>

class Solution {
public:
	// Below my code is not correct 
	double find(vector<int>& aa, vector<int>& bb, int al, int ah, int bl, int bh) {
		int na = ah - al + 1;
		int nb = bh - bl + 1;
		if (na < 2 && nb < 2) {
			if (na == 1 && nb == 1) return (aa[al] + bb[bl]) / 2.0;
			else if (na == 0 && nb == 1) return bb[bl];	
			else if (na == 1 && nb == 0) return aa[al];
		}

		double am = na % 2 ? aa[na / 2] : (aa[na / 2] + aa[na / 2 - 1]) / 2.0;
		double bm = nb % 2 ? bb[nb / 2] : (bb[nb / 2] + bb[nb / 2 - 1]) / 2.0;
		int ax = na % 2 ? na / 2: na / 2 - 1;
		int bx = nb % 2 ? nb / 2: nb / 2 - 1;
		pvi(aa);
		pvi(bb);
		trace(am, bm, ax, bx, na, nb);
		if (dcmp(am, bm) == 0) return am;
		else if (dcmp(am, bm) == 1) return find(aa, bb, al, ax, bx, bh);     
		else return find(aa, bb, ax, ah, bl, bx);
	}

	double findMedianSortedArrays(vector<int>& aa, vector<int>& bb) {
		int m = aa.size();
		int n = bb.size();
		return find(aa, bb, 0, m-1, 0, n-1);		
	}

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

		if (total % 2 == 0) return sum / 2.0;
		else return (sum * 1.0);
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
