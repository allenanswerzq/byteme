/* created   : 2020-09-29 22:08:52
 * accepted  : 2020-09-29 22:33:35
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define ll long long

// Description
// The API: int read4(char *buf) reads 4 characters at a time from a file.

// The return value is the actual number of characters read. For example, it
// returns 3 if there is only 3 characters left in the file.

// By using the read4 API, implement the function int read(char *buf, int n)
// that reads n characters from the file.

// The read function may be called multiple times.

// Have you met this question in a real interview?
// Example
// Example 1

// Input:
// "filetestbuffer"
// read(6)
// read(5)
// read(4)
// read(3)
// read(2)
// read(1)
// read(10)
// Output:
// 6, buf = "filete"
// 5, buf = "stbuf"
// 3, buf = "fer"
// 0, buf = ""
// 0, buf = ""
// 0, buf = ""
// 0, buf = ""
// Example 2

// Input:
// "abcdef"
// read(1)
// read(5)
// Output:
// 1, buf = "a"
// 5, buf = "bcdef"

// Forward declaration of the read4 API.
int read4(char *buf) {
  string s = "filetestbuffer";
  static int i = 0;
  if (i >= (int) s.size()) return 0;
  string t = s.substr(i, min((int) s.size() - i, 4));
  i += 4;
  int n = t.size();
  memcpy(buf, t.data(), n);
  return t.size();
}

class Solution {
 public:
  /**
   * @param buf destination buffer
   * @param n maximum number of characters to read
   * @return the number of characters read
   */
  int read(char *dst, int n) {
    if (n == 0) {
      dst = nullptr;
      return 0;
    }
    int size = 0;
    if (saved_cnt > 0) {
      int d = min(saved_cnt, n);
      assert(head >= 0);
      memcpy(dst, buff + head, d);
      head += d;
      saved_cnt -= d;
      if (d == n) {
        return d;
      }
      else if (eof) {
        return d;
      }
      else {
        head = -1;
        saved_cnt = 0;
        size += d;
      }
    }
    while (!eof && size < n) {
      char tmp[4];
      int t = read4(tmp);
      if (t == 0) {
        eof = true;
        break;
      }
      int need = min(n - size, t);
      memcpy(dst + size, tmp, need);
      size += need;
      trace(need, size);
      if (need < t) {
        int rest = t - need;
        memcpy(buff, tmp + need, rest);
        saved_cnt = rest;
        head = 0;
      }
    }
    return size;
  }
 private:
  char buff[4];
  bool eof = false;
  int head = -1;
  int saved_cnt = 0;
};

#define EXPECT_TRUE(a) assert(a)
#define EXPECT_FALSE(a) assert(!a)
#define EXPECT(a, b) assert(a == b)

void solve() {
  Solution sol;
  char* dst = (char*) malloc(6);
  EXPECT(sol.read(dst, 6), 6);
  EXPECT(sol.read(dst, 5), 5);
  EXPECT(sol.read(dst, 4), 3);
  free(dst);
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
