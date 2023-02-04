#include <iostream>
#include <map>
#include <vector>
#include <stack>

using namespace std;

vector<int> topological_sort(map<int, vector<int>> &graph) {
  int num_nodes = graph.size();
  vector<int> indegrees(num_nodes, 0);
  for (auto &p : graph) {
    for (int neighbor : p.second) {
      indegrees[neighbor]++;
    }
  }

  stack<int> stk;
  for (int i = 0; i < num_nodes; i++) {
    if (indegrees[i] == 0) {
      stk.push(i);
    }
  }

  vector<int> sorted;
  while (!stk.empty()) {
    int node = stk.top();
    stk.pop();
    sorted.push_back(node);

    for (int neighbor : graph[node]) {
      indegrees[neighbor]--;
      if (indegrees[neighbor] == 0) {
        stk.push(neighbor);
      }
    }
  }

  return sorted;
}

int main() {
  map<int, vector<int>> graph;
  graph[0] = {1, 2};
  graph[1] = {3};
  graph[2] = {3};
  graph[3] = {};

  vector<int> sorted = topological_sort(graph);

  cout << "Topologically sorted order: ";
  for (int node : sorted) {
    cout << node << " ";
  }
  cout << endl;

  return 0;
}