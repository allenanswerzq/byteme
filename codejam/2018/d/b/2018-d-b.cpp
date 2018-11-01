#include<bits/stdc++.h>
using namespace std;

const int size = 1e5 + 5;
int p[size];
int h[size];
int x[size];
int y[size];
int tx[size], ty[size];
int bx[size], by[size];
int idt[size], idb[size];

void read_arr(int *arr, int n) {
  int a, b, c, m;
  cin >> arr[1] >> arr[2] >> a >> b >> c >> m;
  fori (i, 3, n + 1) {
    arr[i] = (1ll * a * arr[i-1] + 1ll * b * arr[i-2] + c) % m + 1; 
  }
}

bool cmp_t(int i, int j) {
  return tx[i] < tx[j];
}

bool cmp_b(int i, int j) {
  return bx[i] < bx[j];
}

int solve() {
  int nn, kk; cin >> nn >> kk;
  read_arr(p, nn);
  read_arr(h, nn);
  read_arr(x, kk);
  read_arr(y, kk);

  // par(p, nn + 1);
  // par(h, nn + 1);
  // par(x, kk + 1);
  // par(y, kk + 1);

  fori (i, 1, nn + 1) {
    idt[i] = i;
    tx[i] = p[i] - h[i]; // x - y
    ty[i] = p[i] + h[i]; // x + y
  }

  fori (i, 1, kk + 1) {
    idb[i] = i;
    bx[i] = x[i] - y[i];
    by[i] = x[i] + y[i]; 
  }

  sort(idt + 1, idt + nn + 1, cmp_t); 
  sort(idb + 1, idb + kk + 1, cmp_b);

  int ix = 1;
  int max_y = nnf;
  int res = 0;

  // For each balloon check whether there exist suitable tower or not.
  // Starting from tower `idt[ix]`.
  fori (i, 1, kk + 1) {  
    while (ix <= nn && tx[idt[ix]] <= bx[idb[i]]) {
      max_y = max(max_y, ty[idt[ix]]); 
      ++ix;
    } 
    res += max_y >= by[idb[i]];
  } 
  return res;
}

int main(int argc, char** argv) {
  std::ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.precision(5);
  cout << fixed; 

  int t; cin >> t;
  fori (i, 1, t + 1) {
    int r = solve();
    output(i, r);  
  }  

  return 0;
}
