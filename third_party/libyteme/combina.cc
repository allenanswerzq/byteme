struct combina {
  vector<mint> fact;
  vector<mint> fact_inv;

  combina(int n) {
    fact.resize(n + 1);
    fact_inv.resize(n + 1);
    fact[0] = 1;
    for (int i = 1; i <= n; ++i) {
      fact[i] = fact[i - 1] * i;
    }
    fact_inv[n] = fact[n].inv();
    for (int i = n - 1; i >= 0; --i) {
      fact_inv[i] = fact_inv[i + 1] * i;
    }
  }

  // Choose k from total n items without permutation
  mint nck(int n, int k) {
    return (*this)(n, k);
  }

  // Choose k from total n items with permutation
  mint npk(int n, int k) {
    // nPk = nCk * k!
    mint ret = nck(n, k);
    ret *= fact[k];
    return ret;
  }

  mint operator() (int n, int k) {
    if (k < 0 || n < k) {
      return mint(0);
    }
    return fact[n] * fact_inv[k] * fact_inv[n - k];
  }
};


struct combina {
  // c(n, k) = c(n - 1, k) + c(n - 1, k - 1);
  vector<vector<ll>> dp;
  combina(int n) {
    dp.resize(n + 1, vector<ll>(n + 1));
    for (int i = 0; i <= n; i++) {
      dp[i][0] = 1;
    }
    for (int i = 1; i <= n; i++) {
      for (int k = 1; k <= i; k++) {
        dp[i][k] = dp[i - 1][k] + dp[i - 1][k - 1];
      }
    }
  }
  // Choose k from total n items without permutation
  int operator() (int n, int k) {
    return dp[n][k];
  }
};
