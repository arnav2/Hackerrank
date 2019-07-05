#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the queensAttack function below.
bool checkBound (int val , int n)
{
    if (val >= 0 && val < n)
        return true; 
    else 
        return false;
}


int recursivefunc(int n, int k, int r_q, int c_q, int dir_y , int dir_x ,  vector<pair<int , int>>& obstacle_pair) { 
    // cout << " row : " << r_q << " col : " << c_q << " dir_y : " << dir_y << " dir_x: " << dir_x << endl;
    if (    checkBound(r_q + dir_y , n) && checkBound(c_q + dir_x , n)  &&
            std::find(obstacle_pair.begin(), obstacle_pair.end(), make_pair(r_q + dir_y , c_q + dir_x)) 
            == obstacle_pair.end()){
        // cout << "Hello " << endl;
        return (1 + recursivefunc( n , k , r_q + dir_y , c_q + dir_x , dir_y , dir_x , obstacle_pair));
    }
    // cout << "End of recursivefunc " << endl;
    return 0;
}

int queensAttack(int n, int k, int r_q, int c_q, vector<pair<int , int>>& obstacle_pair) {
    vector<int> dir = {-1 , 0 , 1};
    
    int result = 0;
    for (int i = 0 ; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            // if it is not the same element and it is in the bound and there are no obstacles then increment 1
            if ( !(dir[i]==0 && dir[j]==0) && checkBound(r_q + dir[i] , n) && checkBound(c_q + dir[j] , n)  &&
                std::find(obstacle_pair.begin(), obstacle_pair.end(), make_pair(r_q + dir[i] , c_q + dir[j])) 
                == obstacle_pair.end()){
                result += (1 + recursivefunc(n, k, r_q + dir[i], c_q + dir[j], dir[i] , dir[j] ,obstacle_pair));             
                cout << result << endl;
            }
        }
    }
     return result; 
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nk_temp;
    getline(cin, nk_temp);

    vector<string> nk = split_string(nk_temp);

    int n = stoi(nk[0]);

    int k = stoi(nk[1]);

    string r_qC_q_temp;
    getline(cin, r_qC_q_temp);

    vector<string> r_qC_q = split_string(r_qC_q_temp);

    int r_q = stoi(r_qC_q[0]) - 1;

    int c_q = stoi(r_qC_q[1]) - 1;

    vector<pair<int , int>> obstacles(k);
    for (int i = 0; i < k; i++) {
        cin >> obstacles[i].first;
        cin >> obstacles[i].second; 
        obstacles[i].first  --;
        obstacles[i].second --;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = queensAttack(n, k, r_q, c_q, obstacles);

    fout << result << "\n";
    cout << result << "\n";
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
