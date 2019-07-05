#include <bits/stdc++.h>

using namespace std;

// Complete the formingMagicSquare function below
// find all 8 magic squares and then use that to find the min cost 

int formingMagicSquare(vector<vector<int>> s) {
    std::vector<int> sum(8); 
    

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    vector<vector<int>> s(3);
    for (int i = 0; i < 3; i++) {
        s[i].resize(3);


        for (int j = 0; j < 3; j++) {
            cin >> s[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = formingMagicSquare(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
