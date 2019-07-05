#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the climbingLeaderboard function below.
typedef 
struct leaderboard
{
    int score; 
    int rank; 
} leaderboard;

int binarySearch(int startIndex , int endIndex , vector<int>& scores, int num)
{   
    // cout << " startIndex : " << startIndex << " endIndex : " << endIndex << " with value : " << num << endl;
    int middleIndex = (endIndex + startIndex) / 2;
    if (endIndex <= startIndex)
    {   
        if (num < scores[startIndex])
            return (startIndex);
        else if (num > scores[startIndex])
            return (startIndex - 1);
        else
            return startIndex;
    }

    if (startIndex < endIndex )
    {
        if (scores[middleIndex] < num)
        {
            return binarySearch(startIndex , middleIndex - 1 , scores , num); 
        }
        else{
            return binarySearch( middleIndex + 1, endIndex, scores , num);
        }
    }
    return -1;
}

vector<int> climbingLeaderboard(vector<int> scores, vector<int> alice) {
    
    std::vector<leaderboard> v(scores.size());
    std::vector<int> resultScores(alice.size());
    int rank = 1;
    v[0].score = scores[0];
    v[0].rank = rank;
    // cout << "score : " << v[0].score << " ";
    // cout << "rank : " << v[0].rank << endl;
    for (int i = 1; i < scores.size(); ++i)
    {
         
        v[i].score = scores[i];
        if (v[i].score < v[i-1].score)
        {
            rank ++;
        }
        v[i].rank = rank;
        // cout << "score : " << v[i].score << " ";
        // cout << "rank : " << v[i].rank << endl;
    }
    for (int i = 0; i < alice.size(); ++i)
    {
        int position = binarySearch(0, scores.size() - 1 , scores , alice[i]);
        if (position >= (int)scores.size())
            resultScores[i] = v[scores.size() - 1].rank + 1;
        else if (position < 0)
            resultScores[i] = 1;
        else if (alice[i] < v[position].score)
            resultScores[i] = v[position].rank + 1;
        else
            resultScores[i] = v[position].rank;
    }
    return resultScores;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int scores_count;
    cin >> scores_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string scores_temp_temp;
    getline(cin, scores_temp_temp);

    vector<string> scores_temp = split_string(scores_temp_temp);

    vector<int> scores(scores_count);

    for (int i = 0; i < scores_count; i++) {
        int scores_item = stoi(scores_temp[i]);

        scores[i] = scores_item;
    }

    int alice_count;
    cin >> alice_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string alice_temp_temp;
    getline(cin, alice_temp_temp);

    vector<string> alice_temp = split_string(alice_temp_temp);

    vector<int> alice(alice_count);

    for (int i = 0; i < alice_count; i++) {
        int alice_item = stoi(alice_temp[i]);

        alice[i] = alice_item;
    }

    vector<int> result = climbingLeaderboard(scores, alice);

    for (int i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

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
