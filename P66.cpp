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
vector<int> plusOne(vector<int>& A) {
	int n = A.size();
	int i = n-1;
	int c = 0;
	int v = A[i] + 1;
	A[i] = v%10;
	c = v/10;
	i--;
	while (i>=0 && c) {
		v = A[i] + 1;
		A[i--] = v%10;
		c = v/10;
	}
	if (c) {
		A.insert(A.begin(), 1);
	}
	return A;
}

int main(int argc, char** argv) {
    return 0;
}
