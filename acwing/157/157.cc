/* created   : 2020-06-12 17:22:52
 * accepted  : 2020-06-12 23:07:25
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
#define ll long long
#define pii pair<int, int>

deque<pii> wait_queue;
set<pii> memory;
set<pii> work;

int curr_time;

bool find_new_space(int t, int m, int p) {
  for (auto it = memory.begin(); it != memory.end(); ++it) {
    auto jt = it;
    if (++jt != memory.end()) {
      // [(it)x....y]    [(jt)x...y]
      int chunk_size = (jt->x - it->y - 1);
      if (chunk_size >= m) {
        work.insert({t + p, it->y + 1});
        memory.insert({it->y + 1, it->y + m});
        return true;
      }
    }
  }
  trace(t, m, p);
  return false;
}

// Free the memory used before time `t`.
void free_used_space(int t) {
  while (work.size() && work.begin()->x <= t) {
    int end_time = work.begin()->x;
    while (work.size() && work.begin()->x == end_time) {
      // Remove this work, and also free the memory this work used.
      int address = work.begin()->y;
      auto it = memory.lower_bound({address, 0});
      // trace(work, address, memory);
      assert(it != memory.end());
      memory.erase(it);
      work.erase(work.begin());
    }
    curr_time = end_time;
    // Try assign new memory to queued work.
    while (wait_queue.size()) {
      int need_memory = wait_queue.front().x;
      int need_time = wait_queue.front().y;
      trace(curr_time, need_memory, need_time);
      if (find_new_space(curr_time, need_memory, need_time)) {
        wait_queue.pop_front();
      }
      else {
        break;
      }
    }
  }
}

void solve() {
  int n; cin >> n;
  int t, m, p;
  memory.insert({-1, -1});
  memory.insert({n, n});
  int cnt = 0;
  while (cin >> t >> m >> p) {
    if (t == 0 && m == 0 && p == 0) break;
    free_used_space(t);
    if (!find_new_space(t, m, p)) {
      cnt++;
      wait_queue.push_back({m, p});
      trace(wait_queue);
    }
    trace(t, m, p, cnt);
  }
  free_used_space(2e9);
  cout << curr_time << "\n";
  cout << cnt << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
