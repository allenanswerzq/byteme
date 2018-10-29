#include<bits/stdc++.h>
using namespace std;


int n, K, x, y, C, D, E1, E2, F;
int A[N], B[N];
int mat[N][N];
long long sum[N][N];
priority_queue<long long, vector<long long>, greater<long long>> pq;

long long getSum(int a, int b, int c, int d) {
  return sum[c][d] - sum[a - 1][d] - sum[c][b - 1] + sum[a - 1][b - 1];
}

int main() {
  int ncas;
  scanf("%d", &ncas);
  for (int tcas = 1; tcas <= ncas; tcas++) {
    scanf("%d %d %d %d %d %d %d %d %d", &n, &K, &x, &y, &C, &D, &E1, &E2, &F);
    int r = 0;
    int s = 0;
    for (int i = 1; i <= n; i++) {
      A[i] = (r & 1)? -x: x;
      B[i] = (s & 1)? -y: y;
      int temp_x = (C * x + D * y + E1) % F;
      y = (D * x + C * y + E2) % F;
      x = temp_x;
      int temp_r = (C * r + D * s + E1) % 2;
      s = (D * r + C * s + E2) % 2;
      r = temp_r;
    }
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        mat[i][j] = A[i] * B[j];
        // printf("%d ", mat[i][j]);
      }
      // puts("");
    }
    // for (int i = 1; i <= n; i++) {
    //   for (int j = 1; j <= n; j++) {
    //     mat[i][j] = A[i] * B[j];
    //     cout << mat[i][j] << " ";
    //   }
    //   cout << endl;
    // }

    memset(sum, 0, sizeof(sum));
    while (!pq.empty()) pq.pop();
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + mat[i][j];
      }
    }
    int cnt = 0;
    for (int a = 1; a <= n; a++) {
      for (int b = 1; b <= n; b++) {
        for (int c = a; c <= n; c++) {
          for (int d = b; d <= n; d++) {
            long long curr_sum = getSum(a, b, c, d);
            if (cnt < K) {
              pq.push(curr_sum);
              cnt++;
            } else {
              if (pq.top() < curr_sum) {
                pq.pop();
                pq.push(curr_sum);
              }
            }
          }
        }
      }
    }
    printf("Case #%d: %lld\n", tcas, pq.top());
  }
  return 0;
}
