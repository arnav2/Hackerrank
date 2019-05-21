#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'kruskals' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts WEIGHTED_INTEGER_GRAPH g as parameter.
 */

/*
 * For the weighted graph, <name>:
 *
 * 1. The number of nodes is <name>_nodes.
 * 2. The number of edges is <name>_edges.
 * 3. An edge exists between <name>_from[i] and <name>_to[i]. The weight of the edge is <name>_weight[i].
 *
 */
int find_parent(std::vector<int>& node_parent , int child , int parent)
{
     
    bool found_parent = false;

    while(found_parent == false)
    {   
        if( node_parent[child] == -1)
        {
            found_parent = true;
        }
        else
        {
            child = node_parent[child];
        }
    }
    return child;
}

int kruskals(int g_nodes, vector<int> g_from, vector<int> g_to, vector<int> g_weight){
    
    // Sorting 
    std::vector<std::pair<int, int>> edge_from;
    edge_from.reserve(g_from.size());
    std::transform(g_from.begin(), g_from.end(), g_weight.begin(), std::back_inserter(edge_from),
                [](int a, int b) { return std::make_pair(a, b); });
    std::sort(edge_from.begin(), edge_from.end() , [](std::pair<int , int>  a , std::pair<int , int> b){ return a.second <= b.second;} );
    
    std::vector<std::pair<int, int>> edge_to;
    edge_to.reserve(g_to.size());
    std::transform(g_to.begin(), g_to.end(), g_weight.begin(), std::back_inserter(edge_to),
                [](int a, int b) { return std::make_pair(a, b); });

    std::sort(edge_to.begin(), edge_to.end() , [](std::pair<int , int>  a , std::pair<int , int> b){ return a.second <= b.second;} );
    
    // loop through all the edges 
    std::vector<int> node_parent(g_nodes, -1);
    int sum_weight = 0; 
    for (int i = 0; i < edge_from.size(); ++i)
    {
        int child1 = find_parent(node_parent , edge_from[i].first , edge_to[i].first);
        int child2 = find_parent(node_parent , edge_to[i].first , edge_from[i].first);
        if (child1 != child2)
        {
            node_parent[child1] = child2;
            sum_weight += edge_to[i].second;
        }
    }

    return sum_weight;
    // add the lowest weight edge and keep adding lowest weight until all nodes are occupied
    // ensure that both the node ends are already not visited.
    // make a pair of {from , to } and pair it with weight and then sort it based on weight
    // finally sort the total value
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string g_nodes_edges_temp;
    getline(cin, g_nodes_edges_temp);

    vector<string> g_nodes_edges = split(rtrim(g_nodes_edges_temp));

    int g_nodes = stoi(g_nodes_edges[0]);
    int g_edges = stoi(g_nodes_edges[1]);

    vector<int> g_from(g_edges);
    vector<int> g_to(g_edges);
    vector<int> g_weight(g_edges);

    for (int i = 0; i < g_edges; i++) {
        string g_from_to_weight_temp;
        getline(cin, g_from_to_weight_temp);

        vector<string> g_from_to_weight = split(rtrim(g_from_to_weight_temp));

        int g_from_temp = stoi(g_from_to_weight[0]);
        int g_to_temp = stoi(g_from_to_weight[1]);
        int g_weight_temp = stoi(g_from_to_weight[2]);

        g_from[i] = g_from_temp - 1;
        g_to[i] = g_to_temp - 1;
        g_weight[i] = g_weight_temp;
    }

    int res = kruskals(g_nodes, g_from, g_to, g_weight);
    fout << res << endl;
    // Write your code here. 
    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
