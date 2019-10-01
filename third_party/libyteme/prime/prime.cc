vector<bool> sieve(int n) {
  vector<bool> primes(n + 1, 1);
  primes[0] = 0;
  primes[1] = 0;
  for (int i = 2; i <= n; i++) {
    if (primes[i]) {
      for (int j = i + i; j <= n; j += i) {
        primes[j] = 0;
      }
    }
  }
  return primes;
}

vector<int> prime_factor(int n) {
  vector<int> factors;
  for (int i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      factors.push_back(i);
      while (n % i == 0) {
        n /= i;
      }
    }
  }
  if (n > 1) {
    factors.push_back(n);
  }
  return factors;
}
