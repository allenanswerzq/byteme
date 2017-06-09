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

// when n overflow occurs
// it' not work 
// but same idea in Python
// it ok
double myPow1(double x, int n) {
	if (!n) 
		return 1;
	if (n < 0) 
		return 1 / myPow(x, -n);
	if (n % 2)
		return return x * myPow(x, n-1);
	return myPow(x*x, n/2); // NOTE: x*x not x
}

double myPow(double x, int n) {
	long long t;
	if (n < 0) {
		x = 1/x;
		t = fabs(n);	// NOTE: when n overflow
	}
	double res = 1;
	while (n) {
		if (n % 2) 
			res = res*x;
		x = x*x;
		n = n >> 1;
	}
	return res;
}

int main(int argc, char** argv) {
    return 0;
}
