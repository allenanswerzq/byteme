#include<bits/stdc++.h>
using namespace std;


const double EPS = 1e-9;
int cmp(double x, double y = 0, double tol = EPS) {
  return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;

class Solution {
public:
		bool isPrime(int x) {
			int ones=0;
			while (x) {
				ones++;
				x = x&(x-1);
			}
			for (int i=2; i*i<=ones; ++i){
				if (ones%i == 0) return false;
			}
			return true;
		}	

  int countPrimeSetBits(int L, int R) {
			int ret=0;
			for (int i=L; i<R; ++i) {
				if (isPrime(i))	
					ret++;
			}        
			return ret;
  }
};

