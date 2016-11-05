#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using P = std::pair<int, int>;

ll gcd(ll a, ll b) {
    if(a < b) {
        swap(a, b);
    }

    ll ret;

    while(true) {
        ret = a % b;
        if(ret == 0) {
            break;
        }
        a = b;
        b = ret;
    }

    return b;
}

// TODO:
// ax + by = gcd(a, b)
pair<ll, ll> ext_euclid(ll a, ll b) {
    pair<ll, ll> ret = {1, 1};

    return ret;
}

int main() {
    ios::sync_with_stdio(false);

    int a, b;
    while(cin >> a >> b) {
        cout << gcd(a, b) << endl;
    }
}

