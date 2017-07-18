#include <bits/stdc++.h>

using namespace std;

// modify value
const int MAX_V;
const int INF;

typedef pair<int, int> P; 

struct edge
{
    int to, cap, cost, rev;
    edge(int t, int ca, int co, int re) : to(t), cap(ca), cost(co), rev(re) { }
};

int V;                          
vector<edge> G[MAX_V];          
int h[MAX_V];                   
int dist[MAX_V];                
int prevv[MAX_V], preve[MAX_V]; 

void add_edge(int from, int to, int cap, int cost)
{
    G[from].emplace_back(edge(to, cap, cost, G[to].size()));
    G[to].emplace_back(edge(from, 0, -cost, G[from].size() - 1));
}

int min_cost_flow(int s, int t, int f)
{
    int res = 0;
    fill(h, h + V, 0); 
    fill(prevv, prevv + V, -1);
    fill(preve, preve + V, -1);

    while (f > 0)
    {
        priority_queue<P, vector<P>, greater<P>> que;
        fill(dist, dist + V, INF);
        dist[s] = 0;
        que.push(P(0, s));
        while (!que.empty())
        {
            P p = que.top();
            que.pop();
            int v = p.second;
            if (dist[v] < p.first) continue;
            for (int i = 0; i < G[v].size(); i++)
            {
                edge &e = G[v][i];
                if (e.cap > 0 && dist[e.to] > dist[v] + e.cost + h[v] - h[e.to])
                {
                    dist[e.to] = dist[v] + e.cost + h[v] - h[e.to];
                    prevv[e.to] = v;
                    preve[e.to] = i;
                    que.push(P(dist[e.to], e.to));
                }
            }
        }
        if (dist[t] == INF)
        {
            return -1;
        }
        for (int v = 0; v < V; v++) h[v] += dist[v];

        int d = f;
        for (int v = t; v != s; v = prevv[v])
        {
            d = min(d, G[prevv[v]][preve[v]].cap);
        }
        f -= d;
        res += d * h[t];
        for (int v = t; v != s; v = prevv[v])
        {
            edge &e = G[prevv[v]][preve[v]];
            e.cap -= d;
            G[v][e.rev].cap += d;
        }
    }

    return res;
}
