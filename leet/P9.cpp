#include <iostream>
#include <stdio.h>

using namespace std;

bool isPalindrome1(int x) {
	if(x<0|| (x!=0 &&x%10==0)) return false;
	int sum=0;
	while(x>sum)
	{
		sum = sum*10+x%10;
		x = x/10;
	}
	return (x==sum)||(x==sum/10);
}

bool isPalindrome(int x) {
	if (x < 0 ) return false;
	int ans = 0;
	int y = x;
	do {
		// NOTE: ans maybe overflow 
		ans = ans*10 + y%10;
		y /= 10;
	} while( y );

	cout << ans << endl;
	if (ans == x) return true;
	else return false;
}

int main() {
	cout << isPalindrome(0) << endl;	
	cout << isPalindrome(1221) << endl;	
	cout << isPalindrome(-1221) << endl;	
	cout << isPalindrome(1111111122) << endl; // overflow occur	
	return 0;
}
