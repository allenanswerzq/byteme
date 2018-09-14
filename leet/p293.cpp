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

// You are playing the following Flip Game with your friend: 
// Given a string that contains only these two characters: + and -, 
// you and your friend take turns to flip twoconsecutive "++" into "--". 
// The game ends when a person can no longer make a move and 
// therefore the other person will be the winner.

// Write a function to compute all possible states of the string after one valid move.
// For example, given s = "++++", after one move, it may become one of the following states:
// [
//   "--++",
//   "+--+",
//   "++--"
// ]
// If there is no valid move, return an empty list [].

// #define LOCAL_FILE

#define vs vector<string>

class Solution {
public:
  vs generatePossibleNextMoves(string aa) {
    vs res;
    fori (i, 0, sz(aa) - 1) {
      if (aa[i] == '+' && aa[i + 1] == '+')
      res.push_back(
        aa.substr(0, i) + 
        "--" + 
        aa.substr(i + 2));
    } 
    return res;
  }
};

int main(int argc, char** argv) {
  return 0;
}
