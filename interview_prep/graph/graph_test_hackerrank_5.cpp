#include <bits/stdc++.h>

using namespace std;


vector<string> split_string(string);


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

int minTime(int g_nodes, vector<vector<int>>& roads , vector<int>& machines){
    
    // Sorting
    std::sort(roads.begin(), roads.end() , [](std::vector<int> a , std::vector<int> b){ return a[2] >= b[2];} );
    
    // loop through all the edges 
    std::vector<int> node_parent(g_nodes, -1);
    int sum_weight = 0;
    for (int i = 0; i < roads.size(); ++i)
    {
        int child1 = find_parent(node_parent , roads[i][0] , roads[i][1]);
        int child2 = find_parent(node_parent , roads[i][1] , roads[i][0]);

        auto it1 = std::find(machines.begin(), machines.end(), child1);
        auto it2 = std::find(machines.begin(), machines.end(), child2);
        if (it1 == machines.end() || it2 == machines.end())
        {
            if (it1 != machines.end())
            {
                node_parent[child2] = child1;
            }
            else
            {
                node_parent[child1] = child2;
            }
        }
        else
        {
            sum_weight += roads[i][2];
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
    cout << "Beginning main function " << "\n";
    ofstream fout(getenv("OUTPUT_PATH"));

    string nk_temp;
    getline(cin, nk_temp);

    vector<string> nk = split_string(nk_temp);

    int n = stoi(nk[0]);

    int k = stoi(nk[1]);

    vector<vector<int>> roads(n - 1);
    for (int i = 0; i < n - 1; i++) {
        roads[i].resize(3);

        for (int j = 0; j < 3; j++) {
            cin >> roads[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    vector<int> machines(k);

    for (int i = 0; i < k; i++) {
        int machines_item;
        cin >> machines_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        machines[i] = machines_item;
    }
    cout << " Total n is : " << n << endl;
    for( auto& val : roads)
    {
        cout << val[0] << " " << val[1] << " " << val[2] << endl;
    } 

    cout << "machines : " << endl;
    for( auto& val : machines)
    {
        cout << val << " ";
    } 
    cout << endl;

    int result = minTime(n , roads, machines);
    fout << result << "\n";

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
