#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the highestValuePalindrome function below.
string highestValuePalindrome(string s, int n, int k) {
    bool isPalindrome = false;
    std::vector<int> changeIndex;
    int high = n-1; 
    int low = 0;
    // cout << s << endl;
    if (high == low )
    {
        if (k == 1)
        {
            s[low] = '9';
        }
        return s;
    }

    while (high > low)
    {
        if (s[high] != s[low])
            changeIndex.push_back(low);        
        high --; 
        low ++;
    }
    int size = changeIndex.size();
    
    if (size <= k)
    {
        for (auto& index : changeIndex)
        {
            s[index] = max(s[index] , s[ n - 1 - index]);
            s[ n - 1 - index] = max(s[index] , s[ n - 1 - index]);
        }
    }
    else 
    {
        return to_string(-1);
    }
    
    if (size < k)
    {
        int changesLeft = k - size;
        int ptrIndex = 0;
        
        // cout << " changeindex is : " << changesLeft << endl;
        // cout << "s[ptr] " << s[ptrIndex] << endl;

        while (ptrIndex != n && changesLeft > 0)
        {

            if (std::find(changeIndex.begin() , changeIndex.end() , ptrIndex) == changeIndex.end() && changesLeft >= 2 && s[ptrIndex] != '9')
            {
                changesLeft -=2;
                s[ptrIndex] = '9';
                s[n-1-ptrIndex] = '9'; 
            }
            else if (std::find(changeIndex.begin() , changeIndex.end() , ptrIndex) != changeIndex.end() && s[ptrIndex] != '9')
            {
                changesLeft --;
                s[ptrIndex] = '9';
                s[n-1-ptrIndex] = '9';
            }
            else if (std::find(changeIndex.begin() , changeIndex.end() , ptrIndex) == changeIndex.end() && changesLeft == 1 && n % 2 && s[n/2] != '9')
            {
                changesLeft --;
                s[n/2] = '9';
            }
            ptrIndex++;
        }
    }
    // cout << s << endl;
    return s;
}
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nk_temp;
    getline(cin, nk_temp);

    vector<string> nk = split_string(nk_temp);

    int n = stoi(nk[0]);

    int k = stoi(nk[1]);

    string s;
    getline(cin, s);

    string result = highestValuePalindrome(s, n, k);

    fout << result << "\n";
    // cout << result << "\n";

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
