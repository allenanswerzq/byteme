#include<bits/stdc++.h>
using namespace std;



const double eps = 1e-9;
int dcmp(double x, double y = 0, double tol = eps) {
  return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

class Solution {
public:
  bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
  int a, b, c, d;
  a = rec1[0], b = rec1[2], c = rec2[0], d = rec2[2];
  int left = max(a, c);
  int right = max(min(b, d), left);
  int w = right - left; 
  a = rec1[1], b = rec1[3], c = rec2[1], d = rec2[3];
  int bottom = max(a, c);
  int up = max(min(b, d), bottom);
  int h = up - bottom; 
  // cout << h << " " << w << endl;
  return h*w != 0; 
  }
};

int main(int argc, char** argv) {
  std::ios_base::sync_with_stdio(false);

  return 0;
}
