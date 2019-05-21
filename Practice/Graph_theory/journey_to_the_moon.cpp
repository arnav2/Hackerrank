#include <bits/stdc++.h>
#include<set>

using namespace std;

vector<string> split_string(string);

// Complete the journeyToMoon function below.
long journeyToMoon(int n, vector<vector<int>> astronaut) {
    vector<set <int>> astronauts;         

    for (auto& connection : astronaut)
    {
        int found = -1;
        for (int i = 0; i < astronauts.size()  ; ++ i)
        {

            // if connection 0 found insert 1 or else if 1 found insert 0
            if(astronauts[i].find(connection[0]) != astronauts[i].end() && found == -1)
            {
                found = i;
                astronauts[i].insert(connection[1]);
            }
            else if (astronauts[i].find(connection[1]) != astronauts[i].end() && found == -1)
            {
                found = i;
                astronauts[i].insert(connection[0]);
            }
            else if ( (astronauts[i].find(connection[0]) != astronauts[i].end() || astronauts[i].find(connection[1]) != astronauts[i].end()) && found != -1)
            {
                astronauts[found].insert(astronauts[i].begin() , astronauts[i].end());
                astronauts.erase(astronauts.begin() + i);
            }
        }
        if (found == -1){
            set<int> temp_set;
            temp_set.insert(connection[0]);
            temp_set.insert(connection[1]);        
            astronauts.push_back(temp_set);
        }
    }
    
    int totsum = 0; 
    int sum = 0; 
    
    
    for (int i = 0; i < astronauts.size() - 1 ; ++ i)
    {
        for (int j = i+1; j < astronauts.size()  ; ++ j)
        {
            sum += (astronauts[i].size() * astronauts[j].size());
        }
        totsum += astronauts[i].size();
    }
    totsum += astronauts[astronauts.size() - 1].size();
    
    int total_no_conn = n - totsum;
    
    long long result = 0;

    if (total_no_conn){
        
        if (total_no_conn % 2 == 0)
            result =  sum +  (long long)(total_no_conn / 2) * (total_no_conn - 1)  + total_no_conn * totsum;
        else
            result =  sum + (long long)(total_no_conn) * ((total_no_conn - 1) / 2)  + total_no_conn * totsum;
    }
    else{
        result = sum ;
    }

    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string np_temp;
    getline(cin, np_temp);

    vector<string> np = split_string(np_temp);

    int n = stoi(np[0]);

    int p = stoi(np[1]);

    vector<vector<int>> astronaut(p);
    for (int i = 0; i < p; i++) {
        astronaut[i].resize(2);

        for (int j = 0; j < 2; j++) {
            cin >> astronaut[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    long result = journeyToMoon(n, astronaut);

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
