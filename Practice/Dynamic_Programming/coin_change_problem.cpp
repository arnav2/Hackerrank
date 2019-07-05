#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the getWays function below.
long getWays(int n, vector<int> c) {

    std::sort(c.begin() , c.end()); // mlog(m)
    int m = c.size();
    std::vector<vector<long>> numWays(m);

    for (int i = 0 ; i < m; ++i)
    {
        numWays[i].resize(n+1 , (long)0);
    }

    // numWays is now (m , n + 1 ) sized

    for (int i = 0; i < m ; ++i)
    {
        numWays[i][0] = 1;
    }

    for (int j = 0; j < m; ++j)
    {
        for (int i = 1; i <= n ; ++i)
        {
            if (i < c[j])
            {
                numWays[j][i] = (j > 0) ? numWays[j-1][i] : 0;
            }
            else{
                numWays[j][i] = (j > 0) ? numWays[j-1][i] + numWays[j][i - c[j]] : numWays[j][i - c[j]];
            }
        }       
    }
    // for (int j = 0; j < m; ++j)
    // {
    //     for (int i = 0; i <= n ; ++i)
    //     {
    //         cout << numWays[j][i] << " ";     
    //     }
    //     cout << endl;
    // }
    return numWays[m-1][n];
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nm_temp;
    getline(cin, nm_temp);

    vector<string> nm = split_string(nm_temp);

    int n = stoi(nm[0]);

    int m = stoi(nm[1]);

    string c_temp_temp;
    getline(cin, c_temp_temp);

    vector<string> c_temp = split_string(c_temp_temp);

    vector<int> c(m);

    for (int i = 0; i < m; i++) {
        int c_item = stol(c_temp[i]);

        c[i] = c_item;
    }

    // Print the number of ways of making change for 'n' units using coins having the values given by 'c'

    long ways = getWays(n, c);
    fout << ways << endl;
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
