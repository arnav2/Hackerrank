#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

typedef
struct nodes{
    vector<int> adjacent_node_values; 
    int id;
} Node;

class Graph {
    private: 
        std::vector<Node> nodes;
    public:
        Graph(int n) {
            nodes.resize(n);
            for(int i = 0; i < n ; ++i)
            {
                nodes[i].id = i;
            }
        }
    
        void add_edge(int u, int v) {
            nodes[u].adjacent_node_values.push_back(v);
            nodes[v].adjacent_node_values.push_back(u);
        }
    
        vector<int> shortest_reach(int start) {
            priority_queue <int> tempq;
            vector<int> distance ;
            distance.resize(nodes.size());
            for (auto& val : distance)
            {
                val = std::numeric_limits<int>::max();
            }
            distance[start] = 0;

            if (nodes[start].adjacent_node_values.size() != 0)
            {
                 // get the first node that is not visited 
                tempq.push(nodes[start].id);
                
                while(!tempq.empty()){
                    
                    int s = tempq.top();
                    tempq.pop();
                    Node currNode = nodes[s];
                    
                    for( int i = 0 ; i < currNode.adjacent_node_values.size(); i++)
                    {
                        if ((distance[currNode.id] + 6) < distance[currNode.adjacent_node_values[i]])
                        {
                            // Assume the edge weight is 6 
                            distance[currNode.adjacent_node_values[i]] = distance[currNode.id] + 6;
                            tempq.push(currNode.adjacent_node_values[i]);
                        }
                    }
                }
            }
            // Could use the visited flag here as well to check 
            for (auto& val : distance)
            {
                if (val == std::numeric_limits<int>::max())
                {
                    val = -1;
                }
            }
            return distance;
        }
};

int main() {
    int queries;
    cin >> queries;
        
    for (int t = 0; t < queries; t++) {
      
        int n, m;
        cin >> n;
        // Create a graph of size n where each edge weight is 6: 
        Graph graph(n);
        cin >> m;
        // read and set edges
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            u--, v--;
            // add each edge to the graph
            graph.add_edge(u, v);
        }
        int startId;
        cin >> startId;
        startId--;
        // Find shortest reach from node s
        vector<int> distances = graph.shortest_reach(startId);

        for (int i = 0; i < distances.size(); i++) {
            if (i != startId) {
                cout << distances[i] << " ";
            }
        }
        cout << endl;
    }
    
    return 0;
}

