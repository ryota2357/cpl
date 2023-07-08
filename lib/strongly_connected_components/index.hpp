#pragma once

#include "../template/index.hpp"

// [START]
struct StronglyConnectedComponents
{
    vector<vector<int>> _result;

    StronglyConnectedComponents(const vector<vector<int>>& graph) : _result(0) {
        auto rev_graph = _create_rev_graph(graph);

        auto return_order = _return_order(graph);
        reverse(return_order.begin(), return_order.end());

        vector<bool> visited(graph.size(), false);
        for (const int current : return_order) {
            if (visited[current]) {
                continue;
            }
            auto component = _get_component(rev_graph, current, visited);
            _result.emplace_back(component);
        }
    }

    vector<vector<int>> get() const {
        return _result;
    }

  private:
    vector<vector<int>> _create_rev_graph(const vector<vector<int>>& graph) const {
        const int size = graph.size();
        vector rev_graph(size, vector<int>());
        for (int i = 0; i < size; ++i) {
            for (const int next : graph[i]) {
                rev_graph[next].emplace_back(i);
            }
        }
        return rev_graph;
    }

    vector<int> _return_order(const vector<vector<int>>& graph) const {
        const int size = graph.size();
        vector<bool> visited(size, false);
        vector<int> order;
        order.reserve(size);
        auto dfs = recursive([&](auto dfs, const int current) -> void {
            visited[current] = true;
            for (const int next : graph[current]) {
                if (visited[next]) {
                    continue;
                }
                dfs(dfs, next);
            }
            order.emplace_back(current);
        });
        for (int i = 0; i < size; ++i) {
            if (visited[i]) {
                continue;
            }
            dfs(i);
        }
        return order;
    }

    vector<int> _get_component(const vector<vector<int>>& rev_graph, int start, vector<bool>& visited) const {
        vector<int> group;
        auto dfs = recursive([&](auto dfs, const int current) -> void {
            visited[current] = true;
            group.emplace_back(current);
            for (const int next : rev_graph[current]) {
                if (visited[next]) {
                    continue;
                }
                dfs(dfs, next);
            }
        });
        dfs(start);
        return group;
    }
};
// [END]
