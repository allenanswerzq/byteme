#include <functional>
#include <iostream>
#include <mutex>
#include <unistd.h>
#include <vector>
using namespace std;

void LOG(string msg, bool nl = true) {
  static std::mutex mutex;
  mutex.lock();
  cerr << msg;
  if (nl) {
    cerr << endl;
  }
  mutex.unlock();
}

typedef function<void(int)> JobType;
std::mutex JobMutex;
vector<JobType> Jobs;

struct Worker {
  vector<pid_t> childs_;

  void Start(int n) {
    for (int i = 0; i < n; i++) {
      int f;
      if ((f = fork()) == 0) {
        childs_.push_back(getpid());
        while (1) {
          JobMutex.lock();
          JobType job;
          if (!Jobs.empty()) {
            job = Jobs.back();
            Jobs.pop_back();
          } else {
            return;
          }
          JobMutex.unlock();
          job(0);
        }
      }
      else {
        int status = -1;
        int w = -1;
        do {
          w = waitpid(f, &status, 0);
          if (w == -1 && errno != EINTR)
            break;
        } while (w != f);
        if (w == -1) {
          status = 1;
        }
        else if (WIFEXITED(status)) {
          status = WEXITSTATUS(status);
        }
        else if (WIFSIGNALED(status)) {
          status = WTERMSIG(status) + 128;
        }
        else {
          status = 1;
        }
      }
    }
  }
};

void Job(int idx) {
  for (int i = 0; i < 4; i++) {
    LOG(to_string(idx) + "-" + to_string(i) + " AAAA");
    sleep(1);
  }
}

int main() {
  Worker worker;
  for (int i = 0; i < 4; i++) {
    Jobs.push_back(bind(&Job, i));
  }
  worker.Start(4);
}
