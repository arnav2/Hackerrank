#include <bits/stdc++.h>

using namespace std;

/* 	input format : 
*	n m 
*	<list of nodes>
*	<m edges that create the connections between the nodes in m lines>
*/
vector<string> split_string(string);

void showpair(std::vector<std::pair<int , int>>& node_parent)
{
	for (int i = 0 ; i < node_parent.size(); ++i)
	{
		cout << node_parent[i].first << " ";
	}
	cout << endl;
	for (int i = 0 ; i < node_parent.size(); ++i)
	{
		cout << node_parent[i].second << " ";
	}
}

int find_parent(std::vector<std::pair<int , int>>& node_parent , int child , int parent)
{
	 
	bool found_parent = false;

	while(found_parent == false)
	{	
		if( node_parent[child].second == -1)
		{
			found_parent = true;
		}
		else
		{
			child = node_parent[child].second;
		}
	}
	return child;
}

bool create_disjoint_set( int n, std::vector<vector<int>>& roads)
{
	std::vector<std::pair<int , int>> node_parent;
	node_parent.resize(n);
	for (int i = 0; i < n ; ++i)
	{
		node_parent[i].first = i;
		node_parent[i].second = -1;
	}

	for(int i = 0; i < roads.size(); ++i)
	{
		int child1 = find_parent(node_parent , roads[i][0] , roads[i][1]);
		int child2 = find_parent(node_parent , roads[i][1] , roads[i][0]);
		if (child1 == child2)
		{
			return false;
		}
		else
		{
			node_parent[child1].second = child2;
		}
	}
	return true;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nk_temp;
    getline(cin, nk_temp);

    vector<string> nk = split_string(nk_temp);

    int n = stoi(nk[0]);

    int m = stoi(nk[1]);

    vector<vector<int>> roads(m);
    for (int i = 0; i < m; i++) {
        roads[i].resize(2);

        for (int j = 0; j < 2; j++) {
            cin >> roads[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    bool result = create_disjoint_set(n , roads);

    if (result == false)
    {
    	cout << " There is a cyle in the graph " << endl;
    }
    else 
    {
    	cout << " There is no cycle in the graph " << endl;
    }
    // fout << result << "\n";

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
