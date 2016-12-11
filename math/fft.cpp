// validation: http://atc001.contest.atcoder.jp/submissions/692183
#include <bits/stdc++.h>

#define get_variable_name(x) #x
#define debug(x) cout << #x << " = " << x << endl
#define rep(i, begin, end) for(int (i) = (begin); (i) < (end); (i)++)

#define ALL(x) (x).begin(), (x).end()
#define SORT(x) sort((x).begin(), (x).end())
#define REVERSE(x) reverse( (x).begin(),(x).end())
#define UNIQUE(x) (x).erase(unique(ALL((x))), (x).end())
#define PW(x) (1LL<<(x))

using namespace std;
using ll = int64_t;
using P = pair<int, int>;

typedef complex<double> Complex;

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
const double PI = 3.141592653589;

vector<Complex> DFT(vector<Complex> f, int n, double d) {
    if(n == 1) return f;
    
    vector<Complex> f0, f1;
    double theta = (PI * d * 2.0) / n;

    for(int i = 0; i < n / 2; i++) {
        f0.emplace_back(f[2*i+0]);
        f1.emplace_back(f[2*i+1]);
    }

    f0 = DFT(f0, n/2, d);
    f1 = DFT(f1, n/2, d);

    auto zeta = Complex(cos(theta), sin(theta));
    auto pow_zeta = Complex(1, 0);

    vector<Complex> ret;
    for(ll i = 0; i < n; i++) {
        ret.emplace_back(f0[i%(n/2)] + pow_zeta * f1[i%(n/2)]);
        pow_zeta *= zeta;
    }

    return ret;
}

vector<Complex> multiply(vector<Complex> &g, vector<Complex> &h) {
    int n = 1;
    while(n < g.size() + h.size()) { n <<= 1; }
    vector<Complex> f;

    g.resize(n);
    h.resize(n);

    g = DFT(g, n, 1.0);
    h = DFT(h, n, 1.0);

    for(int i = 0; i < n; i++) f.emplace_back(g[i] * h[i]);
    f = DFT(f, n, -1.0);

    for(int i = 0; i < n; i++) f[i] /= n;
    return f;
}

int main() {
    ll N;
    ll a, b;
    cin >> N;
    vector<Complex> A, B;
    A.emplace_back(Complex(0));
    B.emplace_back(Complex(0));
    for(int i = 0; i < N; i++) {
        cin >> a >> b;
        A.emplace_back(Complex(a));
        B.emplace_back(Complex(b));
    }
    auto f = multiply(A, B);
    for(int i = 1; i <= 2 * N; i++) cout << (int)(f[i].real() + 0.1) << endl;
}

