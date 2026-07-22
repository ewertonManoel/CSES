#include <bits/stdc++.h>

using namespace std;

using ll = long long;

#define fast_io() ios::sync_with_stdio(false); cin.tie(nullptr)
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define ff first
#define ss second

const ll MOD = 1e9 + 7;

struct Vetor {
    ll a11, a21;
    Vetor() : a11(1), a21(0) {}
    Vetor(ll a11_, ll a21_) : a11(a11_), a21(a21_) {}
};

struct Matrix {
    ll a11, a12, a21, a22;
    Matrix() : a11(1), a12(0), a21(0), a22(1) {}
    Matrix(ll a11_, ll a12_, ll a21_, ll a22_) : a11(a11_), a12(a12_), a21(a21_), a22(a22_) {}
    Matrix operator*(const Matrix& m) const {
        return Matrix(
        ((a11 * m.a11) % MOD + (a12 * m.a21) % MOD) % MOD, 
        ((a11 * m.a12) % MOD + (a12 * m.a22) % MOD) % MOD,
        ((a21 * m.a11) % MOD + (a22 * m.a21) % MOD) % MOD,
        ((a21 * m.a12) % MOD + (a22 * m.a22) % MOD) % MOD);
    }
    Matrix& operator*=(const Matrix& m) {
        *this = *this * m;
        return *this;
    }
    Vetor operator*(const Vetor& v) const {
        return Vetor(
        ((a11 * v.a11) % MOD + (a12 * v.a21) % MOD) % MOD,
        ((a21 * v.a11) % MOD + (a22 * v.a21) % MOD) % MOD);
    }
};

Matrix fast_exp(Matrix m, ll n) {
    Matrix ans;
    Matrix x = m;
    while(n > 0) {
        if(n & 1) ans *= x;
        n >>= 1;
        x *= x;
    }
    return ans;
}

int main() {
    fast_io();
    ll n; cin >> n;
    if(n == 0) cout << 0 << '\n';
    else if(n == 1) cout << 1 << '\n';
    else {
        Vetor base;
        Matrix fib(1, 1, 1, 0);
        Matrix new_matrix = fast_exp(fib, n - 1);
        Vetor fibonacci = new_matrix * base;
        cout <<  fibonacci.a11 << '\n';
    }
}