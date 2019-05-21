#include <bits/stdc++.h>

using namespace std;

// Complete the maxRegion function below.
// typedef
// struct nodes{
//     int id;
//     vector<int> adjacent_node_values; 
//     int val;
// } Node;

// class Graph {
//     private: 
//         std::vector<Node> nodes;
//     public:
//         Graph(int n , int m) {
//             int size = n*m;
//             nodes.resize(size);
//             for(int i = 0; i < size ; ++i)
//             {
//                 nodes[i].id = i;
//             }
//         }
    
//         void add_edge(int u, int v) {
//             nodes[u].adjacent_node_values.push_back(nodes[v].id);
//             nodes[v].adjacent_node_values.push_back(nodes[u].id);
//         }
        
// };

bool checkBound(int row , int col , int n , int m)
{
    return (row >= 0 && row < n && col >= 0 && col < m);
}

int DFS (vector<vector<int>>& grid , vector<vector<bool>>& visited , int row , int col, int n, int m , int retValue) {
    visited[row][col] = true;
    retValue += 1;
    // for (int i = 0; i < n; ++i)
    // {
    //     for (int j = 0; j < m ; ++j)
    //     {
    //         cout << visited[i][j]<< " ";
    //     }
    //     cout << endl;
    // }
    // cout << endl;
    // cout << endl;
    for (int i = -1 ; i < 2; ++i)
    {
        for (int j = -1; j < 2; ++j)
        { 
            if (checkBound( row + i , col + j , n , m) && grid[row+i][col+j] && visited[row+i][col+j] == false)
            {
                retValue = DFS(grid , visited , row+i, col + j , n , m , retValue);
            }
        }
    }

    return retValue;
}

int maxRegion(vector<vector<int>> grid) {
    // Assumptions n != 0
    int n = grid.size(); 
    int m = grid[0].size(); 

    vector<vector<bool>> visited(n);
    for (int i = 0; i < n; ++i)
    {
        visited[i].resize(m);
        for(int j = 0 ; j < m ; ++j)
        {
            visited[i][j] = false;
        }
    }

    
    int maxCount = 0;
    for (int i = 0; i < n ; ++i)
    {
        for (int j = 0; j < n ; ++j)
        {
            if (visited[i][j] == false && grid[i][j])
            {   
                int count = 0;
                visited[i][j] = true;
                count = DFS(grid , visited , i , j , n , m , count);
                if (count > maxCount)
                {
                    maxCount = count;
                }
            }
        }

    }
    return maxCount;
    
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int m;
    cin >> m;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<vector<int>> grid(n);
    for (int i = 0; i < n; i++) {
        grid[i].resize(m);

        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int res = maxRegion(grid);

    fout << res << "\n";

    fout.close();

    return 0;
}
