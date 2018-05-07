#include <cstdio>  
#include <cmath>
#include <climits>
#include <cstdlib>
#include <ctype.h> // <cctype> isalpha isdigit
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <string>   // std:string std:stoi
#include <sstream>  // std:istringstream
#include <queue>
#include <deque>
#include <iterator>

using namespace std;

void printVector(vector<int>& v) {
    printf("[ ");
    for (auto x:v)
        printf("%d ", x); 
    printf("]\n");
}

// accepted
class MagicDictionary {
private:
  vector<string> dict;
  bool compare(string a, string b) {
    if (a.size() != b.size()) return false;
    int k=0;
    for (int i=0; i<a.size(); ++i) {
      if (a[i] - b[i] != 0) k++;
      if (k > 1) return false;  
    }
    return k == 1;
  }
public:
    /** Initialize your data structure here. */
    MagicDictionary() {
          
    }
    
    /** Build a dictionary through a list of words */
    void buildDict(vector<string> d) {
      dict = d;      
    }
    
    /** Returns if there is any word in the trie that equals to the given word after modifying exactly one character */
    bool search(string word) {
       for (int i=0; i<dict.size(); ++i)
        if (compare(word, dict[i])) return true; 
       return false;
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary obj = new MagicDictionary();
 * obj.buildDict(dict);
 * bool param_2 = obj.search(word);
 */
