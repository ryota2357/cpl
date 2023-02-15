#pragma once

#include "../template/index.hpp"

// [START]
vector<int> topologicalSort(const vector<vector<int>>& graph) {
    vector<int> ret;
    const int size = graph.size();
    vector<int> indegree(size);
    for (const vector<int>& v : graph) {
        for (const int& to : v) indegree[to]++;
    }
    queue<int> que;
    for (int i = 0; i < size; i++) {
        if (indegree[i] == 0) que.emplace(i);
    }
    while (que.size()) {
        const int v = que.front();
        que.pop();
        ret.emplace_back(v);
        for (const int& to : graph[v]) {
            indegree[to]--;
            if (indegree[to] == 0) que.emplace(to);
        }
    }
    return ret;
}
// [END]
