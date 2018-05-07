#include <cstdio>
#include <stdio.h> // for using printf
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
#include <tuple>
#include <deque>
#include <stack>
#include <sstream>  // std:istringstream
#include <queue>
#include <iterator>

using namespace std;

void printVector(vector<int>& v) {
  printf("[ ");
  for (auto x:v)
      printf("%d ", x);
  printf("]\n");
}

void printMatrix(vector<vector<int>>& v) {
  printf("{\n");
  for (auto x:v)
    printVector(x);
  printf("}\n");
}

bool isPowerOfTwo(int x) {
  //return (x && !(x & (x-1)));
  return x* !(x&(x-1)) > 0;
}

int countOne (int n){
  while( n ){
    n = n&(n-1);
    count++;
  }
  return count;
}

char toupper( char a ) {
  return ((a >= 'a' && a <= 'z') ? a-('a'-'A') : a );
}

int main(int argc, char** argv) {
  return 0;
}

//Given a list of words and two words word1 and word2, return the shortest distance between these two words in the list.
//word1 and word2 may be the same and they represent two individual words in the list.
//For example,
//Assume that words = ["practice", "makes", "perfect", "coding", "makes"].
//Given word1 = “makes”, word2 = “coding”, return 1.
//Given word1 = "makes", word2 = "makes", return 3.

int shortestDistance(vector<string> words, string word1, string word2) {
  int m = -1, n = -1; 
  int ret = INT_MAX;
  
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