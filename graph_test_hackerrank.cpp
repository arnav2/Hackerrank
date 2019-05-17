#include <bits/stdc++.h>
#include <queue>

using namespace std;

vector<string> split_string(string);


typedef
struct node
{
    int value; 
    bool visited = false;
    std::vector<int> adjacent_node_values;
}Node;

typedef
struct graph
{
    std::vector<Node> nodes;
}Graph;

Graph* ConstructGraph(int n , vector<vector<int>> edges)
{
    Graph* graph = new Graph; 
    graph->nodes.resize(n);
    for(int i = 0; i < n ; ++i)
    {
        (graph->nodes)[i].value = i;
    }
    
    for(int i = 0; i < edges.size() ; ++i)
    {
        (graph->nodes[edges[i][0] - 1].adjacent_node_values).push_back(edges[i][1] - 1);
        (graph->nodes[edges[i][1] - 1].adjacent_node_values).push_back(edges[i][0] - 1); 
    }
    return graph;
}



int BreadthFirstSearch (int startIdx , Graph* graph)
{   
    queue <int> tempq;
    graph->nodes[startIdx].visited = true;
    if (graph->nodes[startIdx].adjacent_node_values.size() != 0)
    {
        int numRoads = 0;
         // get the first node that is not visited 
        tempq.push(graph->nodes[startIdx].value);
        while(!tempq.empty()){
            int s = tempq.front(); 
            tempq.pop();
            Node currNode = graph->nodes[s];
            for( int i = 0 ; i < currNode.adjacent_node_values.size(); i++)
            {
                if (graph->nodes[currNode.adjacent_node_values[i]].visited == false)
                {
                    numRoads ++;
                    graph->nodes[currNode.adjacent_node_values[i]].visited = true;
                    tempq.push(currNode.adjacent_node_values[i]);
                }
            }
        }
        return numRoads;
    }
    return 0;
}

long checkUnvisited(int n , Graph* graph , int c_lib , int c_road)
{   int count_roads = 0;
    int count_library = 0;
    for (int i = 0 ; i < n ; i ++)
    {
        // cout << " check unvisited : " << i << endl;
        if (graph->nodes[i].visited == false)
        {
            int val = BreadthFirstSearch ( i , graph);
            if (val > 0)
            {
                count_roads +=val;

            }
            count_library += 1;
        }
    }
    return ( (long)c_lib * count_library + (long)c_road * count_roads);
    // cout << "num library : " <<  count_library << " num roads : " << count_roads << endl;
}

// Complete the roadsAndLibraries function below.
long roadsAndLibraries(int n, int c_lib, int c_road, vector<vector<int>> roads) {
    // std::cout << " Before graph construct " << std::endl;
    Graph* graph = ConstructGraph( n,roads);
    // std::cout << " After graph construct " << std::endl;
    long cost = 0; 
    if (c_lib < c_road)
    {
        cost = (long)c_lib * n;
    }
    else
    {
        cost = checkUnvisited(n,graph , c_lib , c_road);    
    }
    return cost;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string nmC_libC_road_temp;
        getline(cin, nmC_libC_road_temp);

        vector<string> nmC_libC_road = split_string(nmC_libC_road_temp);

        int n = stoi(nmC_libC_road[0]);

        int m = stoi(nmC_libC_road[1]);

        int c_lib = stoi(nmC_libC_road[2]);

        int c_road = stoi(nmC_libC_road[3]);

        vector<vector<int>> cities(m);
        for (int i = 0; i < m; i++) {
            cities[i].resize(2);

            for (int j = 0; j < 2; j++) {
                cin >> cities[i][j];
            }

            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        long result = roadsAndLibraries(n, c_lib, c_road, cities);

        fout << result << "\n";
    }

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
