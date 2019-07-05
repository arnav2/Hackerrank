// The problem is based on: https://en.wikipedia.org/wiki/Longest_common_subsequence_problem


#include <bits/stdc++.h>
#include <string>
using namespace std;

// Complete the commonChild function below.
int commonChild(string s1, string s2) {
	int n = s1.size() - 1;
	std::vector<std::vector<int>> dp(n+1);
	for (int i = 0; i <= n; ++i)
	{
		dp[i].resize(n+1);
	}
	std::fill(dp[0].begin(), dp[0].end(), 0);
	for (int i = 0 ; i <= n ;++i)
	{
		dp[i][0] = 0;
	}

	for (int i = 1; i <= n ; ++i)
	{
		for (int j = 1; j <=n ; ++j)
		{
			if (s1[i-1] == s2[j-1])
			{
				dp[i][j] = dp[i-1][j-1] + 1;
			}
			else
			{
				dp[i][j] = max(dp[i][j-1] , dp[i-1][j]);
			}
		}
	}

	// for (int i = 0; i <= n ; ++i)
	// {
	// 	for (int j = 0; j <=n ; ++j)
	// 	{
	// 		cout << dp[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }
	return dp[n][n];
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s1;
    getline(cin, s1);

    string s2;
    getline(cin, s2);

    int result = commonChild(s1, s2);

    fout << result << "\n";

    fout.close();

    return 0;
}

