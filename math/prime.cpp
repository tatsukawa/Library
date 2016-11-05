#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using P = std::pair<int, int>;

const int INF = 1e8;

const int MAX = 1e8;

vector<int> prime;
bool is_prime[MAX];

void create_prime() {
    fill(is_prime, is_prime+MAX, true);
    is_prime[0] = is_prime[1] = false;
    for(int i = 2; i*i < MAX; i++) {
        if(!is_prime[i]) {
            continue;
        }
        prime.emplace_back(i);
        for(int j = i*2; j < MAX; j += i) {
            is_prime[j] = false;
        }
    }
}

vector<int> factor(int x) {
    vector<int> ret;
    for(int i = 2; i * i < x; i++) {
        while(x % i == 0) {
            ret.emplace_back(i);
            x /= i;
        }
    }
    if(x > 1) ret.emplace_back(x);
    return ret;
}

int main() {
    ios::sync_with_stdio(false);

}

