#include <cstdio>
#include <stdio.h> // for using printf
#include <cmath>
#include <climits>
#include <cstdlib>
#include <ctype.h> // <cctype> isalpha isdigit
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <string>   // std:string std:stoi
#include <tuple>
#include <deque>
#include <stack>
#include <sstream>  // std:istringstream
#include <queue>
#include <iterator>

using namespace std;


// Idea: get shortest path from source vertex to each vertex
// Maximum shortest path of all these path is the result we needed

using pair_t = pair<int, int>;
int networkDelayTime(vector<vector<int>>& times, int n, int s) {
    int inf=1e9, N=101;
    vector<int> dist(N, inf); // shortest distance from source s to node i
    vector<int> visit(N, 0);
    unordered_map<int, vector<pair_t>> mp;
    for (auto t : times)
        mp[t[0]].push_back(make_pair(t[1], t[2]));
    dist[s] = 0;
    queue<int> q; // bfs
    q.push(s);
    while (!q.empty()) {
        int x = q.front(); q.pop();
        for (auto e : mp[x]) {
            int y = e.first;
            int w = e.second;
            int new_dist = dist[x] + w;    // distance: source --> x --> y 
            if (new_dist < dist[y]) {       // distance: source --> y
                dist[y] = new_dist;
                q.push(y);
            }
        }
    }
    int mx = 0;
    for (int i = 1; i <= n; ++i) {
        if (dist[i] >= inf)
            return -1;
        mx = max(mx, dist[i]);
    }
    return mx;
}