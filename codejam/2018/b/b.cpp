#include<bits/stdc++.h>
using namespace std;

vvi inp;
string solve(int n, int k, ll p) {
  unordered_set<int> st;
  vi arr(n, 0);
  fora (a, inp) {
    int ix = a[0] - 1;
    arr[ix] = a[2];
    st.insert(ix);
  }

  p = p - 1;
  int j = n - 1;
  while (p) {
    int x = p & 1;
    while (st.count(j)) --j;
    arr[j--] = x;
    p = p >> 1;
  }

  string res = "";
  fori (i, 0, n) {
    res += (char)(arr[i] + '0');
  }
  return res;
}

int main(int argc, char** argv) {
  std::ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.precision(5);
  cout << fixed; 

  int t; cin >> t;
  fori (i, 0, t) {
    inp.clear();
    int n, k; ll p;
    cin >> n >> k >> p;
    fori (i, 0, k) {
      int a, b, c;
      cin >> a >> b >> c;
      inp.pb({a, b, c}); 
    } 
    string r = solve(n, k, p); 
    output(i + 1, r);
  }
  return 0;
}
