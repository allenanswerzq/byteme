struct dsu {
  int n;
  vector<int> e;

  dsu(int n_) : n(n_), e(n, -1) {
  }

  int size(int x) {
    return -e[find(x)];
  }

  int find(int x) {
    return e[x] < 0 ? x : e[x] = find(e[x]);
  }

  bool join(int a, int b) {
    a = find(a);
    b = find(b);
    if (a == b) {
      return false;
    }
    if (e[a] > e[b]) {
      swap(a, b);
    }
    e[a] += e[b];
    e[b] = a;
    n--;
    return true;
  }
};
