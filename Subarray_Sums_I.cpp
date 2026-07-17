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
vector<int> vect;
int main() {
    fast_io();
    int n; cin >> n;
    int sum; cin >> sum;
    int count = 0;
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        vect.pb(x);
    }
    int value = 0;
    int l = 0;
    for(int r = 0; r < vect.size(); r++) {
        value += vect[r];
        while(value > sum) {
            value -= vect[l];
            l++;
        }
        if(value == sum) count++;
    }
    cout << count << '\n';
}