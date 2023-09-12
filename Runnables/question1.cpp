#include <iostream>
#include <chrono>


#include "../Algorithms/Dijkstra/Dijkstra.h"

using namespace std;
using namespace std::chrono;

int main() {
    // Implement the ReadGraph class to read the graph from "Florida.gr"
    ReadGraph rg("Florida.gr");
    Graph g = rg.getGraph();

    high_resolution_clock::time_point t1 = high_resolution_clock::now();

    for (int i = 0; i < 200; i++) {
        int source = rand() % g.numNodes();
        int target = rand() % g.numNodes();
        
        // Implement the Dijkstra function to perform Dijkstra's algorithm which is not  working 
        // Dijkstra(g, source, target);
    }

    high_resolution_clock::time_point t2 = high_resolution_clock::now();

    auto duration = duration_cast<seconds>(t2 - t1).count();

    cout << "Total runtime in seconds for 200 random Dijkstra: " << duration << endl;

    return 0;
}
