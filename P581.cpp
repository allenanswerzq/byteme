#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>

using namespace std;

int main() {
	vector<int> v({2,6,4,8,10,9,15});
	cout << findUnsortedSubarray(v) << endl;
	vector<int> vv({2,1}); 
	cout << findUnsortedSubarray(vv) << endl;
	vector<int> vvv({1,2,3,4});
	cout << findUnsortedSubarray(vvv) << endl;
	vector<int> vvvv({1,2,1});
	cout << findUnsortedSubarray(vvvv) << endl;
	return 0;
}
