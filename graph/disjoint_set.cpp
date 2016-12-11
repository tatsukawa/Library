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

struct disjoint_set {
    int size;
    vector<int> par;
    vector<int> rank;

    UF(int n) : size(n) {
        for(int i = 0; i < n; i++) {
            par.emplace_back(i);
            rank.emplace_back(0);
        }
    }

    int find(int x) {
        if(par[x] == x) return x;
        else return par[x] = find(par[x]);
    }

    void unite(int x, int y) {
        x = find(x);
        y = find(y);
        if(x == y) return;

        if(rank[x] < rank[y]) par[x] = y;
        else {
            par[y] = x;
            if(rank[x] == rank[y]) rank[x]++;
        }
    }

    bool same(int x, int y) {
        return find(x) == find(y);
    }
};



int main() {
    ios::sync_with_stdio(false);
}

