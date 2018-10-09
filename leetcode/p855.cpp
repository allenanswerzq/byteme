#include<bits/stdc++.h>
using namespace std;



const double eps = 1e-9;
int dcmp(double x, double y = 0, double tol = eps) {
  return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

class ExamRoom {
public:
  ExamRoom(int N) {
    n = N; 
    num = 0;
  }
  
  int seat() {

  if (num == 0) {
    st.insert(0);
    ++num;
    return 0;
  } 

  // pvi(st);

  int max = *st.begin();
  int seat = 0;
  int last = -1;

  fora(t, st) {
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
  st.erase(p);
  --num; 
  }

private:
  set<int> st;
  int num;
  int n;
};

int main(int argc, char** argv) {
  std::ios_base::sync_with_stdio(false);
  cout.precision(10);
  cout << fixed; 

  ExamRoom go(10);
  cout << "r: " << go.seat() << "\n";
  int r = go.seat();
  cout << "r: " << r << "\n";
  r = go.seat();
  cout << "r: " << r << "\n";
  r = go.seat();
  cout << "r: " << r << "\n";
  go.leave(4);
  r = go.seat();
  cout << "r: " << r << "\n";
  return 0;
}
