#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <vector>

using namespace std;

const int INF = 1e9;

vector<int> dijkstra(int start, map<int, vector<int>> &graph, map<pair<int, int>, int> &weights) {
  int num_nodes = graph.size();
  vector<int> distances(num_nodes, INF);
  distances[start] = 0;

  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
  pq.push({0, start});

  while (!pq.empty()) {
    int node = pq.top().second;
    pq.pop();

    for (int neighbor : graph[node]) {
      int weight = weights[{node, neighbor}];
      if (distances[neighbor] > distances[node] + weight) {
        distances[neighbor] = distances[node] + weight;
        pq.push({distances[neighbor], neighbor});
      }
    }
  }

  return distances;
}

int main() {
  map<int, vector<int>> graph;
  graph[0] = {1, 2};
  graph[1] = {0, 3};
  graph[2] = {0, 3};
  graph[3] = {1, 2};

  map<pair<int, int>, int> weights;
  weights[{0, 1}] = 2;
  weights[{0, 2}] = 3;
  weights[{1, 3}] = 1;
  weights[{2, 3}] = 5;

  vector<int> distances = dijkstra(0, graph, weights);

  for (int i = 0; i < distances.size(); i++) {
    cout << "Shortest distance from node 0 to node " << i << " is " << distances[i] << endl;
  }

  return 0;
}
