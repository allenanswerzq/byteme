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
    for (int x:v)
    	cout << x << " ";
    cout <<"] " << endl;
}

// Perfect!!!
// Accepted
void rotate(vector<vector<int>>& A) {
	int n = A.size();
	for (int k=0; k<n/2; ++k) {
		// NOTE: n-1-k not n-k
		for (int i=k; i<n-1-k; ++i) {
			int x = k; 			// before rotate x
			int y = i;	
			int a = A[x][y]; 	
			int cnt = 4;
			while (cnt > 0) {
				--cnt;
				int nx = y; 		// rotate x to a new x  
				int ny = n-1 - x;
				int b = A[nx][ny]; 	// save current val for next use
				A[nx][ny] = a; 		 
				x = nx;
				y = ny;
				a = b;
			}	
		}
	}	
}

int main(int argc, char** argv) {
    return 0;
}
