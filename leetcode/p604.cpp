#include <bits/stdc++.h>
using namespace std;

class StringIterator {
public:
  StringIterator(string compressedString) {
    nextCnt = 0;
    numCurr = 0;
    numCnt = 0;
    SS = compressedString;
  }

  char next() {
    if (numCnt < numCurr) {
      numCnt++;
        return currChar;
    } else if (nextCnt < SS.size()) {
      numCnt = 0;
      currChar = SS[nextCnt];
      //cout << "C: " << SS[nextCnt] << endl;
      string t = "";
      nextCnt++;
      while (SS[nextCnt]>='0' && SS[nextCnt]<='9') {
          t += SS[nextCnt++];
      }
        numCurr = atoi(t.c_str());
        numCnt++;
        return currChar;
    } else {
      return ' ';
    }
  }

  bool hasNext() {
     //cout << numCnt << " " << numCurr << endl;
     //cout << numCnt << " " << SS.size() << endl;
     return (numCnt<numCurr || nextCnt<SS.size()-1);
  }
private:
    int nextCnt;
    int numCurr;
    int numCnt;
    string SS;
    char currChar;
};

// A very good approach
class StringIterator {
  vector<pair<char, int>> a;
  int p;
public:
  StringIterator(string s) {
    for (size_t i = 0; i < s.size(); ) {
      char c = s[i++];
      int r = 0;
      while (i < s.size() && isdigit(s[i])) r = r * 10 + s[i++] - '0';
      if (r > 0) a.emplace_back(c, r);
    }
    p = 0;
  }

  char next() {
    if (p >= a.size()) {
      return ' ';
    }
    char c = a[p].first;
    a[p].second--;
    if (a[p].second == 0) p++;
    return c;
  }

  bool hasNext() {
    return p < a.size();
  }
};

int main() {
  return 0;
}
