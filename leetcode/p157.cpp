#include <bits/stdc++.h>
using namespace std;

// The API: int read4(char *buf) reads 4 characters at a time from a file.
// The return value is the actual number of characters read. 
// For example, it returns 3 if there is only 3 characters left in the file.
// By using the read4 API, implement the function int read(char *buf, int n) 
// that reads n characters from the file.
// Note:
// The read function will only be called once for each test case.

int read4(char *buf);

class Solution {
public:
  int read(char *buf, int n) {
    bool eof = 0;
    int total = 0;
    char tmp[4];
    while (!eof && total < n) {
      int cnt = read4(tmp);
      eof = cnt < 4;
      cnt = min(cnt, n - total);
      fori (i, 0, cnt)
        buf[total++] = tmp[i];
    }
    return total;
  }
};

int main() {
  return 0;
}
