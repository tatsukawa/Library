#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using P = std::pair<int, int>;


template<class T>
T gcd(const T& a, const T& b){
    return __gcd(a,b);
}

template<class T>
T lcm(const T& a, const T& b){
    return a*b/__gcd(a,b);
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

