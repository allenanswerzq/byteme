#include<bits/stdc++.h>
using namespace std;


const double EPS = 1e-9;
int cmp(double x, double y = 0, double tol = EPS) {
  return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

int jran;
int random(int jlo, int jhi) {
  int im=6075, ia=106, ic=1283;
  jran = (jran * ia + ic) % im;
  int j = jlo + ((jhi - jlo + 1) * jran) / im;
  return j;
}

// Randomly choose numbers not follow any well known distribution.
int random_rand5() {
  int r = 1 + (int) (5.0 * rand() / (RAND_MAX + 1.0));
  return r;
}

int uniform_rand5() {
  int r = random(1, 7);
  while (r > 5)
    r = random(1, 7);
  return r;
}

// int uniform_rand5() {
//   int r = random(1, 10);
//   if (r > 6) {
//     // Do something
//   }
//   return r;
// }

// int main(int argc, char** argv) {
//   std::ios_base::sync_with_stdio(false);
//   return 0;
// }


int main(int, char*[]) {
    const int range_from  = 0;
    const int range_to    = 10;
    std::random_device                  rand_dev;
    std::mt19937                        generator(rand_dev);
    std::uniform_int_distribution<int>  distr(range_from, range_to);
 
    for (int i = 0; i < 10; ++i)
        std::cout << distr(generator) << '\n';
}
