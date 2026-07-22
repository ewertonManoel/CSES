#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;
using tli = tuple<ll, int, int>;
using pil = pair<int, ll>;
#define fast_io() ios::sync_with_stdio(false); cin.tie(nullptr)
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define ff first
#define ss second

const int INF = 1e9;
const ll LINF = 1e18;
const int MOD = 1e9 + 7;
const double EPS = 1e-9;

vector<vector<pil>> graph;
priority_queue<tli, vector<tli>, greater<tli>> pq;
vector<vector<ll>> dist;
vector<int> prevNode;

void dijkstra(int s) {
    dist[s][0] = 0;
    pq.push({0, s, 0});
    while(!pq.empty()) {
        auto [d, u, ticket] = pq.top(); pq.pop();
        if(d != dist[u][ticket]) continue;
        for(auto& [v, w] : graph[u]) {
            ll cur_dist = d + w;
            ll cur_dist2 = d + w / 2;
            if(cur_dist < dist[v][ticket]) {
                dist[v][ticket] = cur_dist;
                pq.push({cur_dist, v, ticket});
            }
            if(!ticket && cur_dist2 < dist[v][1]) {
                dist[v][1] = cur_dist2;
                pq.push({cur_dist2, v, 1});
            }
        }
    }
}
int main() {
    fast_io();
    int n; cin >> n;
    int m; cin >> m;
    graph.assign(n + 1, vector<pil>());
    dist.assign(n + 1, vector<ll>(2, LINF));
    for(int i = 0; i < m; i++) {
        int u; cin >> u;
        int v; cin >> v;
        ll w; cin >> w;
        graph[u].pb({v, w});
    }
    dijkstra(1);
    cout << dist[n][1] << '\n';
}