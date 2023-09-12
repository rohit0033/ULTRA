

#include <iostream>
#include <algorithm>
#include <chrono>
#include <queue>
#include <limits>

#include "../Algorithms"

using namespace std;
using namespace std::chrono;

// Heuristic function for A* search
int heuristic(int current, int target, const Graph& graph) {

return abs(current-target);
}

void AStarSearch(Graph graph, int source, int target) {

priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> pq;

vector<int> dist(graph.numNodes(), INT_MAX);
dist[source] = 0;
pq.push({0, source});

while(!pq.empty()) {
int currentDist = pq.top().first;
int currentNode = pq.top().second;
pq.pop();

if(currentNode == target) 
  break;

for(auto neighbour: graph.graph[currentNode]) {

  int alt = currentDist + graph.edges[currentNode][neighbour.first].weight + heuristic(neighbour.second, target, graph);

  if(alt < dist[neighbour.second]) {
    dist[neighbour.second] = alt;
    pq.push({alt, neighbour.second});
  }
}
}

// Print shortest path
}

int main() {

Graph graph = readGraphFromDIMACS("Florida.gr");

high_resolution_clock::time_point t1 = high_resolution_clock::now();

for(int i=0; i<200; i++) {

int source = rand() % graph.numNodes();
int target = rand() % graph.numNodes();

AStarSearch(graph, source, target);
}

high_resolution_clock::time_point t2 = high_resolution_clock::now();

auto duration = duration_cast<seconds>(t2 - t1).count();

cout << "Total runtime in seconds for 200 random A* searches: " << duration << endl;

return 0;
}

