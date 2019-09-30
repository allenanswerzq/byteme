#include<bits/stdc++.h>
using namespace std;

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

int main() {
  return 0;
}
