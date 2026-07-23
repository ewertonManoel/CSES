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

vector<vector<int>> tree, up;
vector<int> depth, tin, tout;
int LOG, timer;

void dfs(int u, int p, int h) {
    depth[u] = h;
    up[u][0] = p;
    for(int j = 1; j < LOG; j++) up[u][j] = up[up[u][j - 1]][j - 1];
    tin[u] = timer++;
    for(auto& v : tree[u]) {
        if(v == p) continue;
        dfs(v, u, h + 1);
    }
    tout[u] = timer++;
}

bool isAncestor(int a, int b) {
    if(a == 0) return true;
    if(tin[a] <= tin[b] && tout[a] >= tout[b]) return true;
    return false;
}

int LCA(int a, int b) {
    if(isAncestor(a, b)) return a;
    if(isAncestor(b, a)) return b;
    for(int j = LOG - 1; j >= 0; j--) {
        if(!isAncestor(up[a][j], b)) a = up[a][j];
    }
    return up[a][0];
}

int main() {
    fast_io();
    int n; cin >> n;
    int q; cin >> q;

    timer = LOG = 0;
    while((1 << LOG) <= n) LOG++; 
    tree.assign(n + 1, vector<int>());
    up.assign(n + 1, vector<int>(LOG, 0));
    depth.assign(n + 1, 0);
    tin.assign(n + 1, 0); tout.assign(n + 1, 0);

    for(int i = 0; i < n - 1; i++) {
        int a; cin >> a;
        int b; cin >> b;
        tree[a].pb(b);
        tree[b].pb(a);
    }
    dfs(1, 0, 0);
    for(int i = 0; i < q; i++) {
        int a; cin >> a;
        int b; cin >> b;
        int ancestor = LCA(a, b);
        int distance = (depth[a] + depth[b]) - 2 * depth[ancestor];
        cout << distance << "\n";
    }
}