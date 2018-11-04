#include<bits/stdc++.h>
using namespace std;

class MNS {
public:
  int res;
  vi nums;
  vi new_nums;
  int visit[9];
  set<ll> st;

  bool check() {
    ll bits = 0;
    fori (i, 0, 9) {
      bits <<= 4;
      bits |= new_nums[i] & 0xf;
    }

    if (st.count(bits)) {
      return false;
    }
    st.insert(bits);

    // Check row
    int sum = 0;
    fori (i, 0, 3) {
      int r = 0;
      r = new_nums[3*i + 0] + new_nums[3*i + 1] + new_nums[3*i + 2];
      if (i == 0)
        sum = r;
      else if (r != sum)
        return false;
    }

    // Check column
    fori (i, 0, 3) {
      int r = 0;
      r = new_nums[i] + new_nums[i + 3] + new_nums[i + 6];
      if (r != sum)
        return false;
    }
    return true;
  }

  void dfs(int idx) {
    if (idx == 9) {
      if (check())
        res++;
      return;
    }

    fori (i, 0, 9) {
      if (!visit[i]) {
        visit[i] = 1;
        new_nums[idx] = nums[i];
        dfs(idx+1);
        visit[i] = 0;
      }
    }
  }

  int combos(vi aa) {
    nums = aa;
    mst(visit, 0);
    new_nums.resize(9);
    res = 0;
    dfs(0);
    return res;
  }

  // int combos(vi aa) {
  //   res = 0;
  //   new_nums = aa;
  // Note: we must sort fist in order to get all permutations.
  //   sort(all(new_nums));
  //   do {
  //     if (check())
  //       res++;
  //   } while (next_permutation(all(new_nums)));

  //   return res;
  // }
};

void test(vi aa) {
  MNS go;
  int r = go.combos(aa);
  output(r);
}

int main() {
   test({1,2,3,3,2,1,2,2,2});
  test({4,4,4,4,4,4,4,4,4});
  test({1,5,1,2,5,6,2,3,2});
  return 0;
}
