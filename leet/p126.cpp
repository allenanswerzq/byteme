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

class Node {
public:
  string word;
  int level;
  Node* pre;
  Node (string w, int l, Node* p) {
    word = w;
    pre = p;
    level = l;
  }
};

vvs findLadders(string start, string end, vs& wordList) {
    vvs res;
    queue<Node*> que; 
    unordered_set<string> wordSet(wordList.begin(), wordList.end());
    if (!wordSet.count(end)) return res;
    if (wordSet.count(start)) wordSet.erase(start);
    int level = 1;
    bool ok = 0;
    que.push(new Node(start, level, nullptr));
    while (!que.empty()) {
      int n = que.size();
      set<string> del;
      for (int i=0; i<n; ++i) {
        auto node = que.front(); que.pop();
        trace(node->word, node->level);
        if (node->word == end) {
          ok = 1;
          Node* tmp = node;
          vs path;
          while (tmp != nullptr) {
            path.insert(path.begin(), tmp->word);
            tmp = tmp->pre;
          }
          res.pb(path);
        } else {
          fora (w, wordSet) {
            int k = 0;
            fori (i, 0, sz(w)) {
              if (w[i] != node->word[i]) ++k;
              if (k > 1) break;
            } 
            if (k == 1) {
              que.push(new Node(w, level+1, node));
              del.insert(w);
            }
          }  
        } 
      }
      // pvi(del);
      fora (x, del) {
        // trace(x);
        wordSet.erase(x);
      }
      ++level;
      if (ok) break;
    }
    return res;
}


int main(int argc, char** argv) {
  std::ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.precision(5);
  cout << fixed; 

  freopen("p126-IIIIIIIIIN.txt", "rt", stdin);
  clock_t begin = clock();

  // string aa = "hit", bb = "cog";
  // vs cc = {"hot", "dot", "dog", "lot", "log", "cog"};
  // string aa = "a", bb = "c";
  // vs cc = {"a", "b", "c"};
  string aa = "red", bb = "tax";
  vs cc = {"ted","tex","red","tax","tad","den","rex","pee"};
  vvs res = findLadders(aa, bb, cc);
  fora (v, res) {
    pvi(v);
  }

  clock_t end = clock();
  double elapsed = double(end - begin) / CLOCKS_PER_SEC;
  cerr << "Elapsed: " << elapsed;
  return 0;
}
