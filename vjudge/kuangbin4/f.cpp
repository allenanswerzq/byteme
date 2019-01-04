#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>
using namespace std;

const int maxn = 510;
const int maxm = 10010;

int n, m, w;
int dist[maxn];
int visit[maxn];
int counters[maxn];
int head[maxn];
int k_edge;

struct Node {
    int from, to, cost, next;
} edge[maxm];

void init() {
    k_edge = 0;
    memset(head, -1, sizeof(head));
}

void add_edge(int u, int v, int cost) {
    Node e = {u, v, cost, head[u]};
    edge[k_edge] = e;
    head[u] = k_edge++;
}

bool spfa() {
    queue<int> dq;
    memset(visit, 0, sizeof(visit));
    memset(dist, 0x3f, sizeof(dist));
    memset(counters, 0, sizeof(counters));

    dist[1]=0;
    visit[1]=1;
    dq.push(1);
    counters[1]++;

    while (!dq.empty()) {
        int u = dq.front(); dq.pop();
        visit[u] = 0;
        for (int i = head[u]; i != -1; i = edge[i].next) {
            int v = edge[i].to, w = edge[i].cost;
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                if (!visit[v]) {
                    visit[v] = 1;
                    if (++counters[v] > n) {
                        return 1;
                    }
                    dq.push(v);
                }
            }
        }
    }
    return 0;
}

void solve() {
    cin >> n >> m >> w;
    init();

    for (int i = 1; i <= m; i++) {
        int s, e, t;
        cin >> s >> e >> t;
        add_edge(s, e, t);
        add_edge(e, s, t);
    }

    for (int i = 1; i <= w; i++) {
        int s, e, t;
        cin >> s >> e >> t;
        add_edge(s, e, -t);
    }

    if (spfa()) {
        cout << "YES" << '\n';
    } else {
        cout << "NO" << '\n';
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);


    int t; cin >> t >> ws;
    for (int i = 1; i <= t; ++i) {
        solve();
    }
    return 0;
}
