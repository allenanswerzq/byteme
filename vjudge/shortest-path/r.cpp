#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define pend cout << '\n'
#define pvar(x) cout << #x << ": "
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define mst(x, y) memset(x, y, sizeof(x))
#define fora(e, c) for (auto &e : c)
#define fori(i, a, b) for (int i = (a); i < (b); ++i)
#define ford(i, a, b) for (int i = (a); i > (b); --i)
#define output(v) cout << (v) << '\n'
#define codejam(ix, v) cout << "Case #" << (ix) << ": " << (v) << '\n'
#define pvi(x, v) if (v) pvar(x); fora(a, x) cout << a << " "; pend
#define par(x, n, v) if (v) pvar(x); fori(a, 0, n) cout << x[a] << " "; pend

#define trace(...) _f(#__VA_ARGS__, __VA_ARGS__)
template <typename T>
void _f(const char* name, T&& arg) {
    cout << fixed << name << ": " << arg << '\n';
}

template <typename T, typename... Args>
void _f(const char* names, T&& arg, Args&&... args) {
    const char* split = strchr(names + 1, ',');
    cout.write(names, split - names) << ": " << arg << " |";
    _f(split, args...);
}

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<vs> vvs;
typedef pair<int, int> pii;
typedef vector<pii> vpii;

const int inf = 0x3f3f3f3f;
const int maxn = 330;
int cost[maxn][maxn];
int visit[maxn];
int dist[maxn];
int que[maxn];
int n;

void spfa(int src) {
    int front = 0, rear = 0;
    fori (v, 1, n + 1) {
        if (v == src) {
            dist[v] = inf;
            visit[v] = 0;
        } else if (cost[src][v] != inf) {
            // Find all the shortest distance from v to others.
            // Here assign the distance from src to v, assume we then find
            // the shorest distance from v to u, it equivalently says we get
            // the shortest distance from src to u, and u can be any vetices
            // even itself.
            dist[v] = cost[src][v];
            que[rear++] = v;
            visit[v] = 1;
        } else {
            // Never reach to here.
            dist[v] = inf;
            visit[v] = 0;
        }
    }

    while (front != rear) {
        int u = que[front++];
        fori (v, 1, n + 1) {
            if (dist[v] > dist[u] + cost[u][v]) {
                dist[v] = dist[u] + cost[u][v];
                if (!visit[v]) {
                    visit[v] = 1;
                    que[rear++] = v;
                    if (rear >= maxn) rear = 0;
                }
            }
        }
        visit[u] = 0;
        if (front >= maxn) front = 0;
    }
}

void solve() {
    // Must write in this way, otherwise it will become wrong answer.
    while (cin >> n) {
        fori (i, 1, n + 1) {
            fori (j, 1, n + 1) {
                cin >> cost[i][j];
            }
        }

        spfa(1);
        // Shortest path form 1 to n.
        int ret = dist[n];
        // Shortest cycle staring from 1 and ending to 1.
        int loop1 = dist[1];

        spfa(n);
        // Shortest cycle staring from n and ending to n.
        int loopn = dist[n];
        ret = min(ret, loop1 + loopn);
        output(ret);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
    return 0;
}
