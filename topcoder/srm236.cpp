#include<bits/stdc++.h>
using namespace std;

class BusinessTasks {
public:
  string getTask(vector<string>& tasks, int seed) {
    int start = 0;
    while (sz(tasks) > 1) {
      int ix = (start + seed - 1) % sz(tasks);
      cout << ix << " " << tasks[ix] << '\n';
      tasks.erase(tasks.begin() + ix);
      start = ix;
    }
    return tasks[0];
  }
};

void test(vs aa) {
  BusinessTasks go;
  auto r = go.getTask(aa);
  output(r);
}

int main() {
  test({"a", "b", "c", "d"});
  test({"a", "b", "c", "d", "e"});
  test({"a", "b"});
  return 0;
}
