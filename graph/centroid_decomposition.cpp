#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using P = std::pair<int, int>;

const int INF = 1e8;

const int MAX_N = 1e5;

struct edge { int to, length; };

int N, K;
vector<edge> G[MAX_N];

// その頂点が既に分割に用いられているか
bool centroid[MAX_N];
// その頂点を根とする部分木のサイズ
int subtree_size[MAX_N];

// 部分木のサイズ
int compute_subtree_size(int v, int p) {
    int c = 1;
    for(int i = 0; i < G[v].size(); i++) {
        int w = G[v][i].to;
        if(w == p || centroid[w]) continue;
        c += compute_subtree_size(G[v][i].to, v);
    }
    subtree_size[v] = c;
    return c;
}

// 重心となる頂点を探す
// return: (最大部分木の頂点数, 頂点番号)
pair<int, int> search_centroid(int v, int p, int t) {
    pair<int, int> res = make_pair(INT_MAX, -1);
    int s = 1, m = 0;
    for(int i = 0; i < G[v].size(); i++) {
        int w = G[v][i].to;
        if(w == p || centroid[w]) continue;
        res = min(res, search_centroid(w, v, t));
        m = max(m, subtree_size[w]);
        s += subtree_size[w];
    }

    m = max(m, t - s);
    res = min(res, make_pair(m, v));
    return res;
}

// 部分木に含まれる全頂点の重心までの距離を列挙
void enumerate_paths(int v, int p, int d, vector<int> &ds) {
    ds.emplace_back(d);
    for(int i = 0; i < G[v].size(); i++) {
        int w = G[v][i].to;
        if(w == p || centroid[w]) continue;
        enumerate_paths(w, v, d + G[v][i].length, ds);
    }
}

// 和がK以下となる組の数を求める
int count_pairs(vector<int> &ds) {
    int res = 0;
    sort(ds.begin(), ds.end());
    int j = ds.size();
    for(int i = 0; i < ds.size(); i++) {
        while(j > 0 and ds[i] + ds[j-1] > K) --j;
        res += j - (j > i ? 1 : 0);
    }
    return res / 2;
}

// 頂点vが属する部分木に関して、重心を探し、木を分割し問題を解く
void solve_subproblem(int v) {
    // 重心となる頂点sを探す
    compute_subtree_size(v, -1);
    int s = search_centroid(v, 1, subtree_size[v]).second;
    centroid[s] = true;

    // TODO:
}

int main() {
    ios::sync_with_stdio(false);
}

