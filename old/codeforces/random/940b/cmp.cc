#include <bits/stdc++.h>

#define ll long long
#define pb push_back
#define F first
#define S second

using namespace std;

const int N = 100005;

int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n, k, a, b;
    cin >> n >> k >> a >> b;
    ll res = 0;
    if (k == 1) {
        cout << 1LL * (n - 1) * a << endl;
        return 0;
    }
    while(n != 1) {
        if (n < k) {
            res += 1LL * (n - 1) * a;
            break;
        }
        res += 1LL * (n % k) * a;
        n -= n % k;
        res += min(1LL * b, 1LL * a * (n - n / k));
        n /= k;
    }
    cout << res << endl;
    return 0;
}
