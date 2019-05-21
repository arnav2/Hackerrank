#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

int main()
{
    string nmk_temp;
    getline(cin, nmk_temp);

    vector<string> nmk = split_string(nmk_temp);

    int n = stoi(nmk[0]);

    int m = stoi(nmk[1]);

    int k = stoi(nmk[2]);

    for (int n_itr = 0; n_itr < n; n_itr++) {
        string row;
        getline(cin, row);
        // cout << row << endl;
        // Write Your Code Here
    }
    
    for (int k_itr = 0; k_itr < k; k_itr++) {
        string i1J1I2J2_temp;
        getline(cin, i1J1I2J2_temp);

        vector<string> i1J1I2J2 = split_string(i1J1I2J2_temp);

        int i1 = stoi(i1J1I2J2[0]);

        int j1 = stoi(i1J1I2J2[1]);

        int i2 = stoi(i1J1I2J2[2]);

        int j2 = stoi(i1J1I2J2[3]);

        // std::cout << i1 << " " << j1 << " " << i2 << " " << j2 << endl; 
        // Write Your Code Here
    }
    // Write Your Code Here

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
