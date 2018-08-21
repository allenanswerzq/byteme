#include<bits/stdc++.h>

using namespace std;

int divide1(int dividend, int divisor) {
	if (!divisor || (dividend == INT_MIN && divisor == -1))
		return INT_MAX;
	int sign = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1;
	long long dvd = labs(dividend);
	long long dvs = labs(divisor);
	int res = 0;
	while (dvd >= dvs) { 
		long long temp = dvs, multiple = 1;
		while (dvd >= (temp << 1)) {
			temp <<= 1;
			multiple <<= 1;
		}
		dvd -= temp;
		res += multiple;
	}
	return sign == 1 ? res : -res; 
}

int divide(int dividend, int divisor) {
	int sign = ( (dividend < 0) ^ (divisor < 0) ) ? -1 : 1;
	unsigned int result = 0;
	unsigned int dvd = dividend < 0 ? -dividend : dividend; 
	unsigned int dvs = divisor < 0 ? -divisor : divisor; 
	/*
	cout << "=======================================" << endl;
	cout << "Unsigned: " << dvd << " " << dvs << endl;
	long long  dvdd = dividend < 0 ? -dividend : dividend; 
	long long  dvss = divisor < 0 ? -divisor : divisor; 
	cout << "Long: " << dvdd << " " << dvss << endl;
	*/

	// *It worked, but very slow.
	/*
	long long tmp = dvs;
	while (dvd >= (tmp << 1)) {
		dvd -= (tmp<<1);
		result += 2; 
	}
	while (dvd >= dvs) {
		dvd -= dvs;
		result += 1; 
	}*/

	int k = 0;	
	cout << "==================================================" << endl;
	while (dvd >= dvs) {
		// NOTE: tmp type 
		long long tmp = dvs, var = 1;
		while (dvd >= (tmp<<1)) {
			tmp <<= 1;
			var <<= 1;
			//cout << "TMP: " << tmp << endl;
		}
		dvd -= tmp;
		result += var;
		cout << ++k << " " << tmp << " " << dvd << " " << result << endl;
	}
	

	// NOTE:
	if (result > INT_MAX && sign > 0) {
		return INT_MAX;
	}	

	return (int)result * sign;
	
}

int main() {
	long long t = abs(-2147483648);
	// https://stackoverflow.com/questions/11243014/why-the-absolute-value-of-the-max-negative-integer-2147483648-is-still-2147483
	cout << abs(-2147483648) << " " << t << endl;
	
	// NOTE:
	unsigned int a = 2147483648;
	//long long b = 2147483648;
	unsigned int b = 2147483648;
	cout << (b<<1) << endl;
	if (a >= (b<<1) ) cout << "TRUE" << endl;
	else cout << "FALSE" << endl;
	
	//unsigned int a = 2147483648<<1;
	//cout << "Unsigned INT_MAX" << a << " " << UINT_MAX << endl;
    cout << "0/2=" << divide(0, 2) << endl;
    cout << "10/2=" << divide(10, 2) << endl;
    cout << "10/3=" << divide(10, 3) << endl;
    cout << "-10/5=" << divide(-10, 5) << endl;
    cout << "10/7=" << divide(10, 7) << endl;
    cout << "10/10=" << divide(10, 10) << endl;
    cout << "10/11=" << divide(10, 11) << endl;
    cout << "-1/1=" << divide(1, -1) << endl;
    cout << "1/-1=" << divide(1, -1) << endl;
    cout << "-1/-1=" << divide(-1, -1) << endl;
    cout << "2147483647/1=" << divide(2147483647, 1) << endl;
    cout << "-2147483647/1=" << divide(-2147483647, 1) << endl;
    cout << "2147483647/-1=" << divide(2147483647, -1) << endl;
    cout << "-2147483647/-1=" << divide(-2147483647, -1) << endl;
    cout << "2147483647/2=" << divide(2147483647, 2) << endl;
    cout << "2147483647/10=" << divide(2147483647, 10) << endl;
    cout << "-2147483648/1=" << divide(-2147483648, 1) << endl;
    cout << "-2147483648/-1=" << divide(-2147483648, -1) << endl;
	return 0;
}
