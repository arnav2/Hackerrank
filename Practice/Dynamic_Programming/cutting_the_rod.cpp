// A Naive recursive solution for Rod cutting problem 
#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the getWays function below.
long getRodCost(long n, vector<long> price) {
    vector<long> best_price(n , 0); 
    // index 0 has the price of length 1 and index n - 1 has price of length n 
    best_price[0] = price[0];

    // Find the max between the case of having a cut we have to find the case where we made the cut 
    for (long i = 1; i < n ; ++i )
    {
      long val = 0; 
      for (long j = 0 ; j < i; ++ j)
      {
        val = max(best_price[j] + price[i-j-1] , val);
      }
      best_price[i] = max(val , price[i]);
    }
    return best_price[n-1];
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nm_temp;
    getline(cin, nm_temp);

    int n = stoi(nm_temp);

    string c_temp_temp;
    getline(cin, c_temp_temp);

    vector<string> c_temp = split_string(c_temp_temp);

    vector<long> c(n);

    for (int i = 0; i < n; i++) {
        long c_item = stol(c_temp[i]);

        c[i] = c_item;
    }

    // Print the number of ways of cutting the rods of length 'n' units to give the max result

    long maxCost = getRodCost(n, c);
    cout << maxCost << endl;
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