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
vector<int> lps;
int main() {
    fast_io();
    string s, p; cin >> s >> p;
    int n = s.size(), m = p.size();
    lps.assign(m, 0);
    int j = 0;
    for(int i = 1; i < m; i++) {
        while(j && p[i] != p[j]) j = lps[j - 1];
        if(p[i] == p[j]) j++;
        lps[i] = j;
    }
    int count = 0;
    j = 0;
    for(int i = 0; i < n; i++) {
        while(j && s[i] != p[j]) {
            j = lps[j - 1];
        }
        if(s[i] == p[j]) j++;
        if(j == m) {
            count++;
            j = lps[j - 1];
        }
    }
    cout << count << '\n';
}