#pragma once
#include "../template/index.hpp"

// [START]
using WeightedGraph = vector<vector<pair<int, ll>>>;
vector<ll> dijkstra(const WeightedGraph& graph, int start) {
    vector<ll> cost(graph.size(), INFL);
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> que;
    cost[start] = 0;
    que.emplace(0, start);
    while (que.size()) {
        auto [c, now] = que.top();
        que.pop();
        if (c > cost[now]) {
            continue;
        }
        for (const auto& [next, weight] : graph[now]) {
            ll new_cost = c + weight;
            if (chmin(cost[next], new_cost)) {
                que.emplace(new_cost, next);
            }
        }
    }
    return cost;
}
// [END]
