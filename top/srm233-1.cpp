#include<bits/stdc++.h>
using namespace std;


const double EPS = 1e-9;
int cmp(double x, double y = 0, double tol = EPS) {
  return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

class QuizShow {
public:
  int wager (vector<int> scores, int wager1, int wager2)
  {
    int best, bet, odds, wage, I, J, K;
    best = 0; bet = 0;

    for (int wage = 0; wage <= scores[0]; wage++)
    {
      int odds = 0;
      for (I = -1; I <= 1; I = I + 2)
      for (J = -1; J <= 1; J = J + 2)
        for (K = -1; K <= 1; K = K + 2)
        if (scores[0] + I * wage > scores[1] + J * wager1  &&
            scores[0] + I * wage > scores[2] + K * wager2)
          { odds++; }

      if (odds > best) { 
        bet = wage; 
        best = odds;
      }
    }
    return bet;
  }
};
