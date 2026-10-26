#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
private:
    vector<long long> dijkstra(int n, const vector<vector<pair<int, int>>>& adj, int src) {
        vector<long long> dist(n, 1e15);
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> min_heap;

        dist[src] = 0;
        min_heap.push({0, src});

        while (!min_heap.empty()) {
            auto [d, u] = min_heap.top();
            min_heap.pop();

            if (d > dist[u]) continue;

            for (auto& edge : adj[u]) {
                int v = edge.first;
                int w = edge.second;

                if (dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    min_heap.push({dist[v], v});
                }
            }
        }
        return dist;
    }

public:
    long long minimumWeight(int n, vector<vector<int>>& edges, int src1, int src2, int dest) {
        vector<vector<pair<int, int>>> graph(n);
        vector<vector<pair<int, int>>> rev_graph(n);

        for (const auto& e : edges) {
            int u = e[0], v = e[1], w = e[2];
            graph[u].push_back({v, w});
            rev_graph[v].push_back({u, w});
        }

        vector<long long> dist1 = dijkstra(n, graph, src1);
        vector<long long> dist2 = dijkstra(n, graph, src2);
        vector<long long> dist3 = dijkstra(n, rev_graph, dest);

        long long min_total_weight = 1e15;

        for (int i = 0; i < n; i++) {
            if (dist1[i] != 1e15 && dist2[i] != 1e15 && dist3[i] != 1e15) {
                min_total_weight = min(min_total_weight, dist1[i] + dist2[i] + dist3[i]);
            }
        }

        return (min_total_weight >= 1e15) ? -1 : min_total_weight;
    }
};

int main() {
    Solution sol;

    int n = 6;
    vector<vector<int>> edges = {
        {0, 2, 2}, {0, 5, 6}, {1, 0, 3}, {1, 4, 5}, 
        {2, 1, 1}, {2, 3, 3}, {2, 3, 4}, {3, 4, 2}, {4, 5, 1}
    };
    int src1 = 0, src2 = 1, dest = 5;


    long long ans = sol.minimumWeight(n, edges, src1, src2, dest);
    cout << "Minimum total weight of subgraph: " << ans << endl;

    return 0;
}