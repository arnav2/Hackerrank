#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

// Complete the matrixRotation function below.
void matrixRotation(vector<vector<int>> matrix, int r) {
    int rows = matrix.size(); // this is supposed to be m 
    int cols = matrix[0].size(); // this is supposed to be n
    int numRings = min(rows , cols) / 2;

    std::vector<std::vector<int>> newMatrix(rows);
    for (auto& row : newMatrix)
    {
        row.resize(cols);
    }

    for (int i = 0 ; i < r ; ++i)
    {
        for (int i = 0; i < rows ; ++i)
        {
            for (int j = 0; j < cols ; ++j)
            {
                if ( i < numRings && j < (cols - i - 1) && j >= i)
                {
                    // move right.
                    // cout << " i : " << i << " j : " << j << endl;  
                    newMatrix[i][j + 1] = matrix[i][j];  
                }
                else if (j < numRings && i < (rows - j) && i > j )
                {
                    // move top
                    // cout << " i : " << i << " j : " << j << endl;
                    newMatrix[i - 1][j] = matrix[i][j];
                }
                else if ( j >= numRings && i < (rows - cols + j) && i >= cols - 1 - j)
                {
                //     // move bottom
                    // cout << " i : " << i << " j : " << j << endl;
                    newMatrix[i + 1][j] = matrix[i][j];
                }
                else if ( i > numRings && j <= (cols - rows + i) && j > rows - i - 1)
                {
                    // cout << " i : " << i << " j : " << j << endl;
                    newMatrix[i][j - 1] = matrix[i][j];
                    // move left
                }
            }
        }
    }
    for (int i = 0; i < newMatrix.size(); ++i)
    {
        for (int j = 0 ; j < newMatrix[i].size(); ++j)
        {
            cout << newMatrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    string mnr_temp;
    getline(cin, mnr_temp);

    vector<string> mnr = split(rtrim(mnr_temp));

    int m = stoi(mnr[0]);

    int n = stoi(mnr[1]);

    int r = stoi(mnr[2]);

    vector<vector<int>> matrix(m);

    for (int i = 0; i < m; i++) {
        matrix[i].resize(n);

        string matrix_row_temp_temp;
        getline(cin, matrix_row_temp_temp);

        vector<string> matrix_row_temp = split(rtrim(matrix_row_temp_temp));

        for (int j = 0; j < n; j++) {
            int matrix_row_item = stoi(matrix_row_temp[j]);

            matrix[i][j] = matrix_row_item;
        }
    }

    matrixRotation(matrix, r);

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
