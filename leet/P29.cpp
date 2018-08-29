#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define mst(x, y) memset(x, y, sizeof(x))
#define fora(e, c) for (auto &e : c)
#define fori(i, a, b) for (int i=(a); i<(b); ++i)
#define ford(i, a, b) for (int i=(a); i>(b); --i)
#define pvi(x) fora(a, x) cout << a << " "; cout << endl
#define par(x, n) fori(a, 0, n) cout << x[a] << " "; cout << endl
#define output(ix, val) cout << "Case #" << (ix) << ": " << (val) << endl

#define trace(...) _f(#__VA_ARGS__, __VA_ARGS__)
template <typename T>
void _f(const char* name, T&& arg) {
  cout << name << ": " << arg << endl;
}

template <typename T, typename... Args> 
void _f(const char* names, T&& arg, Args&&... args) {
  const char* split = strchr(names + 1, ','); 
  cout.write(names, split - names) << ": " << arg << " |";
  _f(split, args...); 
} 

#define ll long long

class Solution {
public:
	int divide(int dividend, int divisor) {
		if (!divisor || (dividend == INT_MIN && divisor == -1))
			return INT_MAX;
		int sign = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1;
		ll dvd = labs(dividend);
		ll dvs = labs(divisor);
		int res = 0;
		// aa / bb
		// aa = (bb * 2 * 2 * 2 ... ) + ((aa - bb) * 2 * 2 ... )
		while (dvd >= dvs) { 
			ll temp = dvs, multiple = 1;
			while (dvd >= (temp << 1)) {
				temp <<= 1;
				multiple <<= 1;
			}
			dvd -= temp;
			res += multiple;
		}
		return sign == 1 ? res : -res; 
	}
};

void test(string rep, int aa, int bb) {
	Solution go;
	int res = go.divide(aa, bb);
	output(rep, res);
}

int main() {
  test("0/2=", 0, 2);
  test("10/2=", 10, 2);
  test("10/3=", 10, 3);
  test("-10/5=", -10, 5);
  test("10/7=", 10, 7);
  test("10/10=", 10, 10);
  test("10/11=", 10, 11);
  test("-1/1=", -1, 1);
  test("1/-1=", 1, -1);
  test("-1/-1=", -1, -1);
  test("2147483647/1=", 2147483647, 1);
  test("-2147483647/1=", -2147483647, 1);
  test("2147483647/-1=", 2147483647, -1);
  test("-2147483647/-1=", -2147483647, -1);
  test("2147483647/2=", 2147483647, 2);
  test("2147483647/10=", 2147483647, 10);
  test("-2147483648/1=", -2147483648, 1);
  test("-2147483648/-1=", -2147483648, -1);
	return 0;
}
