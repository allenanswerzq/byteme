#include<bits/stdc++.h>
using namespace std;




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

const double eps = 1e-9;
int dcmp(double x, double y = 0, double tol = eps) {
  return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}


const int maxn = 100;
char mat[maxn][maxn];
int solve() {
  int n; cin >> n;
  mst(mat, 0);
  fori (i, 1, n + 1) {
    string a; cin >> a;
    fori (j, 1, n + 1)
      mat[i][j] = a[j - 1];
  }
  // Find the center of 'X' symbol.
  int cnt = 0;
  fori (i, 1, n + 1) {
    fori (j, 1, n + 1) {
      if (mat[i][j] != 'X') continue;
      int one = 0;
      fori (k, 1, n + 1) 
        one += mat[i][k] == 'X';
      fori (k, 1, n + 1)
        one += mat[k][j] == 'X';
      if (one == 2) {
        ++cnt;
        mat[i][j] = '.';
      }
    }
  } 
  if (cnt > 1 || cnt == 0) return 0;

  fori (i, 1, n + 1) {
    fori (j, 1, n + 1) {
      if (mat[i][j] != 'X') continue;
      int x = -1, y = -1;
      fori (k, i + 1, n + 1) {
        fori (l, 1, n + 1) {
          if (l != j && mat[k][l] == 'X' && 
              mat[i][l] == 'X' && mat[k][j] == 'X')  {
            if (x == -1)  {
              x = k; y = l;
            } else 
              return 0;
          }
        }
      } 
      if (x == -1)  return 0;
      mat[i][j] = '.';
      mat[x][j] = '.';
      mat[i][y] = '.';
      mat[x][y] = '.';
      cnt += 2;
    }
  }  
  return cnt == n;
}

int main(int argc, char** argv) {
  std::ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.precision(5);
  cout << fixed; 

  freopen("2017-c-b-SSSSSSmall.txt", "rt", stdin);
  clock_t begin = clock();

  int t; cin >> t;
  fori (i, 1, t + 1) {
    int r = solve(); 
    output(i, r ? "POSSIBLE" : "IMPOSSIBLE"); 
  }

  clock_t end = clock();
  double elapsed = double(end - begin) / CLOCKS_PER_SEC;
  cerr << "Elapsed: " << elapsed;
  return 0;
}
