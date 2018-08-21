#include<bits/stdc++.h>

using namespace std;

int reverse(int x) {
	cout << INT_MAX << " " << INT_MIN << endl;
	long long ret = 0;
	while ( x != 0 ) {
		ret = ret*10 + x % 10;
		x = x / 10;
		if (ret >= INT_MAX || ret <= INT_MIN) return 0;
	} 
	return ret;	
}

int reverse1(int x) {
	if (x == 0) return x;
	long long ret = 0;
	vector<int> v;
	do {
		v.push_back(x % 10);
		x = x / 10;
	} while ( x );

	// for (auto x: v)
	// 	cout << x << " ";
	// cout << endl;

	for (int i=0; i<v.size(); ++i) {
		ret = ret*10 +  v[i];
		if (ret >= INT_MAX || ret <= INT_MIN) return 0;
	}
	return ret;	
}

int main() {
	cout << reverse1(123) << endl;
	cout << reverse1(-123) << endl;
	// cout << reverse(1534236469) << endl;
	// cout << reverse(-2147483648) << endl;
	return 0;
}
