#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool isRectangleOverlap(vector<int>& r1, vector<int>& r2) {
    int a, b, c, d;
    a = r1[0], b = r1[2], c = r2[0], d = r2[2];
    int left = max(a, c);
    int right = max(min(b, d), left);
    int w = right - left; 
    a = r1[1], b = r1[3], c = r2[1], d = r2[3];
    int bottom = max(a, c);
    int up = max(min(b, d), bottom);
    int h = up - bottom; 
    // cout << h << " " << w << endl;
    return h * w != 0; 
  }
};

int main() {
  return 0;
}
