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

vector<vector<int>> tree;
int max_dist, farthest_node;

void dfs(int u, int p, int d) {
    if(d > max_dist) {
        max_dist = d;
        farthest_node = u;
    }
    for(auto& v : tree[u]) {
        if(v == p) continue;
        dfs(v, u, d + 1);
    }
}

int main() {
    fast_io();
    int n; cin >> n;
    tree.assign(n + 1, vector<int>());
    max_dist = -1;
    for(int i = 0; i < n - 1; i++) {
        int a; cin >> a;
        int b; cin >> b;
        tree[a].pb(b);
        tree[b].pb(a);
    }
    dfs(1, 0, 0); 
    max_dist = -1;
    dfs(farthest_node, 0, 0);
    cout << max_dist << '\n';
}