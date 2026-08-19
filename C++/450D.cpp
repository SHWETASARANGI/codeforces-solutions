#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const long long INF = 1e18;

struct Edge {
    int to;
    long long weight;
};

struct State {
    long long dist;
    int u;
    
    bool operator>(const State& other) const {
        return dist > other.dist;
    }
};

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, k;
    if (!(cin >> n >> m >> k)) return 0;

    vector<vector<Edge>> adj(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v;
        long long w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    // Keep track of the shortest train route to each city
    vector<long long> min_train(n + 1, INF);
    int closed_trains = 0;

    for (int i = 0; i < k; ++i) {
        int s;
        long long y;
        cin >> s >> y;
        if (min_train[s] != INF) {
            // Already have a train route to city s, close the longer one
            closed_trains++;
            min_train[s] = min(min_train[s], y);
        } else {
            min_train[s] = y;
        }
    }

    vector<long long> dist(n + 1, INF);
    vector<bool> has_train(n + 1, false);
    priority_queue<State, vector<State>, greater<State>> pq;

    dist[1] = 0;
    pq.push({0, 1});

    // Add valid train routes to the priority queue
    for (int i = 2; i <= n; ++i) {
        if (min_train[i] != INF) {
            dist[i] = min_train[i];
            has_train[i] = true;
            pq.push({dist[i], i});
        }
    }

    // Standard Dijkstra
    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        if (d > dist[u]) continue;

        for (const auto& edge : adj[u]) {
            int v = edge.to;
            long long w = edge.weight;

            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                has_train[v] = false; // Replaced by a road path
                pq.push({dist[v], v});
            } else if (dist[u] + w == dist[v] && has_train[v]) {
                // Same distance using a road path, train route can be closed
                has_train[v] = false;
            }
        }
    }

    // Count remaining trains that are necessary
    int used_trains = 0;
    for (int i = 2; i <= n; ++i) {
        if (has_train[i]) {
            used_trains++;
        }
    }

    // Closed trains = redundant initial trains + trains replaced during Dijkstra
    cout << closed_trains + (k - closed_trains - used_trains) << "\n";

    return 0;
}