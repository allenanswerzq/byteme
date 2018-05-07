#include <stdio.h>
#include <iostream>

using namespace std;

int romanToInt(string s) {
	string syms[] = {"I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"};
	int value[]   = {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};
	int ret = 0;
	int k = 0;
	for(int i=12; k<s.size() && i>=0; --i) {
		int t = syms[i].size();
		while(s.substr(k, t) == syms[i]) {
			ret += value[i];
			k += t;
		}
	}
	return ret;
}

string intToRoman(int num) {
	string syms[] = {"I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"};
	int value[]   = {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};
	string ret = "";
	for (int i=12; num!=0; --i)
		while (num >= value[i]) {
			ret += syms[i];
			num -= value[i];
		}
	return ret;
}

int main(){
	cout << intToRoman(3) << endl;
	cout << romanToInt("III") << endl;
	cout << intToRoman(1904) << endl;
	cout << romanToInt("MCMIV") << endl;
	cout << intToRoman(1954) << endl;
	cout << romanToInt("MCMLIV") << endl;
	cout << intToRoman(1990) << endl;
	cout << romanToInt("MCMXC") << endl;
	cout << intToRoman(2014) << endl;
	cout << romanToInt("MMXIV") << endl;

	return 0;
}
