#include<bits/stdc++.h>
using namespace std;

class ExamRoom {
public:
  ExamRoom(int N) {
    n = N;
    num = 0;
  }

  int seat() {
    if (num == 0) {
      st.insert(0); ++num;
      return 0;
    }

    int max = *st.begin();
    int seat = 0;
    int last = -1;

    fora (t, st) {
      if (last > -1) {
        int diff = t - last;
        if (diff / 2 > max) {
          max = diff / 2;
          seat = last + max;
        }
      }
      last = t;
    }

    if (n - 1 - *st.rbegin() > max) {
      seat = n - 1;
      max = n - 1 - *st.rbegin();
    }

    st.insert(seat);
    ++num;
    return seat;
  }

  void leave(int p) {
    st.erase(p); --num;
  }

private:
  set<int> st;
  int num;
  int n;
};

int main() {
  return 0;
}
