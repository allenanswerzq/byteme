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

// Not that good, but accepted
// reference: https://en.wikipedia.org/wiki/Multiplication_algorithm
string multiply(string a, string b) {
	int p = a.size();
	int q = b.size();
  	int product[p+q] = {0};     
	string result = "";
  	reverse(a.begin(), a.end());
  	reverse(b.begin(), b.end());
	//cout << a << " " << b << endl;
  	for (int i=0; i<q; ++i) {   // for all digits in b
		int carry = 0;
		for (int j=0; j<p; ++j) {   //for all digits in a
			product[i + j] += carry + (a[j]-'0') * (b[i]-'0');
			//cout << a[j] << " " << b[i] << " "<< product[i+j] << endl;
			carry = product[i + j] / 10;
			product[i + j] = product[i + j] % 10;
		}
		product[i + p] += carry;      // last digit comes from final carry
  }

  // remove the leading zero
  int i = p+q-1;
  while (i>=0 && !product[i]) --i;
  if (i==0) return "0";
  while(i >= 0) {
	  result += product[i]+'0';
	  --i;
  }
  return result;
}

int main(int argc, char** argv) {
	cout << multiply("1234", "1111") << endl;
    return 0;
}
