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

// TODO
class Solution {
public:
  vector<int> findSubstring(string ss, vector<string>& dicts) {
  vector<int> res;
  if (ss.size() <= 0 || dicts.size() <= 0 ){
    return res;
  }
  
  int n = ss.size(), m = dicts.size(), l = dicts[0].size();

  // Put all words into a map
  map<string, int> expected;
  for(int i = 0; i < m; i++) {
    expected[dicts[i]]++;
  }
  
  for (int i = 0; i < l; ++i) {
  	  map<string, int> actual;
  	  int count = 0;
  	  int winLeft = i;
  	  for (int j = i; j <= n - l; j += l) {
    string word = ss.substr(j, l);
    // If not found, then restart from j + 1;
    if (!expected.count(word)) {
      actual.clear();
      count = 0;
      winLeft = j + l;
      continue;
    }
    count++;

    // Count the number of "word"
    actual[word]++;

    // If there is more appearance of "word" than expected
    if (actual[word] > expected[word]) {
      string tmp;
      do {
      tmp = ss.substr(winLeft, l);
      count--;
      actual[tmp]--;
      winLeft += l; 
      } while(tmp != word);
    }

    // If total count equals dicts's size, find one res
    if (count == m) {
      res.push_back(winLeft);
      string tmp = ss.substr(winLeft, l);
      actual[tmp]--;
      winLeft += l;
      count--;
    }
  	  } 
  }
	  return res;
	}
};

class Solution1 {
public:
  vector<int> findSubstring(string ss, vector<string>& words) {
  vector<int> res;
  if (ss.empty() || words.empty()) return res;

  int n = words.size(), m = words[0].size();
  unordered_map<string, int> mp1;

  for (auto &a : words) 
    ++mp1[a];

  for (int i = 0; i <= (int)ss.size() - n * m; ++i) {
    unordered_map<string, int> mp2;
    int j = 0; 
    for (j = 0; j < n; ++j) {
      string tmp = ss.substr(i + j * m, m);
      if (!mp1.count(tmp)) break;
      ++mp2[tmp];
      if (mp2[tmp] > mp1[tmp]) break;
    }
    if (j == n) res.push_back(i);
  }
  return res;
  }
};


#define vi vector<int>
#define vs vector<string>

void test(string aa, vs bb) {
  Solution1 go;
  vi res = go.findSubstring(aa, bb); 
  pvi(res);
}

int main() {
  test("aaaaaaaa", {"aa","aa","aa"});
	test("barfoothefoobarman", {"foo", "bar"});
	test("barfoothefoobarman", {"foo", "bar", "the"});
	test("barfoofoothefoobarman", {"foo", "bar"});
	test("wordgoodgoodgoodbestword", {"word","good","best","good"});
  test("wordgoodstudentgoodword", {"word","student"});
	test("lingmindraboofooowingdingbarrwingmonkeypoundcake", {"fooo","barr","wing","ding","wing"});
	return 0;
}
