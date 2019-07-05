#include <bits/stdc++.h>
#include <limits>
using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'shop' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. INTEGER k
 *  3. STRING_ARRAY centers
 *  4. 2D_INTEGER_ARRAY roads
 */

typedef
struct nodes{
    vector<int> adjacent_node_values; 
} Node;

typedef
struct edges{
    vector<int> adjacent_node_values; 
    int weight;
} Edge;

class Graph {
    private: 
        std::vector<Node> nodes;
        std::vector<Edge> edges;
    public:
        Graph(int n , int k) {
            nodes.resize(n);
            edges.resize(k);
        }
    
        void add_edge(int u, int v , int weight) {
            nodes[u].adjacent_node_values.push_back(v);
            nodes[v].adjacent_node_values.push_back(u);
            
            Edge newEdge; 
            newEdge.adjacent_node_values.push_back(u); 
            newEdge.adjacent_node_values.push_back(v);
            newEdge.weight = weight; 
            edges.push_back(newEdge);
        }
    
};


void createAdjointMatrix(int n , vector<vector<int>>& roads , std::vector<std::vector<int> >& resultMatrix )
{
    int inf = std::numeric_limits<int>::max();
    resultMatrix.resize(n);
    for(int i = 0 ; i < n ; ++i)
    {
        resultMatrix[i].resize(n , inf);
    }

    // Bidirectional roads 
    for (int i = 0; i < roads.size() ; ++i)
    {
        resultMatrix[roads[i][0] - 1][roads[i][1] - 1] = roads[i][2];
        resultMatrix[roads[i][1] - 1][roads[i][0] - 1] = roads[i][2];
    }
}

int tsp ( std::vector<std::vector<int> >& adjacencyMatrix ,  std::vector<int>& cost, std::vector<int>& parent , int startingPosition)
{
    for (int i = 0; i < n; ++i)
    {
        if (i != startingPosition && adjacencyMatrix[i][startingPosition] < cost[i])
        {
            cost[i] += adjacencyMatrix[i][startingPosition];
            parent[i] = startingPosition;
            cout << "cost vector is : ";
            for (auto& elem : cost)
            {
                cout << cos
            }

        }
    }

}

int shop(int n, int k, vector<string> centers, vector<vector<int>> roads) {
    Graph graph(n , k);
    std::vector<std::vector<int> > adjacencyMatrix;
    for (auto& line : roads)
    {
        // cout << line[0] << " " << line[1] << " " << line[2] << endl;
        graph.add_edge(line[0] - 1 , line[1] - 1 , line[2]);
    }

    createAdjointMatrix(n , roads , adjacencyMatrix);
    tsp (adjacencyMatrix);
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int m = stoi(first_multiple_input[1]);

    int k = stoi(first_multiple_input[2]);

    vector<string> centers(n);

    for (int i = 0; i < n; i++) {
        string centers_item;
        getline(cin, centers_item);

        centers[i] = centers_item;
    }

    vector<vector<int>> roads(m);

    for (int i = 0; i < m; i++) {
        roads[i].resize(3);

        string roads_row_temp_temp;
        getline(cin, roads_row_temp_temp);

        vector<string> roads_row_temp = split(rtrim(roads_row_temp_temp));

        for (int j = 0; j < 3; j++) {
            int roads_row_item = stoi(roads_row_temp[j]);

            roads[i][j] = roads_row_item;
        }
    }

    int res = shop(n, k, centers, roads);

    fout << res << "\n";

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
