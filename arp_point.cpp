#include <bits/stdc++.h>
using namespace std;

class Solution {
    void dfs(int u, int parent, vector<int> adj[], vector<bool> &visited, vector<int> &tin, vector<int> &low, int &timer, set<int> &articulationPoints) {
        visited[u] = true;
        tin[u] = low[u] = timer++;
        int children = 0;

        for (int v : adj[u]) {
            if (v == parent) continue;
            if (!visited[v]) {
                dfs(v, u, adj, visited, tin, low, timer, articulationPoints);
                low[u] = min(low[u], low[v]);
                if (low[v] >= tin[u] && parent != -1) {
                    articulationPoints.insert(u);
                }
                children++;
            } else {
                low[u] = min(low[u], tin[v]);
            }
        }

        if (parent == -1 && children > 1) {
            articulationPoints.insert(u);
        }
    }

public:
    vector<int> articulationPoints(int V, vector<vector<int>> &edges) {
        vector<int> adj[V];
        for (auto &edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        vector<bool> visited(V, false);
        vector<int> tin(V, -1), low(V, -1);
        set<int> articulationPoints;
        int timer = 0;

        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                dfs(i, -1, adj, visited, tin, low, timer, articulationPoints);
            }
        }

        if (articulationPoints.empty()) return {-1};
        return vector<int>(articulationPoints.begin(), articulationPoints.end());
    }
};
