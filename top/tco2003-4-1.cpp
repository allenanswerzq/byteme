#include<bits/stdc++.h>
using namespace std;

// Still not work, dont want to waste too much time on this problem now.
class AvoidRoads {
public:
  ll grid[120][120];
  ll dp[120][120];
  ll numWays(int height, int width, vs bad) {
    mst2(grid, 120, 120, 0);
    mst2(dp, 120, 120, 0);
    ++height;
    ++width;
    int w = 1;
    fora(s, bad) {
      istringstream iss(s);
      int a, b, c, d;
      iss >> a >> b >> c >> d;
      if (grid[a][b] && !grid[c][d]) {
        grid[c][d] = grid[a][b]; 
      } else if (grid[c][d] && !grid[a][b]) {
        grid[a][b] = grid[c][d];
      } else if (grid[a][b] && grid[c][d] && grid[a][b] != grid[c][d]) {
        int t = grid[a][b];
        int old = grid[c][d];
        vector<vi> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0,1}};
        grid[c][d] = t;

        deque<pii> Q;
        Q.pb(pii(c, d));
        while (!Q.empty()) {
          int x = Q.front().fi, y = Q.front().se; Q.pf();
          // cout << x << " " << y << "\n";
          fora(dir, dirs) {
            int nx = x+dir[0], ny=y+dir[1];
            if (0<=nx && nx<=height && 0<=ny && ny<=width && grid[nx][ny]==old) {
              grid[nx][ny] = t;
              Q.pb(pii(nx, ny));
            }
          }
        }
      } else if (grid[a][b] && grid[c][d] && grid[a][b] == grid[c][d]) {

      } else {
        // cout << "w: " << w << "\n";
        grid[a][b] = w;
        grid[c][d] = w;
        w++;
      }
    }

    // fori(i, 0, height+2) {
    //   printf("%02d: ", i);
    //   fori(j, 0, width+2)
    //     printf("%02lld ", grid[i][j]);
    //   cout << '\n';
    // }
    // cout << "----------\n";
    dp[0][0] = 1;
    fori(i, 0, height) {
      fori(j, 0, width) {

          if (i > 0) {
            if (grid[i-1][j] && grid[i][j] && grid[i-1][j] == grid[i][j]) {
              dp[i][j] += 0;
            } else {
              dp[i][j] += dp[i-1][j];
            }
          }

          if (j > 0) {
            if (grid[i][j-1] && grid[i][j] && grid[i][j-1] == grid[i][j]) {
              dp[i][j] += 0;
            } else {
              dp[i][j] += dp[i][j-1];
            }
          }
      }
    }
    // fori(i, 0, 28) {
    //   fori(j, 0, 28)
    //     cout << dp[i][j] << " ";
    //   cout << '\n';
    // }
    // cout << "----------\n";
    return dp[height-1][width-1];
  }
};

// class AvoidRoads
// {
// public:
//   ll dp[100+10][100+10];
//   ll numWays(int height, int width, vs bad) {
//     ++height, ++width;

//     mst2(dp, 110, 110, 0);

//     set<string> st;
//     fora(s, bad) st.insert(s);

//     fori(i, 0, height)
//       fori(j, 0, width) {
//         if (i==0 && j==0) {
//           dp[i][j] = 1;
//           continue;
//         }

//         if (i > 0) {
//           string bad_one = to_string(i-1) + " " + to_string(j) +  " " + 
//                            to_string(i) + " " +  to_string(j);
//           string bad_two = to_string(i) + " " + to_string(j) +  " " + 
//                            to_string(i-1) + " " +  to_string(j);
//           if (!st.count(bad_one) && !st.count(bad_two))
//             dp[i][j] += dp[i-1][j];
//         }

//         if (j > 0) {
//           string bad_one = to_string(i) + " " + to_string(j-1) +  " " + 
//                            to_string(i) + " " +  to_string(j);
//           string bad_two = to_string(i) + " " + to_string(j) +  " " + 
//                            to_string(i) + " " +  to_string(j-1);
//           if (!st.count(bad_one) && !st.count(bad_two))
//             dp[i][j] += dp[i][j-1];
//         }
//       }
//     return dp[height-1][width-1];
//   }
// };

int main(int argc, char** argv) {
  std::ios_base::sync_with_stdio(false);
  AvoidRoads go;
  vs aa = {"0 0 0 1","6 6 5 6"};
  // cout << go.numWays(6, 6, aa) << '\n';
  aa = {"18 24 18 23", "24 19 24 18", "22 10 22 11", "9 24 9 23", "9 20 10 20", 
 "11 2 12 2", "16 1 16 2", "15 7 14 7", "1 3 0 3", "7 22 6 22", "22 2 23 2", 
 "15 6 15 7", "1 16 0 16", "0 2 1 2", "6 19 6 18", "1 23 0 23", "19 2 18 2", 
 "24 1 24 2", "9 3 9 2", "24 24 24 23", "4 17 4 18", "11 3 11 2", "12 1 13 1",
 "13 1 14 1", "14 1 15 1", "15 1 16 1",
 "12 5 12 6", "11 11 11 10", "20 3 20 2", "10 20 9 20", "19 5 20 5", 
 "17 10 16 10", "23 10 22 10", "18 19 18 18", "12 2 12 1", "15 20 15 21", 
 "6 15 6 16", "8 6 8 5", "11 17 11 18", "0 22 1 22", "5 9 6 9", "5 24 4 24", 
 "13 24 14 24", "16 20 16 19", "2 24 2 23", "4 17 5 17", "2 13 2 12", 
 "3 10 2 10", "18 9 19 9", "18 0 18 1", "9 5 9 4", "21 6 20 6", "11 9 10 9"};

// Expected:
// 5567661664485

// Received:
// 5568282027709

  aa = {"0 0 0 1", "0 0 1 0", "0 1 0 0"};
  cout << go.numWays(24, 24, aa) << '\n';
  // aa = {};
  // cout << go.numWays(1, 1, aa) << '\n';
  // aa = {};
  // cout << go.numWays(35, 31, aa) << '\n';
  // aa = {"0 0 1 0", "1 2 2 2", "1 1 2 1"};
  // cout << go.numWays(2, 2, aa) << '\n';
  // aa = {"1 2 2 2", "1 1 2 1"};
  // cout << go.numWays(2, 2, aa) << '\n';
  // aa = {"5 17 6 17", "13 21 13 20", "8 3 9 3", "7 1 7 2", "15 19 16 19", "24 22 23 22", "16 3 16 4", "21 9 20 9", "21 22 21 21", "18 15 18 16", "24 1 24 2", "11 5 10 5", "21 13 21 14", "2 18 1 18", "13 19 12 19", "20 18 20 19", "13 15 12 15", "15 21 16 21", "15 3 15 2", "18 18 18 19", "21 4 21 5", "5 4 5 3", "10 17 10 16", "19 3 20 3", "16 4 15 4", "3 19 2 19", "16 21 16 20", "21 1 21 0", "10 6 10 5", "15 2 16 2", "23 5 22 5", "16 17 15 17", "7 9 8 9", "22 18 23 18", "3 18 4 18", "6 10 7 10", "14 14 15 14", "1 6 0 6", "5 12 4 12", "11 15 11 14", "19 9 18 9", "9 18 9 19", "21 17 22 17", "14 19 13 19", "23 22 23 21", "21 13 21 12", "9 24 10 24", "19 19 19 20", "22 6 22 7", "18 7 19 7"};
  // cout << go.numWays(24, 24, aa) << '\n';
  return 0;
}
