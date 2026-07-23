#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define fast_io() ios::sync_with_stdio(false); cin.tie(nullptr)
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define ff first
#define ss second

const int INF = 1e9;
const ll LINF = 1e18;
const int MOD = 1e9 + 7;
const double EPS = 1e-9;

vector<tuple<ll, int, int>> edges;

struct DSU {
    vector<int> parent;
    vector<int> sz;
    DSU(int n) {
        sz.resize(n + 1);
        parent.resize(n + 1); 
        for(int i = 1; i <= n; i++) {
            parent[i] = i;
            sz[i] = 1;
        }
    }
    int find(int x) {
        if(parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    }

    void unite(int x, int y) {
        int root_x = find(x);
        int root_y = find(y);
        if(root_x == root_y) return;
        if(sz[root_x] < sz[root_y]) {
            swap(root_x, root_y);
        }
        parent[root_y] = root_x;
        sz[root_x] += sz[root_y];
    }

    bool same(int x, int y) {
        return (find(x) == find(y));
    }
};

int main() {
    fast_io();
    int n; cin >> n;
    int m; cin >> m;
    DSU uf(n);
    for(int i = 0; i < m; i++) {
        int a; cin >> a;
        int b; cin >> b;
        ll c; cin >> c;
        edges.pb({c, a, b});
    }
    sort(all(edges));
    ll mst_cost = 0;
    int number_edges = 0;
    for(auto& [c, a, b] : edges) {
        if(uf.same(a, b)) continue;
        uf.unite(a, b);
        mst_cost += c;
        number_edges++;
    }
    if(number_edges == n - 1) cout << mst_cost << '\n';
    else cout << "IMPOSSIBLE" << '\n';
}