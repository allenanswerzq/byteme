#include<bits/stdc++.h>
using namespace std;

//Given a list of words and two words word1 and word2, 
//return the shortest distance between these two words in the list.
//word1 and word2 may be the same and they represent two individual words in the list.
//For example,
//Assume that words = ["practice", "makes", "perfect", "coding", "makes"].
//Given word1 = “makes”, word2 = “coding”, return 1.
//Given word1 = "makes", word2 = "makes", return 3.

int shortestDistance(vector<string> words, string word1, string word2) {
  int m = -1, n = -1; 
  int ret = (1 << 31) - 1;
  
  for (int i=0; i<words.size(); ++i) {
    if (word1 == word2) {
      if (words[i] == word1) {
        if (m > n) n = i;
        else m = i;
      }
    } else { 
      if (words[i] == word1) m = i;
      if (words[i] == word2) n = i;
    }

    if (m>=0 && n>=0)
      ret = min(ret, abs(m-n));
  }
  return ret;
}

int main(int argc, char** argv) {
  return 0;
}