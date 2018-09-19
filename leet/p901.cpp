#include<bits/stdc++.h>
using namespace std;

#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define mst(x, y) memset(x, y, sizeof(x))
#define outret(val) cout << (val) << endl;
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

class StockSpanner {
public:
  deque<pii> dq;
  int cnt = 0;
  StockSpanner() {
    dq.push_back({(1<<30), 0}); 
  }
  
  int next(int pp) {
    ++cnt;
    auto top = dq.back();
    int val = top.first;
    int ret = 1;
    if (pp < val) {
      dq.push_back({pp, cnt});
    } else {
      while (pp >= val) {
        // trace(pp, val, cnt);
        dq.pop_back();
        val = dq.back().first;
      } 
      ret = cnt - dq.back().second;
      dq.push_back({pp, cnt});
    }
    return ret;
  }
};

void test() {
  StockSpanner go;
  outret(go.next(100));
  outret(go.next(80));
  outret(go.next(60));
  outret(go.next(70));
  outret(go.next(60));
  outret(go.next(75));
  outret(go.next(85));
}

void test2() {
  StockSpanner go;
  outret(go.next(31));
  outret(go.next(41));
  outret(go.next(48));
  outret(go.next(59));
  outret(go.next(79));
}

int main(int argc, char** argv) {
  test();
  test2();
}
