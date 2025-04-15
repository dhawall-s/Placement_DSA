#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        vector<int> dist(V, 1e8);
        dist[src] = 0;

        for (int i = 0; i < V - 1; ++i) {
            for (auto& edge : edges) {
                int u = edge[0];
                int v = edge[1];
                int w = edge[2];
                if (dist[u] != 1e8 && dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                }
            }
        }

        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            if (dist[u] != 1e8 && dist[u] + w < dist[v]) {
                return {-1};
            }
        }

        return dist;
    }
};

int main() {
    int V, E;
    cin >> V >> E;

    vector<vector<int>> edges;
    for (int i = 0; i < E; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
    }

    int src;
    cin >> src;

    Solution obj;
    vector<int> result = obj.bellmanFord(V, edges, src);

    for (int i = 0; i < result.size(); ++i) {
        cout << result[i];
        if (i != result.size() - 1) cout << " ";
    }
    cout << endl;

    return 0;
}
