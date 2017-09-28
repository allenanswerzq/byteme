#include <cstdio>  
#include <cmath>
#include <climits>
#include <cstdlib>
#include <ctype.h> // <cctype> isalpha isdigit
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <string>   // std:string std:stoi
#include <tuple>
#include <queue>
#include <deque>

using namespace std;

void printVector(vector<int>& v) {
    cout << "[ ";
    for (auto x:v)
        cout << x << " ";
    cout <<"] " << endl;
}

typedef long long int64;
string fractionToDecimal(int numerator, int denominator) {
    if (denominator==0) return "";
    if (!numerator) return "0";

    string res;
    // determine final result sign
    if (numerator<0 ^ denominator<0) res += "-";
    // Note: overflow case
    // and convert all nubmer into postive number
    int64 x = numerator<0 ? (int64)numerator*(-1) : (int64)numerator; 
    int64 y = denominator<0 ? (int64)denominator*(-1) : (int64)denominator;

    int64 quotient = x / y;
    int64 reminder = x % y;
    res += to_string(quotient);
    if (reminder == 0)
        return res;

    res += ".";
    map<int, int> mp;
    int k = 0;
    string rep = "";
    string ans = "";
    while (reminder) {
        int z = reminder;
        reminder = reminder * 10;
        mp[z] = k++;
        rep += to_string(reminder / y);
        reminder = reminder % y;
        if (mp.find(reminder) != mp.end()) {
            ans = rep.substr(0, mp[reminder]);
            rep = "(" + rep.substr(mp[reminder]) + ")";
            break;
        }
    }
    return res + ans + rep; 
}

int main(int argc, char** argv) {
    fractionToDecimal(1, 7);
    return 0;
}
