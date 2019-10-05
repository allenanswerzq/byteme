/**
 *    author:  tourist
 *    created: 10.09.2017 15:04:48       
**/
#include <bits/stdc++.h>

using namespace std;

struct Treap {
  long long x, y;
  long long add_x, add_y;
  int height;

  Treap *left, *right, *parent;

  Treap (long long x, long long y, Treap* parent = 0) : x(x), y(y), parent(parent) {
    height = rand ();
    add_x = add_y = 0;
    left = right = 0;
  }

  void push () {
    if (!add_x && !add_y) {
      return;
    }
    if (left) {
      left->x += add_x;
      left->add_x += add_x;
      left->y += add_y;
      left->add_y += add_y;
    }
    if (right) {
      right->x += add_x;
      right->add_x += add_x;
      right->y += add_y;
      right->add_y += add_y;
    }
    add_x = add_y = 0;
  }

  void recalc () {
  }
};

Treap* merge ( Treap *x, Treap *y ) {
  if (!x)
    return y;
  if (!y)
    return x;
  if (x->height < y->height) {
    x->push ();
    x->right = merge (x->right, y);
    if (x->right) x->right->parent = x;
    x->recalc ();
    return x;
  } else {
    y->push ();
    y->left = merge (x, y->left);
    if (y->left) y->left->parent = y;
    y->recalc ();
    return y;
  }
}

Treap* get_left(Treap *x) {
  if (!x) {
    return x;
  }
  if (!x->left) {
    return x;
  }
  x->push();
  return get_left(x->left);
}

Treap* get_right(Treap *x) {
  if (!x) {
    return x;
  }
  if (!x->right) {
    return x;
  }
  x->push();
  return get_right(x->right);
}

Treap* remove_left(Treap *x) {
  x->push();
  if (x->left) {
    x->left = remove_left(x->left);
    return x;
  }
  if (x->right) {
    Treap* z = get_left(x->right);
    Treap* zz = new Treap(z->x, z->y);
    zz->right = remove_left(x->right);
    if (zz->right) {
      zz->right->parent = zz;
    }
    zz->parent = x->parent;
    return zz;
  }
  if (x->parent) {
    if (x->parent->left == x) {
      x->parent->left = 0;
    } else {
      x->parent->right = 0;
    }
  }
  return 0;
}

Treap* remove_right(Treap *x) {
  x->push();
  if (x->right) {
    x->right = remove_right(x->right);
    return x;
  }
  if (x->left) {
    Treap* z = get_right(x->left);
    Treap* zz = new Treap(z->x, z->y);
    zz->left = remove_right(x->left);
    if (zz->left) {
      zz->left->parent = zz;
    }
    zz->parent = x->parent;
    return zz;
  }
  if (x->parent) {
    if (x->parent->right == x) {
      x->parent->right = 0;
    } else {
      x->parent->left = 0;
    }
  }
  return 0;
}

void split(Treap* t, Treap* &l, Treap* &r, long long diff) {
  if (!t) {
    l = r = 0;
    return;
  }
  t->push();
  if (t->x - t->y >= diff) {
    split(t->left, l, t->left, diff);
    if (t->left) t->left->parent = t;
    r = t;
  } else {
    split(t->right, t->right, r, diff);
    if (t->right) t->right->parent = t;
    l = t;
  }
}

void readll(long long &v) {
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    ch = getchar();
  }
  v = 0;
  while ('0' <= ch && ch <= '9') {
    v = v * 10 + ch - '0';
    ch = getchar();
  }
}

const int N = 1234567;

pair <long long, int> e[N];

int main() {
  int n, m;
  long long C;
  scanf("%d %d", &n, &m);
  readll(C);
  int cnt = 0;
  for (int i = 0; i < 2 * n; i++) {
    readll(e[cnt].first);
    e[cnt].second = 1;
    cnt++;
  }
  for (int i = 0; i < 2 * m; i++) {
    readll(e[cnt].first);
    e[cnt].second = 2;
    cnt++;
  }
  sort(e, e + cnt);
  Treap *r = new Treap(0, 0, 0);
  int mask = 0;
  long long big_add = 0;
  for (int i = 0; i < cnt - 1; i++) {
    mask ^= e[i].second;
    if (mask == 0) {
      continue;
    }
    long long t = e[i + 1].first - e[i].first;
    if (t == 0) {
      continue;
    }
    if (mask == 1) {
      r->x += t;
      r->add_x += t;
    }
    if (mask == 2) {
      r->y += t;
      r->add_y += t;
    }
    if (mask == 3) {
      big_add += t;
      Treap *t1 = new Treap(0, 0, 0), *t2 = new Treap(0, 0, 0), *t3 = new Treap(0, 0, 0);
      split(r, t1, t2, -C);
      split(t2, t2, t3, C + 1);
      if (t1) t1->parent = 0;
      if (t2) t2->parent = 0;
      if (t3) t3->parent = 0;
      long long x3 = -C, y3 = 0;
      long long x4 = 0, y4 = -C;
      if (t1) {
        Treap *tmp = get_right(t1);
        x3 = tmp->x;
        y3 = tmp->x + C;
      }
      if (t3) {
        Treap *tmp = get_left(t3);
        x4 = tmp->y + C;
        y4 = tmp->y;
      }
      if (x3 > x4 || y3 > y4) {
        if (!t2) {
          t2 = new Treap(x3, y3);
        } else {
          Treap *tmp = get_left(t2);
          if (x3 > tmp->x || y3 > tmp->y) {
            t2 = merge(new Treap(x3, y3), t2);
          }
        }
      }
      if (x4 > x3 || y4 > y3 || (x3 == x4 && y3 == y4)) {
        if (!t2) {
          t2 = new Treap(x4, y4);
        } else {
          Treap *tmp = get_right(t2);
          if (x4 > tmp->x || y4 > tmp->y) {
            t2 = merge(t2, new Treap(x4, y4));
          }
        }
      }
      t2->x += t;
      t2->add_x += t;
      t2->y += t;
      t2->add_y += t;
      Treap *t2l = get_left(t2);
      Treap *t2r = get_right(t2);
      while (t1) {
        Treap *tmp = get_right(t1);
        if (tmp->x <= t2l->x && tmp->y <= t2l->y) {
          t1 = remove_right(t1);
        } else {
          break;
        }
      }
      while (t3) {
        Treap *tmp = get_left(t3);
        if (tmp->x <= t2r->x && tmp->y <= t2r->y) {
          t3 = remove_left(t3);
        } else {
          break;
        }
      }
      r = merge(t1, merge(t2, t3));
    }
  }
  cout << (big_add + (get_right(r))->x) << endl;
  return 0;
}
