#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	// solution 2
	vector<vector<int>> matrixReshape(vector<vector<int>>& a, int r, int c) {
		int n = a.size();
		int m = a[0].size();
		if (n == 0) return a;
		if (r*c != n*m) return a;
		// NOTE: init a two dems vector with r rows and c cols
		vector<vector<int>> ret;
		vector<int> t;
		for (int i=0; i<n; ++i) {
			for (int j=0; j<m; ++j) {
				t.push_back(a[i][j]);
				if ((int)t.size() == c) {
					ret.push_back(t);
					t.clear();
				}
			}
		}	
		return ret;
	}
	// soultion 1
	vector<vector<int>> matrixReshape1(vector<vector<int>>& a, int r, int c) {
		int n = a.size();
		int m = a[0].size();
		if (n == 0) return a;
		if (r*c != n*m) return a;
		// NOTE: init a two dems vector with r rows and c cols
		vector<vector<int>> ret(r, vector<int>(c));
		for (int i=0; i<n; ++i) {
			for (int j=0; j<m; ++j) {
				int pos = i*m + j;	
				ret[pos / c][pos % c] = a[i][j];
			}
		}	
		return ret;
	}
	
	void out(vector<vector<int>>& a) {
		// NOTE: auto need -std=c++11
		cout << "row: " << a.size() << " col: " << a[0].size() << endl;
		for (auto& row: a) { 
					for (auto& col : row)
						cout << col << " ";
					cout << endl;
			}	
		}
};


int main(void) {
	int d[2][2] = { {1, 2},
					{3, 4}
	};
	vector<vector<int>> a;
	vector<int> t;
	t.push_back(d[0][0]);
	t.push_back(d[0][1]);
	a.push_back(t);
	t.clear();
	t.push_back(d[1][0]);
	t.push_back(d[1][1]);
	a.push_back(t);
	/*
	vector<vector<int>> a;
	int myints[] = {16,2};
    vector<int> t(myints, myints + sizeof(myints) / sizeof(int) );	
	a.push_back(t);
	int m[] = {4, 5};
	vector<int> n(m, m + sizeof(m) / sizeof(int));	
	a.push_back(n);
	*/

	Solution s;
	cout << "Before Reshape: " << endl;
	s.out(a);
	cout << "After Reshape: " << endl;
	
	vector<vector<int>> ret = s.matrixReshape(a, 1, 4);
	s.out(ret);

}
