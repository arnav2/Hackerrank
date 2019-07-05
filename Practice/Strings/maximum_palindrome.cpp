#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'initialize' function below.
 *
 * The function accepts STRING s as parameter.
 */

// void initialize(string s) {

// }

/*
 * Complete the 'answerQuery' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER l
 *  2. INTEGER r
 */

int factorial(int n) 
{ 
    // single line to find factorial 
    return (n==1 || n==0) ? 1: n * factorial(n - 1);  
} 


int answerQuery(string s , int l, int r) {
    // Return the answer for this query modulo 1000000007.
    unordered_map<char, int> umap;  
    
    for(int i = l-1; i < r ; ++i)
    {
        if (umap.find(s[i]) == umap.end())
        {
            umap[s[i]] = 1;
        }
        else
        {
            umap[s[i]] += 1; 
        }
    }
    int big_odd_val = 0; 
    int count_big_odd_val = 1;
    int total_even = 0;
    int max_length = 0;
    long long prod = 1; 
    for (auto& elem : umap)
    {
        if (elem.second % 2)
        {
            if (elem.second > big_odd_val)
            {
                big_odd_val = elem.second;
                count_big_odd_val = 1;
            }
            else if (elem.second == big_odd_val)
            {
                count_big_odd_val ++; 
            }
        }
        else 
        {
            total_even += elem.second / 2;
            prod*= factorial(elem.second / 2);
        }
    }
    // odd has to be handled seperately like multinomial theorum.
    if (total_even == 0)
    {
        return umap.size();
    } 
    int total = total_even + (big_odd_val - 1) / 2;
    prod*= factorial((big_odd_val - 1) / 2);
    int result = (long long)factorial(total_even) / prod;
    result*= count_big_odd_val;
    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    // initialize(s);

    string q_temp;
    getline(cin, q_temp);

    int q = stoi(ltrim(rtrim(q_temp)));

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string first_multiple_input_temp;
        getline(cin, first_multiple_input_temp);

        vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

        int l = stoi(first_multiple_input[0]);

        int r = stoi(first_multiple_input[1]);

        int result = answerQuery(s , l, r);
        // cout << result << endl;
        fout << result << "\n";
    }

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
