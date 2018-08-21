#include<bits/stdc++.h>

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
			// before rotate x
			int x = k, y = i;	
			int a = A[x][y]; 	
			int cnt = 4;
			while (cnt-- > 0) {
				// rotate x to a new x
				int nx = y, ny = n - 1 - x;
				// save current val for next use
				int b = A[nx][ny]; 	
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
