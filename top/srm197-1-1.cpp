#include<bits/stdc++.h>
using namespace std;

const double EPS = 1e-9;
int cmp(double x, double y = 0, double tol = EPS) {
  return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

class Node {
  public:
    int x;
    int y;
    Node(int a, int b)
      : x(a), y(b) {}
    // Note: the final const here
    bool operator< (const Node& b) const {
      if (x == b.x)
        return y <= b.y;
      return x <= b.x;
    }
};

class GeneralChess {
public:
  vs attackPositions(vs aa) {
    vector<vi> dirs = { {-2,-1},  {-2,1}, {-1,-2},  {-1,2},  
                        {1,-2},  {1,2},  {2,-1},  {2,1} };
    vector<Node> pieces;
    fora(a, aa) {
      istringstream iss(a);
      int x, y;
      char comma;
      iss >> x >> comma >> y;
      pieces.pb(Node(x, y));
    }

    int n = sz(pieces);
    vector<Node> res;
    set<string> st;
    fori(i, 0, n) {
      fora(d, dirs) {
        Node node = pieces[i];
        int nx = node.x + d[0], ny = node.y + d[1];
        int cnt = 0;
        fori(j, 0, n)
          if ((abs(pieces[j].x - nx)==1 && abs(pieces[j].y - ny)==2) ||
              (abs(pieces[j].y - ny)==1 && abs(pieces[j].x - nx)==2)) {
            ++cnt;
          }
        if (cnt == n) {
          string s = to_string(nx) + "," + to_string(ny);
          if (! st.count(s))  {
            st.insert(s);
            res.pb(Node(nx, ny));
          }
        }
      }
    }
    sort(all(res));
    vs ans;
    fora(node, res)
      ans.pb(to_string(node.x) + "," + to_string(node.y));
    return ans;
  }
};

int main(int argc, char** argv) {
  std::ios_base::sync_with_stdio(false);
  GeneralChess go;
  vs aa = {"0,0"};
  vs res = go.attackPositions(aa);
  pvi(res);

  aa = {"2,1", "-1,-2"};
  res = go.attackPositions(aa);
  pvi(res);

  aa = {"0,0", "2,1"};
  res = go.attackPositions(aa);
  pvi(res);

  aa = {"-1000,1000", "-999,999", "-999,997"};
  res = go.attackPositions(aa);
  pvi(res);

  // Node x(2, 3);
  // Node z(1, 2);
  // Node y(2, 4);
  // cout << (x < z) << '\n';
  // cout << (x < y) << '\n';
  return 0;
}
