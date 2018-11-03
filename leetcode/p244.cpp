#include<bits/stdc++.h>
using namespace std;

// This is a follow up of Shortest Word Distance. 
// The only difference is now you are given the list of words and 
// your method will be called repeatedly many times with different parameters. 
// How would you optimize it?
// Design a class which receives a list of words in the constructor, 
// and implements a method that takes two words word1 and word2 
// and return the shortest distance between these two words in the list.
// For example,
// Assume that words = ["practice", "makes", "perfect", "coding", "makes"].
// Given word1 = “coding”, word2 = “practice”, return 3.
// Given word1 = "makes", word2 = "coding", return 1.

class WordDistance {
public:
  WordDistance(vector<string> words) {
    int n = words.size();
    for (int i = 0; i < n; i++)
      wordMap[words[i]].push_back(i);
  }

  int shortest(string word1, string word2) {
    vector<int> idx1 = wordMap[word1];
    vector<int> idx2 = wordMap[word2];
    int m = idx1.size(), n = idx2.size();
    int i = 0, j = 0, dist = INT_MAX;
    // Note: how to get minimum difference between two sorted list
    while (i < m && j < n) {    
      dist = min(dist, abs(idx1[i] - idx2[j]));
      if (idx1[i] < idx2[j]) i++;
      else j++;
    }
    return dist;
  }
  
private:
  unordered_map<string, vector<int>> wordMap;
};


// Your WordDistance object will be instantiated and called as such:
// WordDistance wordDistance(words);
// wordDistance.shortest("word1", "word2");
// wordDistance.shortest("anotherWord1", "anotherWord2");

int main(int argc, char** argv) {
  return 0;
}
