#include <bits/stdc++.h>

#define get_variable_name(x) #x
#define debug(x) cout << #x << " = " << x << endl

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
    for(auto i : v) {
        os << " " << v[i];
    }
    os << " ]";
    return os;
}


const int INF = 1e8;

int main() {
    ios::sync_with_stdio(false);
    P a = P(2, 5);
    vector<int> v = {1, 5, 3, 5};
    cout << a << endl;
    cout << v << endl;
}

