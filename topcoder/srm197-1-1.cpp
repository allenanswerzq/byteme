#include<bits/stdc++.h>
using namespace std;

class Node {
  public:
    int x;
    int y;
    Node(int a, int b) : x(a), y(b) {}
    // Note: the last const here
    bool operator< (const Node& b) const {
      if (x == b.x)
        return y <= b.y;
      return x <= b.x;
    }
};

class GeneralChess {
public:
  vs attackPositions(vs aa) {
    vector<vi> dirs = {{-2,-1}, {-2,1}, {-1,-2},  {-1,2},
                       {1,-2},  {1,2},  {2,-1},  {2,1} };
    vector<Node> pieces;
    fora (a, aa) {
      istringstream iss(a);
      int x, y;
      char comma;
      iss >> x >> comma >> y;
      pieces.pb(Node(x, y));
    }

    int n = sz(pieces);
    vector<Node> res;
    set<string> st;
    fori (i, 0, n) {
      fora (d, dirs) {
        Node node = pieces[i];
        int nx = node.x + d[0], ny = node.y + d[1];
        int cnt = 0;
        fori (j, 0, n)
          if ((abs(pieces[j].x - nx) == 1 && abs(pieces[j].y - ny) == 2) ||
              (abs(pieces[j].y - ny) == 1 && abs(pieces[j].x - nx) == 2)) {
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
    fora (node, res)
      ans.pb(to_string(node.x) + "," + to_string(node.y));
    return ans;
  }
};

void test(vs aa) {
  GeneralChess go;
  vs ret = go.attackPositions(aa);
  pvi(ret, 1);
}

int main() {
  GeneralChess go;
  test({"0,0"});
  test({"2,1", "-1,-2"});
  test({"0,0", "2,1"});
  test({"-1000,1000", "-999,999", "-999,997"});
  return 0;
}
