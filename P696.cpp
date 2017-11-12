
int countBinarySubstrings(string s) {
  int cnt = 0;
  int a, b;
  int i = 0;
  while (i < s.size()) {
    char c = s[i];
    a = 0;
    while(i<s.size() && s[i] == c) {
      a++; i++;
    }
    cnt += min(a, b);
    if (i == s.size()) return cnt;

    c = s[i];
    b = 0;
    while(i<s.size() && s[i] == c) {
      b++; i++;
    }
  }
  return cnt;
}

int countBinarySubstrings(string s) {
  int cnt = 0;
  char c = s[0];
  int last=0, cur=0;

  for (int i=0; i<s.size(); ++i) {
    if (s[i] == c) {
      cur++;
    } else {
      cnt += min(last, cur);
      last = cur;
      cur = 1;
      c = s[i];
    }
  }
  cnt += min(last, cur);
  return cnt;
}
