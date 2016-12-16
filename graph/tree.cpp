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

const int MAX = 1e5;

vector<int> G[MAX];
vector<int> a;
vector<int> euler_tour;
// search(sample)
int dfs(int v, int p) {
    int res = a[v];
    euler_tour.emplace_back(v);
    for(auto u: G[v]) {
        if(u == p) continue;
        res = max(res, dfs(u, v));
    }
    euler_tour.emplace_back(v);
    return res;
}

int main() {
    ios::sync_with_stdio(false);
}

