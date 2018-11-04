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

// Max-heap `small` has the smaller half of the numbers.
// Min-heap `large` has the larger half of the numbers.
class MedianFinder {
public:
  /** initialize your data structure here. */
  MedianFinder() {
    
  }
  
  void addNum(int num) {
    samll.push(num);       
    // Push the current maximum value into the large heap.
    large.push(-small.top());
    small.pop();
    if (small.size() < large.size()) {
      small.push(-large.top());
      large.pop();
    }
  }
  
  double findMedian() {
    return samll.size() > large.size()
           ? small.top()
           : (small.top() - large.top()) / 2.0; 
  }

private:
  priority_queue<ll> small, large;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */

int main() {
  return 0;
}
