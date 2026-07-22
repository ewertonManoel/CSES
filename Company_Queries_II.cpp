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
vector<int> tin;
vector<int> tout;
vector<vector<int>> up;
int timestamp;
int LOG;

void dfs(int u, int p) {
    up[u][0] = p;
    tin[u] = timestamp++;
    for(auto& v : tree[u]) {
        if(v == p) continue;
        dfs(v, u);
    }
    tout[u] = timestamp++;
}
bool isAncestor(int a, int b) {
    if(a == 0) return true;
    if(tin[a] <= tin[b] && tout[a] >= tout[b]) return true;
    return false;
}
void pre_computing() {
    for(int k = 0; k < LOG; k++) {
        up[0][k] = 0;
    }
    for(int u = 1; u < tree.size(); u++) {
        for(int k = 1; k < LOG; k++) {
            up[u][k] = up[up[u][k-1]][k - 1];
        }
    }
}

int LCA(int a, int b) {
    if(isAncestor(a, b)) return a;
    if(isAncestor(b, a)) return b;
    for(int i = LOG - 1; i >= 0; i--) {
        if(!isAncestor(up[b][i], a)) b = up[b][i];
    }
    return up[b][0];
}

int main() {
    fast_io();
    int n; cin >> n;
    int q; cin >> q;
    LOG = 0;
    while((1 << LOG) <= n) LOG++;
    tree.assign(n + 1, vector<int>());
    up.assign(n + 1, vector<int>(LOG));
    tin.assign(n + 1, 0);
    tout.assign(n + 1, 0);
    timestamp = 0;
    for(int e = 2; e <= n; e++) {
        int b; cin >> b;
        tree[e].pb(b);
        tree[b].pb(e);
    }
    dfs(1, 0);
    pre_computing();
    for(int i = 0; i < q; i++) {
        int a; cin >> a;
        int b; cin >> b;
        cout << LCA(a, b) << '\n';
    }
}