// Disjoint set
// Adopted from https://gist.github.com/kodekracker/2d5b12885c59d7f73d1c

class Disjoint {
private:
  vector<int> p, rank, root;
  int set_size;

public:
  Disjoint(int n) {
    set_size = n;
    rank.assign(n, 0);
    p.assign(n, 0);
    for (int i = 0; i < n; i++) p[i] = i;
    root.assign(n, 1);
  }

  int find(int ix) {
    while (p[ix] != ix) ix = p[ix]; 
    return ix;
  }

  bool same(int i, int j) {
    return find(i) == find(j);
  }

  void joint(int i, int j) {
    if (!same(i, j)) {
      int x = find(i), y = find(j);
      if (rank[x] > rank[y]) {
        root[find(x)] += root[find(y)]; p[y] = x;
      } else {
        root[find(y)] += root[find(x)]; p[x] = y;
        if (rank[x] == rank[y]) rank[y]++;
      }
      set_size--;
    }
  }

  int set(int i) {
    return root[find(i)];
  }

  int size() {
    return set_size;
  }
};
