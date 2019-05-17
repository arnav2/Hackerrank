#include <bits/stdc++.h>
#include <queue>
using namespace std;

vector<string> split_string(string);
#include <limits>
// Complete the findShortest function below.

/*
 * For the unweighted graph, <name>:
 *
 * 1. The number of nodes is <name>_nodes.
 * 2. The number of edges is <name>_edges.
 * 3. An edge exists between <name>_from[i] to <name>_to[i].
 *
 */
typedef
struct nodes{
	int colour; 
	vector<int> adjacent_node_values; 
	int id;
	bool visited = false;
} Node;

typedef
struct graph
{
	vector<Node> nodes; 
}Graph;

Graph* constructGraph(int graph_nodes, vector<int> graph_from, vector<int> graph_to, vector<long> ids)
{
	Graph* graph = new Graph; 
    graph->nodes.resize(graph_nodes);
    for(int i = 0; i < graph_nodes ; ++i)
    {
        (graph->nodes)[i].colour = ids[i];
        (graph->nodes)[i].id = i;
    }
    
	for (int i = 0 ; i < graph_from.size(); ++i)
	{
		// cout << graph_from[i] << " " << graph_to[i] << endl;
		(graph->nodes[graph_from[i] - 1].adjacent_node_values).push_back( (graph->nodes[graph_to[i] - 1].id) );
		(graph->nodes[graph_to[i] - 1].adjacent_node_values).push_back( (graph->nodes[graph_from[i] - 1].id) );
	}
	return graph;
}

// Outputs the value of the shortest distance from a node to another node 
int Djikstra(int startIdx , Graph* graph , int numNodes){
	
    
    // Reset the flag for the graph
    for(int i = 0 ; i < numNodes ; ++i )
    {
    	graph->nodes[i].visited = false;
    }

    // temporary variables
    priority_queue <int> tempq;
    vector<int> distance ;
    distance.resize(numNodes);
    for (auto& val : distance)
    {
    	val = std::numeric_limits<int>::max();
    }

    graph->nodes[startIdx].visited = true;
    distance[startIdx] = 0;

    if (graph->nodes[startIdx].adjacent_node_values.size() != 0)
    {
         // get the first node that is not visited 
        tempq.push(graph->nodes[startIdx].id);
        
        while(!tempq.empty()){
            
            int s = tempq.top();
            tempq.pop();
            Node currNode = graph->nodes[s];
            
            for( int i = 0 ; i < currNode.adjacent_node_values.size(); i++)
            {
                if (graph->nodes[currNode.adjacent_node_values[i]].visited == false)
                {
                	
                    distance[currNode.adjacent_node_values[i]] = min( distance[currNode.id] + 1 , distance[currNode.adjacent_node_values[i]]);
                    graph->nodes[currNode.adjacent_node_values[i]].visited = true;
                    if (graph->nodes[currNode.adjacent_node_values[i]].colour == graph->nodes[startIdx].colour)
                    {
                    	return distance[currNode.adjacent_node_values[i]];
                    }
                    tempq.push(currNode.adjacent_node_values[i]);
                }
            }
        }
        return -1;
    }
    return -1;
}

// val has to be solved 
int findShortest(int graph_nodes, vector<int> graph_from, vector<int> graph_to, vector<long> ids, int val) {
    // solve here
    // Construct graph
    // std::cout << " Before graph construct " << std::endl;
    Graph* graph = constructGraph(graph_nodes, graph_from, graph_to,ids);
    // std::cout << " After graph construct " << std::endl;
    int distance = Djikstra(val - 1 , graph , graph_nodes);
    // cout << " distance is : " << distance;
    return distance;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int graph_nodes;
    int graph_edges;

    cin >> graph_nodes >> graph_edges;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<int> graph_from(graph_edges);
    vector<int> graph_to(graph_edges);

    for (int i = 0; i < graph_edges; i++) {
        cin >> graph_from[i] >> graph_to[i];
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    string ids_temp_temp;
    getline(cin, ids_temp_temp);

    vector<string> ids_temp = split_string(ids_temp_temp);

    vector<long> ids(graph_nodes);

    for (int i = 0; i < graph_nodes; i++) {
        long ids_item = stol(ids_temp[i]);

        ids[i] = ids_item;
    }

    int val;
    cin >> val;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int ans = findShortest(graph_nodes, graph_from, graph_to, ids, val);

    fout << ans << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
