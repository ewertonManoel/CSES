#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define fast_io() ios::sync_with_stdio(false); cin.tie(nullptr)
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define ff first
#define ss second

int INF = 1e9;
const ll LINF = 1e18;
const ll MOD = 1e9 + 7;
const double EPS = 1e-9;
vector<ll> vect;

bool check(ll mid, ll k) {
    ll sum = 0;
    ll parts = 1;
    for(ll val : vect) {
        if(sum + val > mid) {
            parts++;
            sum = 0;
        }
        sum += val;
    }
    return parts <= k;
}

int main() {
    fast_io();
    ll n; cin >> n;
    ll k; cin >> k;
    for(ll i = 0; i < n; i++) {
        ll x; cin >> x;
        vect.pb(x);
    }
    ll low = 0;
    ll high = 0;
    for(ll val : vect) {
        low = max(low, val);
        high += val;
    }
    ll ans = 1;
    ll l = low; ll r = high;
    while(l <= r) {
        ll mid = l + (r - l) / 2;
        if(check(mid, k)) {
            ans = mid;
            r = mid - 1;
        }
        else l = mid + 1;
    }
    cout << ans << '\n';
}