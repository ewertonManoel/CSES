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
vector<bool> visited;
int ans;

void dfs(int u, int p) {
    for(auto& v : tree[u]) {
        if(v == p) continue;
        dfs(v, u);
        if(!visited[u] && !visited[v]) {
            visited[u] = visited[v] = true;
            ans++;
        }
    }
}

int main() {
    fast_io();
    ans = 0;
    int n; cin >> n;
    tree.assign(n + 1, vector<int>());
    visited.assign(n + 1, false);
    for(int i = 0; i < n - 1; i++) {
        int a; cin >> a;
        int b; cin >> b;
        tree[a].pb(b);
        tree[b].pb(a);
    }
    dfs(1, 0);
    cout << ans << '\n';
}