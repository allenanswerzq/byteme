#include<bits/stdc++.h>
using namespace std;




const double eps = 1e-9;
int dcmp(double x, double y = 0, double tol = eps) {
  return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

class Node {
public:
  int city;
  int price;
  int stops;
  Node(int city, int price, int stops)
  : city(city),
    price(price),
    stops(stops) {}
};

int findCheapestPricePQ(int n, vvi& aa, int src, int dst, int k) {
  unordered_map<int, vpii> g;
  fora (a, aa) {
  int s, d, p;
  s = a[0]; d = a[1]; p = a[2];
  g[s].pb({d, p});
  } 
  auto cmp = [](Node a, Node b) { return a.price > b.price; };
  priority_queue<Node, vector<Node>, decltype(cmp)> pq(cmp);
  pq.push(Node(src, 0, k + 1));
  while (sz(pq)) {
  auto top = pq.top(); pq.pop();
  int price, city, stops;
  city = top.city; stops = top.stops, price = top.price;
  if (city == dst) return price;
  if (stops) {
    vpii nxt = g[city];
    fora (n, nxt)
    pq.push(Node(n.fi, price + n.se, stops - 1));
  }
  }
  return -1;
}

int findCheapestPriceBFS(int n, vvi& aa, int src, int dst, int k) {
}

class Solution {
public:
  int findCheapestPrice(int n, vvi& aa, int s, int d, int k) {
  // return findCheapestPricePQ(n, aa, s, d, k); 
  return findCheapestPriceBFS(n, aa, s, d, k);
  }
};

void test(int n, vvi aa, int s, int d, int k) {
  Solution go;
  int r = go.findCheapestPrice(n, aa, s, d, k);
  cerr(r);    
}

int main(int argc, char** argv) {
  std::ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.precision(10);
  cout << fixed; 
  // test(3, {{0,1,100}, {1,2,100}, {0,2,500}}, 0, 2, 1);
  // test(3, {{0,1,100}, {1,2,100}, {0,2,500}}, 0, 2, 0);
  test(4, {{0,1,1}, {0,2,5}, {1,2,1}, {2,3,1}}, 0, 3, 1);
  return 0;
}
