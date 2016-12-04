#include <bits/stdc++.h>
#include <cassert>

#define get_variable_name(x) #x
#define debug(x) cout << #x << " = " << x << endl

#define ALL(x) (x).begin(), (x).end()
#define SORT(x) sort((x).begin(), (x).end())
#define REVERSE(x) reverse( (x).begin(),(x).end())
#define UNIQUE(x) (x).erase(unique(ALL((x))), (x).end())
#define PW(x) (1LL<<(x))

using namespace std;
using ll = int64_t;
using P = pair<int, int>;

template<class T,class U>
ostream& operator<<(ostream &os, const pair<T, U> &p) {
    os << get_variable_name(p) << " = (" << p.first <<", " << p.second << ")";
    return os;
}

template<class T>
ostream& operator <<(ostream& os, const vector<T> &v){
    cout << get_variable_name(v) << " = [";
    for(auto i : v) 
        os << " " << i;
    os << " ]";
    return os;
}


const int INF = 1e8;

template<typename T>
T xpow(T x, T n, T M) {
    T ret = 1;
    T val = x;
    for(; n != 0; n >>= 1) {
        if(n & 1) {
            ret *= val;
            ret %= M;
        }
        val *= val;
        val %= M;
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(false);

    // usage
    ll x = 5, n = 10, M = 1e9+7;
    assert(xpow(x, n, M) == 9765625);
    cout << "passed test" << endl;
}

