#include <cstdio>  
#include <cmath>
#include <climits>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>

using namespace std;

void printVector(vector<int>& v) {
    cout << "[ ";
    for (auto x:v)
        cout << x << " ";
    cout <<"] " << endl;
}

vector<vector<int>> generateMatrix(int n) {
	vector<int> v(n, 0);
	vector<vector<int>> res(n, v);	
	int r=0, c=0, k=1;
	while (r<(n+1)/2 && c<(n+1)/2) {
		// up
		for (int i=c; i<n-c; ++i) 
			res[r][i] = k++;
		// right
		for (int i=r+1; i<n-r; ++i) 
			res[i][n-c-1] = k++;
		// bottom
		for (int i=n-c-2; n-r-1>r && i>=c; --i)
			res[n-r-1][i] = k++;
		// left
		for (int i=n-r-2; n-c-1>c && i>r; --i)
			res[i][c] = k++;
		r++;
		c++;
	}
	return res;
}

int main(int argc, char** argv) {
    return 0;
}
