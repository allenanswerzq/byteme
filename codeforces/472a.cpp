#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define mst(x, y) memset(x, y, sizeof(x))
#define outret(val) cout << (val) << endl
#define fora(e, c) for (auto &e : c)
#define fori(i, a, b) for (int i = (a); i < (b); ++i)
#define ford(i, a, b) for (int i = (a); i > (b); --i)
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

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<vector<string>> vvs;
typedef pair<int, int> pii;
typedef vector<pii> vpii;

// define LOCAL_FILE

bool is_prime(int number) {
  if (((!(number & 1)) && number != 2) 
      || (number < 2) 
      || (number % 3 == 0 && number != 3))
    return false;

  for (int k = 1; 36 * k * k - 12 * k < number; ++k) {
    if ((number % (6 * k + 1) == 0) || (number % (6 * k - 1) == 0))
      return false;   
  }
  return true;
}


int main(int argc, char** argv) {
#ifdef LOCAL_FILE
  // freopen("472a-input.txt", "rt", stdin);
  clock_t begin = clock();
#endif

  int n; cin >> n >> ws;
  int a = 4, b = n - a;
  while (is_prime(b)) {
    a += 2;
    b -= 2;
  }

  cout << a << " " << b << endl;

#ifdef LOCAL_FILE
  clock_t end = clock();
  double elapsed = double(end - begin) / CLOCKS_PER_SEC;
  cout << "elapsed(s): " << elapsed << endl;
#endif

  return 0;
}
