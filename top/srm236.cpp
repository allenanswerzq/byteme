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

// int main(int argc, char** argv) {
//   std::ios_base::sync_with_stdio(false);
//   BusinessTasks go;
//   vector<string> t {"a", "b", "c", "d"};
//   cout << go.getTask(t, 2) << '\n';
//   vector<string> a {"a", "b", "c", "d", "e"};
//   cout << go.getTask(a, 3) << '\n';
//   vector<string> c {"a", "b"};
//   cout << go.getTask(c, 1000) << '\n';
//   return 0;
// }
