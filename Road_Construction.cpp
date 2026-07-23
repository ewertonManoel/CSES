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
    DSU uf(n);
    int m; cin >> m;
    int max_size = 0;
    for(int i = 0; i < m; i++) {
        int a; cin >> a;
        int b; cin >> b;
        if(!uf.same(a, b)) {
            n--;
            uf.unite(a, b);
        }
        max_size = max(max_size, uf.sz[uf.find(a)]);
        cout << n << " " << max_size << '\n';
    }
}