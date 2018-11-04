#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define pend cout << '\n'
#define pvar(x) cout << #x << ": "
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define mst(x, y) memset(x, y, sizeof(x))
#define fora(e, c) for (auto &e : c)
#define fori(i, a, b) for (int i = (a); i < (b); ++i)
#define ford(i, a, b) for (int i = (a); i > (b); --i)
#define output(v) cout << (v) << '\n'
#define codejam(ix, v) cout << "Case #" << (ix) << ": " << (v) << '\n'
#define pvi(x, v) if(v) pvar(x); fora(a, x) cout << a << " "; pend
#define par(x, n, v) if(v) pvar(x); fori(a, 0, n) cout << x[a] << " "; pend

#define trace(...) _f(#__VA_ARGS__, __VA_ARGS__)
template <typename T>
void _f(const char* name, T&& arg) {
  cout << name << ": " << arg << '\n';
}

template <typename T, typename... Args>
void _f(const char* names, T&& arg, Args&&... args) {
  const char* split = strchr(names + 1, ',');
  cout.write(names, split - names) << ": " << arg << " |";
  _f(split, args...);
}

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<vs> vvs;
typedef pair<int, int> pii;
typedef vector<pii> vpii;

class TrieNode {
public:
  #define alphas 26
  TrieNode *child[alphas];
  int leaf;

  TrieNode() {
    for (int i = 0; i < alphas; i++)
      this->child[i] = nullptr;
    this->leaf = 0;
  }

  void insert(string s) {
    TrieNode *head = this;
    for (int i = 0; i < (int)s.size(); i++) {
      if (head->child[s[i] - 'a'] == nullptr)
        head->child[s[i] - 'a'] = new TrieNode();
      head = head->child[s[i] - 'a'];
    }
    // Note: here leaf can be used to store data.
    head->leaf++;
  }


  void walk(vector<char> &path) {
    TrieNode *head = this;
    if (head->leaf) {
      for (auto c : path) cout << c;
      cout << '\n';
      return;
    }

    for (int i = 0; i < alphas; i++)
      if (head->child[i] != nullptr) {
        path.push_back(char(i + 'a'));
        // cout << char(i + 'a') << " ";
        head->child[i]->walk(path);
        path.pop_back();
      }
  }

  void walk() {
    vector<char> path;
    walk(path);
  }

  // Find a string in this trie tree.
  // Returns:
  //    head->leaf: string in this trie tree.
  //    -1: string not in this trie tree.
  int find(string s) {
    TrieNode *head = this;
    for (int i = 0; i < (int)s.size(); ++i) {
      if (head->child[s[i] - 'a'] != nullptr)
        head = head->child[s[i] - 'a'];
      else return -1;
    }
    return head->leaf;
  }

  bool notLeaf() {
    if (this->leaf == 1)
      return false;
    return true;
  }
};


int main(int argc, char** argv) {
  vs ret;
  TrieNode *root = new TrieNode();

  int n; cin >> n >> ws;
  fori (i, 1, n + 1) {
    string ss, tt; cin >> ss;
    int c = root->find(ss);
    if (c >= 1) {
      tt = ss + " " + to_string(c + 1);
    } else {
      fori (i, 1, sz(ss) + 1) {
        tt = ss.substr(0, i);
        if (root->find(tt) == -1) break;
      }
    }

    root->insert(ss);
    ret.pb(tt);
  }

  // root->walk();

  fora (s, ret) {
    output(s);
  }

  return 0;
}

