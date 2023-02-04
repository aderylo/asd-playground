#include <iostream>
#include <map>
#include <vector>
#include <stack>

using namespace std;

void DFS(int node, map<int, vector<int>> &graph, vector<bool> &visited) {
  visited[node] = true;
  cout << node << " ";

  for (int neighbor : graph[node]) {
    if (!visited[neighbor]) {
      DFS(neighbor, graph, visited);
    }
  }
}

int main() {
  map<int, vector<int>> graph;
  graph[0] = {1, 2};
  graph[1] = {0, 3};
  graph[2] = {0, 3};
  graph[3] = {1, 2};

  int num_nodes = graph.size();
  vector<bool> visited(num_nodes, false);

  for (int node = 0; node < num_nodes; node++) {
    if (!visited[node]) {
      DFS(node, graph, visited);
    }
  }

  return 0;
}
