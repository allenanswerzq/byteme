#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define pii pair<int, int>
#define vpii vector<pii>
#define sz(x) (int)(x).size()
#define fora(x, y) for(auto &x : y)
#define fori(i, a, b) for(int i=(a); i<(b); ++i)

// TODO
class Edge {
public:
  int x;
  int h;
  bool start;
  Edge (int x, int h, bool start)
    : x(x), h(h), start(start) {}
};

bool cmp(Edge a, Edge b) {
  // Put the small x first.
  if (a.x != b.x) 
    return a.x < b.x;
  // If two edges are all starting edges.
  // Put the taller height first.
  if (a.start && b.start)
    return a.h > b.h;
  // If two edges are all ending edges.
  // Put the small height first.
  if (!a.start && !b.start)
    return a.h < b.h;
  // Otherwise put the starting egde first.
  return a.start ? 1 : 0;
}

class Solution {
public:
  vector<pair<int, int>> getSkyline(vvi& aa) {
    vpii res; 
    vector<Edge> edges;
    // Note: use multiset as a min heap.
    multiset<int> pq; 
    int n;
    n = sz(aa);
    if (n <= 0) return res;

    fora (a, aa) {
      edges.pb(Edge(a[0], a[2], 1)); // (left, height)
      edges.pb(Edge(a[1], a[2], 0)); // (right, height)
    }

    // Sorting.
    sort(all(edges), cmp);

    fora (edge, edges) {
      if (edge.start) {
        // If i am standing the starting point, and i am the largest one.
        if (pq.empty() || edge.h > *pq.rbegin())
          res.eb(edge.x, edge.h);
        pq.insert(edge.h); 
      } else {
        pq.erase(pq.find(edge.h)); 
        if (pq.empty())
          res.eb(edge.x, 0);
        // There is a drop.
        else if (edge.h > *pq.rbegin())
          res.eb(edge.x, *pq.rbegin());
      }
    }
    return res;
  }
};

void test(vvi aa) {
  Solution go;
  vpii res = go.getSkyline(aa);
  fora (r, res) {
    cout << r.fi << " " << r.se << "\n";
  }
}

int main() {
   test({{2,9,10}, {3,7,15}, {5,12,12}, {15,20,10}, {19,24,8}});
  test({{0,2,3}, {2,5,3}});
  return 0;
}
