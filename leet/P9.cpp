#include<bits/stdc++.h>

using namespace std;

bool isPalindrome1(int x) {
	if(x<0 || (x!=0 &&x%10==0)) return false;
	ll sum = 0;
	while(x > sum) {
		sum = sum*10 + x%10;
		x = x / 10;
	}
	return (x==sum) || (x==sum/10);
}

bool isPalindrome(int x) {
	if (x < 0 ) return false;
	ll tmp = 0;
	int y = x;
	do {
		tmp = tmp*10 + y%10;
		y /= 10;
	} while( y );

	return tmp == x;
}

int main() {
	cout << isPalindrome(0) << endl;	
	cout << isPalindrome(1221) << endl;	
	cout << isPalindrome(-1221) << endl;	
	cout << isPalindrome(1111111122) << endl; // overflow occur	
	return 0;
}
