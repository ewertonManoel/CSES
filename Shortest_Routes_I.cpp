#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

#define fast_io() ios::sync_with_stdio(false); cin.tie(nullptr)
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define ff first
#define ss second

const int INF = 1e9;
const ll LINF = 1e18;
const int MOD = 1e9 + 7;
const double EPS = 1e-9;
vector<vector<pll>> graph;
priority_queue<pll, vector<pll>, greater<pll>> pq;
vector<ll> dist;

void dijkstra(int s) {
    dist[s] = 0;
    pq.push({0, s});
    while(!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if(d != dist[u]) continue;
        for(auto& [v, w] : graph[u]) {
            ll cur_dist = d + w;
            if(cur_dist < dist[v]) {
                dist[v] = cur_dist;
                pq.push({cur_dist, v});
            }
        }
    }
}

int main() {
    fast_io();
    ll n; cin >> n;
    ll m; cin >> m;
    graph.assign(n + 1, vector<pll>());
    dist.assign(n + 1, LINF);
    for(ll i = 0; i < m; i++) {
        ll u; cin >> u;
        ll v; cin >> v;
        ll w; cin >> w;
        graph[u].pb({v, w});
    }
    dijkstra(1);
    for(ll i = 1; i < n + 1; i++) {
        cout << dist[i] << " ";
    }
}