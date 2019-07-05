#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the almostSorted function below.
void almostSorted(vector<int> arr) 
{
    int endIndex = -1;
    int startIndex = -1;
    int counter = 0;
    
    if (arr.size() == 2)
    {
        if(arr[0] > arr[1])
        {
            cout << "yes" << endl;
            cout << "swap " << 1 << " " << 2 << endl;
        }
        return;
    }

    for (int i = 0 ; i < arr.size() - 1; ++i)
    {

        // Now if it doesn't follow order    
        if(arr[i] > arr[i+1]){
            // set the startIndex regardless
            if( startIndex == -1)
            {
                cout << " startIndex : " << i << endl;
                startIndex = i;
            }
            else if ( i == startIndex + counter + 1)
            {
                cout << "Reverse i : " << i << endl ;
                counter ++;
            }
            else if (endIndex == -1)
            {
                cout << "In endIndex : " <<  i << "with val : " <<   endl;
                endIndex = i; 
            }
            else
            {
                cout << " No" << endl;
                return;
            }
        }
        
    }
    if (endIndex != -1 && counter == 0)
    {
        cout << "yes" << endl;
        cout << "swap "<< startIndex + 1 << " " << endIndex + 1  << endl;
    }
    else if (endIndex == -1 && counter != 0)
    {
        cout << "yes" << endl;
        cout <<  "reverse " << startIndex + 1 << " " << startIndex + counter + 2 << endl;
    }
    else 
    {
        cout << " no " << endl;
    }
}

int main()
{
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split_string(arr_temp_temp);

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    almostSorted(arr);

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
