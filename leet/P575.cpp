#include <iostream>
#include <stdio.h>
#include <map>
#include <vector>
#include <set> // NOTE
using namespace std;

int distributeCandies(vector<int>& candies) {
    map<int, int> m;
	int n = candies.size() / 2;
	int ret;
 	for (auto c : candies) 
		m[c]++;

/*	if (m.size() >= n) return n;
	else return m.size();*/
	return min(m.size(), n);
}

int main()
{
	int n[] = {1, 1, 2, 2, 3, 3};
	vector<int> c1(n, n+6);
	int a[] = {1, 1, 2, 3};
	vector<int> c2(a, a+4);
	int b[] = {1, 2};
	vector<int> c3(b, b+2);
	int d[] = {1,1,1,1,2,2,2,3,3,3};
	vector<int> c4(d, d+10);
	
	cout << "Max kinds:" << distributeCandies(c1) << endl;
	cout << "Max kinds:" << distributeCandies(c2) << endl;
	cout << "Max kinds:" << distributeCandies(c3) << endl;
	cout << "Max kinds:" << distributeCandies(c4) << endl;
	return 0;
}
