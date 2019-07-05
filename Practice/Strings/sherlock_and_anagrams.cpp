//***CODE I took from Kartikay Goyle. Thanks **/// 

// First go from 
/*
*def sherlockAndAnagrams(s):
    substrings = []
    count = 0

    for i in range(len(s)+1):
        for j in range(i+1, len(s)+1):
            substrings.append(s[i:j])
            
    substrings_sorted = []
    for substring in substrings:
        substrings_sorted.append(''.join(sorted(substring)))

    for substring in substrings:
        substrings_sorted.remove(''.join(sorted(substring)))
        ang_substring = ''.join(sorted(substring))
        count+=substrings_sorted.count(ang_substring)
    return count
*
*
*
*/

#include <bits/stdc++.h>

using namespace std;

// Complete the sherlockAndAnagrams function below.
int sherlockAndAnagrams(string s) {
    // start from the place you find the first repetitive letter and go till the last repetetive letter. 
    // take a string. Reverse it and then try to find that in the string. 
    // If found then +1 else don't

    std::vector<string> substrings;

    for (int i = 1 ; i <= s.length(); ++i)
    {
        for(int j = 0; j < i ; ++j)
        {
            substrings.push_back(s.substr(j,i-j));
        }
    }
    for (auto& val : substrings)
    {
        cout << val << endl;
    }
    std::unordered_map<string, int> sorted_substrings;
    // std::vector<string> sorted_substrings_vec;
    for (int i = 0; i < substrings.size(); ++i)
    {
        string sorted_substring =  substrings[i];
        std::sort(sorted_substring.begin(), sorted_substring.end());
        if ( sorted_substrings.find(sorted_substring) == sorted_substrings.end() ) 
        {
            sorted_substrings[sorted_substring] = 1;
        }
        else
        {
            sorted_substrings[sorted_substring]++;
        }
    }

    int sum = 0; 
    for(auto& val : sorted_substrings)
    {
            sum += (val.second * (val.second - 1) / 2 ) ;
    }
    return sum;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s;
        getline(cin, s);

        int result = sherlockAndAnagrams(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
