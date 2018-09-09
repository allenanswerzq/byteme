#include<bits/stdc++.h>

using namespace std;

int jran;
int random(int jlo, int jhi) {
  int im=6075, ia=106, ic=1283;
  jran = (jran * ia + ic) % im;
  int j = jlo + ((jhi - jlo + 1) * jran) / im;
  return j;
}

// Non-deterministic
int random_random(int lo, int hi) {
  random_device rd;
  uniform_int_distribution<int> dist(lo, hi);
  return dist(rd);
}

vi shuffle(vector<int>& a) {
  int n = sz(a), l=n;
  vi res(n, 0), v(a);

  fori(i, 0, n) {
    int choice = random_random(0, l-1);
    res[i] = v[choice];
    v.erase(v.begin() + choice);
    l = sz(v);
  }
  return res;
}

vi shuffle_in_place(vi& a) {
  int n = sz(a);
  fori(i, 0, n-1) {
    int choice = random_random(i, n-1);
    if (i != choice)
      swap(a[i], a[choice]);
  }
  return a;
}

int main(int argc, char** argv) {
  std::ios_base::sync_with_stdio(false);
  // Choose a random seed
  jran = 200;
  vi v = {1, 2, 3, 4, 5};
  vi vv = shuffle(v);
  fora(x, vv)
    cout << x << ' ';
  cout << '\n';

  vv = shuffle_in_place(v);
  fora(x, vv)
    cout << x << ' ';
  cout << '\n';
  return 0;
}
