#include<bits/stdc++.h>
using namespace std;

// Accepted
string replaceWords(vector<string>& dict, string sentence) {
  istringstream in(sentence);
  vector<string> words;
  string word, res;
  while (in >> word)
    words.push_back(word);

  for (int i=0; i<words.size(); ++i) {
    string word = words[i];
    string tmp(1001, 'n');
    for (auto d: dict) {
      int lo=0;
      while (lo<d.size() && d[lo]==word[lo])
        ++lo;
      if (lo == d.size()) {
        if (d.size() < tmp.size())
          tmp = d;
      }
    }
    if (tmp.size() == 1001)
      res += word;
    else res += tmp;
    if (i < words.size()-1)
      res += ' ';
  }
  return res;
}

int main() {
  return 0;
}
