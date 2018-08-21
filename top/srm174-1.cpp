#include<bits/stdc++.h>
using namespace std;


const double EPS = 1e-9;
int cmp(double x, double y = 0, double tol = EPS) {
  return (x <= y + tol) ? ((x + tol < y) ? -1 : 0) : 1;
}

class BirthdayOdds {
public:
  int minPeople(int minOdds, int days) {
    int num = 1;
    double ans = 1;
    // Odds of at least two people have same birthday.
    double p = minOdds / 100.0;
    // If condition not fullfill, keep add new person.
    while (cmp(1 - ans, p) == -1) {
      ans *= (days-num) * 1.0 / days;
      ++num;
    }
    return num;
  }
};

// int main(int argc, char** argv) {
//   std::ios_base::sync_with_stdio(false);
//   BirthayOdds bi;
//   int a, b;
//   while (cin >> a >> b) {
//     cout << bi.minPeople(a, b) << '\n';
//   }
//   return 0;
// }
