#include<bits/stdc++.h>
using namespace std;

#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define mst(x, y) memset(x, y, sizeof(x))
#define output(val) cout << (val) << endl;
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

class Solution {
public:
  vector<TreeNode*> allPossibleFBT(int num) {
    if (num % 2 == 0) return {};
    if (num == 1) {
      TreeNode *node = new TreeNode(0);
      return {node};
    }

    vector<TreeNode*> one, two, ret;
    fori (i, 1,  num - 1) {
      one = allPossibleFBT(i);
      two = allPossibleFBT(num - i - 1);
      fora (a, one) {
        fora (b, two) {
          TreeNode *root = new TreeNode(0);
          root->left = a;
          root->right = b;
          ret.push_back(root); 
        }
      }
    }

    // trace(num, sz(ret));
    return ret;
  }
};

int main() {
}
