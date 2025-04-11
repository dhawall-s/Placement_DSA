import heapq

class Solution:
    def dijkstra(self, V, edges, src):
        adj = [[] for _ in range(V)]
        for u, v, w in edges:
            adj[u].append((v, w))
            adj[v].append((u, w))

        dist = [float('inf')] * V
        dist[src] = 0

        min_heap = [(0, src)]

        while min_heap:
            current_dist, u = heapq.heappop(min_heap)
            if current_dist > dist[u]:
                continue
            for v, weight in adj[u]:
                if dist[u] + weight < dist[v]:
                    dist[v] = dist[u] + weight
                    heapq.heappush(min_heap, (dist[v], v))

        return dist
