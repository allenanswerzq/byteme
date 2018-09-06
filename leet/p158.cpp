#include<bits/stdc++.h>
using namespace std;

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

// The API: int read4(char *buf) reads 4 characters at a time from a file.
// The return value is the actual number of characters read. For example, 
// it returns 3 if there is only 3 characters left in the file.
// By using the read4 API, implement the function int read(char *buf, int n) 
// that reads n characters from the file.
// Note:
// The read function may be called multiple times.""

// #define LOCAL_FILE

class Solution {
public:
  int read(char *buf, int n) {
    int total = 0;
    while (total < n && sz(dq)) {
      buf[total++] = dq.front();
    } 

    char tmp[4];
    bool eof = false;
    while (!eof && total < n) {
      int cnt = read4(tmp);
      eof = cnt < 4;
      cnt = min(cnt, n - total);
      fori (i, 0, cnt) 
        buf[total++] = tmp[i];

      fori (i, cnt, 4)
        dq.push_back(tmp[i]); 
    } 
    return total;
  }
private:
  deque<char> dq;
};

int main(int argc, char** argv) {
  return 0;
}
